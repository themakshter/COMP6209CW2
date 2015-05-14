#include <iostream>
#include "expressions.h"

int main()
{
    int variable = 6;
    const int lowerBound = 0;
    const int upperBound = 5;
    //(x + 3) * (x + 5) with bounds (0,5)
    typedef EXPRESSION<MULTIPLY<ADD<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<3>>,ADD<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<5>>>> expr;
    printf("Value of the expression with x=%d is: ",variable);
    try{
        printf("%d\n",expr::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }


}
