#include <iostream>
#include "expressions.h"

int main()
{

    int variable = 5;
    //x + (x - 2) * (x - 3)
    typedef EXPRESSION<ADD<VARIABLE,MULTIPLY<SUBTRACT<VARIABLE,LITERALINTEGER<2>>,SUBTRACT<VARIABLE,LITERALINTEGER<3>>>>> expr1;
    //5/x
    typedef EXPRESSION<DIVIDE<LITERALINTEGER<5>,VARIABLE>> expr2;
    try{
        printf("Value of the expression with x=%d is %d\n",variable,expr1::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }
    return 0;
}
