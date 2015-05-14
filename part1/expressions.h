#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <stdio.h>

using namespace std;

//Exception for division by zero
class divideByZeroException:
    public exception{
    virtual const char* what() const throw()
    {
        return "Error! Cannot divide by zero!";
    }
};


// Literal integer such as 1 or 2
template <int i>
class LITERALINTEGER{
public:
    static inline int eval(int x) {
        return i;
    }
};

// Variable, such as x
class VARIABLE{
public:
    static inline int eval(int x) {
        return x;
    }
};

// A complete expression such as x + (x+2) * (x+3)
template<class a>
class EXPRESSION{
public:
    static inline int eval(int x) {
        return a::eval(x);
    }
};

// Addition such as 1 + 2
template<class a,class b>
class ADD{
public:
        static inline int eval(int x) {
            return a::eval(x) + b::eval(x);
        }
};

// Subtraction such as 2 - 1
template<class a, class b>
class SUBTRACT{
public:
    static inline int eval(int x) {
        return a::eval(x) - b::eval(x);
    }
};

// Multiplication such as 3 * 5
template<class a,class b>
class MULTIPLY{
public:
    static inline int eval(int x) {
        return a::eval(x) * b::eval(x);
    }
};

// Division such as 99/9
template<class a,class b>
class DIVIDE{
public:
    static inline int eval(int x) {
        //throw exception if dividing by zero
        if(b::eval(x) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(x) / b::eval(x);
        }
    }
};

#endif // EXPRESSIONS_H_INCLUDED
