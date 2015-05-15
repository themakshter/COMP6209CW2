#include <iostream>
#include <limits>
#include "expressions.h"

int main()
{
    // x + (y - 2) * (z - 3), x bounds are (0,4), y bounds are (0,6), z bounds are (0,3)
    typedef EXPRESSION<ADD<VARIABLE<BOUNDS<0,4>>,MULTIPLY<SUBTRACT<VARIABLE<BOUNDS<0,6>>,LITERALINTEGER<2>>,SUBTRACT<VARIABLE<BOUNDS<0,3>>,LITERALINTEGER<3>>>>> expr;
    int results[4];
    int values[3];
    try
    {
        // x = 2, y = 4, z = 1
        values[0] = 2;
        values[1] = 4;
        values[2] = 1;
        results[0] = expr::eval(values);

        // x = 0, y = 3, z = 2
        values[0] = 0;
        values[1] = 3;
        values[2] = 2;
        results[1] = expr::eval(values);

        // x = 1, y = 1, z = 1
        values[0] = 1;
        values[1] = 1;
        values[2] = 1;
        results[2] = expr::eval(values);

        // x = 4, y = 6, z = 3
        values[0] = 4;
        values[1] = 6;
        values[2] = 3;
        results[3] = expr::eval(values);

        for(int i = 0;i < 4; i++){
            printf("results[%d]: %d\n",i,results[i]);
        }


    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }


}
