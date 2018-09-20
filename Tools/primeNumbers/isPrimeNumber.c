#include <stdio.h>
#include <time.h>

/*
test examples:
example 1: 987654323 
 */

//  Divide every positive integer number (except 1) which is less than the input number,        take 2.56 sec to prove the example 1
_Bool isPrimeNumber_1(int num)
{
    for (int i = 2; i < num; ++i)
    {
        if (num % i != 0)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

_Bool isPrimeNumber_2(int num)
{

    return 0;
}

int main(void)
{
    int num = 0;
    clock_t tStart, tFinish;
    double duration;

    printf("Please input the number for prime number test.\n");

    while (1)
    {
        //input
        scanf("%d", &num);

        tStart = clock();

        if (isPrimeNumber_2(num))
            printf("num: %d is a prime number.\n", num);
        else
            printf("num: %d is a composite number.\n", num);

        tFinish = clock();
        duration = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

        printf("Execution tooks %f seconds\n", duration);
    }

    return 0;
}