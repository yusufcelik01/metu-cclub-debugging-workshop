#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int factorial_iterative(int x);

int main(int argc, char** argv)
{

    int i;
    for(i = 8; i > 0; --i)
    {
        printf("factorial %d is %d\n", i, factorial(i));
    }

    return 0;
}

int factorial(int x)
{
    if(x == 2)  return 1;
    return x * factorial(x-1);
}

int factorial_iterative(int x)
{
    int acc = 1;
    while(x--){
        acc *= x;
    }
    return acc;
}
