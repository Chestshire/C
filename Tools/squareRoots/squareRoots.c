#include <stdio.h>
#include <time.h>
#include <math.h>

int squareRootFloor(int inputNumber)
{
    int copy = inputNumber, digits = 0, solution = 0, solutionSquared = 0, max = 0, min = 0;
    //find how many digits
    while (copy >= 1)
    {
        copy /= 10;
        ++digits;
    }

    //the square root of a number can never exceed that number with a half less digits
    digits = (digits - 1) / 2;

    solution = inputNumber;
    for (int i = 0; i < digits; ++i)
    {
        solution /= 10;
    }

    max = solution + 2;
    //find the solution with bisection
    while (1)
    {
        if (max - min == 1)
        {
            return min;
        }
        solutionSquared = solution * solution;
        if (solutionSquared > inputNumber)
        {
            max = solution;
            solution = max - ((max - min) / 2);
        }
        else if (solutionSquared < inputNumber)
        {
            min = solution;
            solution = min + ((max - min) / 2);
        }
        else
        {
            return solution;
        }
    }
}

int squareRootFloor_2(int num)
{
    double ans = sqrt(num);
    return floor(ans);
}

int main(void)
{
    /*     int a = 0;
    while (1)
    {
        printf("Type in the number you want to test:\n");
        scanf("%d", &a);
        if (a == 0)
        {
            return 0;
        }
        // clock_t start = clock();
        int ans = squareRootFloor(a);
        // clock_t end = clock();
        printf("num:%d\n", ans);
        printf("num*num:%d    real ans = %d\n", ans * ans, a);
        // printf("takes:%G\n", end - start);
    }
    return 0; */

    int num = 0;
    double timeA = 0.0, timeB = 0.0;
    clock_t start, end;

    scanf("%d", &num);

    for (int i = 0; i < 5; ++i)
    {
        start = clock();
        for (int i = 0; i < num; ++i)
        {
            squareRootFloor(i);
        }
        end = clock();

        timeA = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        for (int i = 0; i < num; ++i)
        {
            squareRootFloor_2(i);
        }
        end = clock();

        timeB = (double)(end - start) / CLOCKS_PER_SEC;

        if (timeA < timeB)
        {
           printf("A 1 is \t%G s\t faster,  A 1 took    %G s,   A 2 took   %G s\n",timeB - timeA,timeA,timeB);
        }
        else
        {
            printf("A 2 is \t%G s\t faster,  A 1 took   %G s,   A 2 took   %G s\n",timeA - timeB,timeA,timeB);
        }
    }

    return 0;
}