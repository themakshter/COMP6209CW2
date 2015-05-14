#include <iostream>
#include "expressions.h"

int main()
{

    int variable = 5;
    //x + (x - 2) * (x - 3)
    typedef EXPRESSION<ADD<VARIABLE,MULTIPLY<SUBTRACT<VARIABLE,LITERALINTEGER<2>>,SUBTRACT<VARIABLE,LITERALINTEGER<3>>>>> expr1;
    printf("Value of the expression with x=%d is: ",variable);
    try{
    printf("%d",expr1::eval(variable));

    }catch(exception &e){
        cout << e.what() << endl;
    }
    return 0;
}
