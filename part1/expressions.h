#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <stdio.h>

using namespace std;

class divideByZeroException:
    public exception{
    virtual const char* what() const throw()
    {
        return "Error! Cannot divide by zero!";
    }
};


template <int i>
class Value{
public:
    static int eval(int x){
        return i;
    }
};

class Variable{
public:
    static int eval(int x){
        return x;
    }
};

template<class a>
class Expression{
    static int eval(int x){
        return a::eval(x);
    }
};

template<class a,class b>
class Add{
public:
        static int eval(int x){
            return a::eval(x) + b::eval(x);
        }
};

template<class a, class b>
class Subtract{
public:
    static int eval(int x){
        return a::eval(x) - b::eval(x);
    }
};

template<class a,class b>
class Multiply{
public:
    static int eval(int x){
        return a::eval(x) * b::eval(x);
    }
};

template<class a,class b>
class Divide{
public:
    static int eval(int x){
        if(b::eval(x) == 0){
            throw divideByZeroException();
        }else{
            return a::eval(x) / b::eval(x);
        }
    }
};



#endif // EXPRESSIONS_H_INCLUDED
