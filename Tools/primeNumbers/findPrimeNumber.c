#include <stdio.h>
#include <time.h>


_Bool isPrimeNumber_1(int num)
{
    for (int i = 3; i < num; ++i)
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

        printf("Primes numbers:\n");

        for (int i = 1; i <= num; ++i)
        {
            if (isPrimeNumber_1(i))
            {
                printf("%d \n", i);
            }
        }

        tFinish = clock();
        duration = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

        printf("Execution tooks %f seconds\n", duration);
    }

    return 0;
}