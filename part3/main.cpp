#include <iostream>
#include <limits>
#include "expressions.h"

int main()
{
    //values
    int variable = 4;
    const int lowerBound = 0;
    const int upperBound = 5;

    //(x + 3) * (x + 5) with bounds (0,5)
    typedef EXPRESSION<MULTIPLY<ADD<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<3>>,ADD<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<5>>>> expr;


    try{
        printf("Value of the expression with x=%d is: %d\n",variable,expr::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }


}
