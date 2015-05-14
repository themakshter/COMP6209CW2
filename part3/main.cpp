#include <iostream>
#include <limits>
#include "expressions.h"

int main()
{
    // x + (y - 2) * (z - 3), x bounds are (0,4), y bounds are (0,6), z bounds are (0,3)
    typedef EXPRESSION<ADD<VARIABLE<BOUNDS<0,4>>,MULTIPLY<SUBTRACT<VARIABLE<BOUNDS<0,6>>,LITERALINTEGER<2>>,SUBTRACT<VARIABLE<BOUNDS<0,3>>,LITERALINTEGER<3>>>>> expr;

    try{
        //printf("Value of the expression with x=%d is: %d\n",variable,expr::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }


}
