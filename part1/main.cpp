#include <iostream>
#include "expressions.h"

int main()
{
    //x + (x - 2) * (x - 3)
    typedef Expression<Add<Variable,Multiply<Subtract<Variable,Value<2>>,Subtract<Variable,Value<3>>>>> exp
    try{
        printf("Value of the expression with x=5 is %d\n",exp::eval(5));
    }catch(exception &e){
        cout << e.what() << endl
    }
    return 0;
}
