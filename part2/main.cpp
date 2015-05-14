#include <iostream>
#include "expressions.h"

int main()
{
    int variable = 6;
    //(x + 3) * (x + 5)
    typedef EXPRESSION< MULTIPLY< ADD< VARIABLE< BOUNDS<0,5> >,LITERALINTEGER<3>>,ADD<VARIABLE< BOUNDS<0,5>> ,LITERALINTEGER<5>> > > expr;

    try{
        printf("Value of the expression with x=%d is %d\n",variable,expr::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }


}
