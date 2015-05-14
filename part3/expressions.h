#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <stdio.h>

using namespace std;

// Exception for out of range variable values
class outOfBoundsException:
    public exception{
        virtual const char* what() const throw(){
            return "Error! The variable value is outside of the bounds set!";
        }
    };

//Exception for division by zero
class divideByZeroException:
    public exception{
        virtual const char* what() const throw(){
            return "Error! Cannot divide by zero!";
        }
    };

//Template for finding smaller value out of two
template<int a,int b>
struct MINIMUM
{
    enum {
        apply =((a < b) ? a: b)
    };

};

//Template for finding larger value out of two
template<int a,int b>
struct MAXIMUM
{
    enum {
        apply = ((a > b) ? a : b)
    };
};

// Bounds class with upper and lower bounds
template<int lower, int upper>
class BOUNDS{
public:


    enum {
		lowerBound = lower,
		upperBound = upper
	};

};

//In all our expression relation classes, we will keep track of upper and lower bound values
// Literal integer such as 1 or 2
template <int i>
class LITERALINTEGER{
public:
    static inline int eval(int values[]) {
        return i;
    }
    enum {
		lowerBound = i,
		upperBound = i
	};

};

//index to keep track of the array
static int index;

// Variable, such as x with a bounds class
template<class b>
class VARIABLE{
public:
    static inline int eval(int values[]) {
        if(values[index] < b::lowerBound || values[index] > b::upperBound){
            throw outOfBoundsException();
        }else{
            //increment index but store it in temp value and use that for returning current value;
            int temp = index;
            index++;

            return values[temp];
        }
    }

    enum {
		lowerBound = b::lowerBound,
		upperBound = b::upperBound
	};
};

// A complete expression such as x + (x+2) * (x+3)
template<class a>
class EXPRESSION{
public:
    static inline int eval(int values[]) {
        index = 0;
        return a::eval(values);
    }

    enum {
		lowerBound = a::lowerBound,
		upperBound = a::upperBound
	};

};

// Addition such as 1 + 2
template<class a,class b>
class ADD{
public:
        static inline int eval(int values[]) {
            return a::eval(values) + b::eval(values);
        }

        enum {
            lowerBound = a::lowerBound + b::lowerBound,
            upperBound = a::upperBound + b::upperBound
        };

};

// Subtraction such as 2 - 1
template<class a, class b>
class SUBTRACT{
public:
    static inline int eval(int values[]) {
        return a::eval(values) - b::eval(values);
    }

     enum {
            lowerBound = a::lowerBound - b::lowerBound,
            upperBound = a::upperBound - b::upperBound
    };

};

// Multiplication such as 3 * 5
template<class a,class b>
class MULTIPLY{
public:
    static inline int eval(int values[]) {
        return a::eval(values) * b::eval(values);
    }

    //need to try all the combos and get the minimum possible values for them
    enum {
        lowerBound = MINIMUM<MINIMUM<a::lowerBound * b::lowerBound,a::lowerBound * b::upperBound>::apply,MINIMUM<a::upperBound * b::lowerBound,a::upperBound * b::upperBound>::apply>::apply,
        upperBound = MAXIMUM<MAXIMUM<a::lowerBound * b::lowerBound,a::lowerBound * b::upperBound>::apply,MAXIMUM<a::upperBound * b::lowerBound,a::upperBound * b::upperBound>::apply>::apply
    };


};

// Division such as 99/9
template<class a,class b>
class DIVIDE{
public:
    static inline int eval(int values[]) {
        //throw exception if dividing by zero
        if(b::eval(values) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(values) / b::eval(values);
        }
    }

    // need to try out all possible combinations and find min and max from them
    enum {
        lowerBound = MINIMUM<MINIMUM<a::lowerBound / b::lowerBound,a::lowerBound / b::upperBound>::apply,MINIMUM<a::upperBound / b::lowerBound,a::upperBound / b::upperBound>::apply>::apply,
        upperBound = MAXIMUM<MAXIMUM<a::lowerBound / b::lowerBound,a::lowerBound / b::upperBound>::apply,MAXIMUM<a::upperBound / b::lowerBound,a::upperBound / b::upperBound>::apply>::apply
    };



};

#endif // EXPRESSIONS_H_INCLUDED
