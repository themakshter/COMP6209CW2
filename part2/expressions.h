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


//In all our expression relation classes, we will keep track of upper and lower bound values


// Literal integer such as 1 or 2
template <int i>
class LITERALINTEGER{
public:
    static int eval(int x){
        return i;
    }
    enum {
		lowerBound = i,
		upperBound = i
	};

};

template<int lower, int upper>
class BOUNDS{
public:


    enum {
		lowerBound = lower,
		upperBound = upper
	};

};

// Variable, such as x with a bounds class
template<class b>
class VARIABLE{
public:
    static int eval(int x){
        if(x < b::lowerBound || x > b::upperBound){
            throw outOfBoundsException();
        }else{
            return x;
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
    static int eval(int x){
        printf("Lower bound of the equation is: %d\n", a::lowerBound);
		printf("Upper bound of the equation is: %d\n", a::upperBound);
        return a::eval(x);
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
        static int eval(int x){
            return a::eval(x) + b::eval(x);
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
    static int eval(int x){
        return a::eval(x) - b::eval(x);
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
    static int eval(int x){
        return a::eval(x) * b::eval(x);
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
    static int eval(int x){
        //throw exception if dividing by zero
        if(b::eval(x) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(x) / b::eval(x);
        }
    }

    // need to try out all possible combinations and find min and max from them
    enum {
        lowerBound = MINIMUM<MINIMUM<a::lowerBound / b::lowerBound,a::lowerBound / b::upperBound>::apply,MINIMUM<a::upperBound / b::lowerBound,a::upperBound / b::upperBound>::apply>::apply,
        upperBound = MAXIMUM<MAXIMUM<a::lowerBound / b::lowerBound,a::lowerBound / b::upperBound>::apply,MAXIMUM<a::upperBound / b::lowerBound,a::upperBound / b::upperBound>::apply>::apply
    };



};

#endif // EXPRESSIONS_H_INCLUDED
