#include <iostream>
#include <limits>
#include "expressions.h"

int main()
{
    //values
    int variable = 5;
    const int lowerBound = 0;
    const int upperBound = 5;

    //(x + 3) * (x + 5) with bounds (0,5)
    typedef EXPRESSION<MULTIPLY<SUBTRACT<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<3>>,SUBTRACT<VARIABLE<BOUNDS<lowerBound,upperBound>>,LITERALINTEGER<5>>>> expr;

/*
    //calculating the upper and lower bounds by iterating through all values in case it exists somewhere in the middle
    int maxBounds = numeric_limits<int>::min();
    int minBounds = numeric_limits<int>::max();
    for(int i = lowerBound; i <= upperBound; i++){
        try{
            int temp = expr::eval(i);
            if(temp > maxBounds){
                maxBounds = temp;
            }
            if(temp < minBounds){
                minBounds = temp;
            }
        }catch(exception &e){

        }
    }

    printf("Lower bounds of the equation is : %d\n",minBounds);
    printf("Upper bounds of the equation is : %d\n",maxBounds);

*/
    try{
        printf("Value of the expression with x=%d is: %d\n",variable,expr::eval(variable));
    }catch(exception &e){
        cout << e.what() << endl;
    }


}
