#include <stdio.h>
#include <time.h>

int squareRootFloor(int a)
{
    int copy = a, digits = 0,b = 0;
    //find how many disgits
    while (copy >= 1)
    {
        copy /= 10;
        digits++;
    }

    copy = a;
    for (int i = 0; i < digits/2; i++)
    {
        copy /= 10;
    }

    b = copy;

    while (1)
    {
        int bSquared = b * b;
        if (bSquared > a)
        {
            b = (b / 2) - 1;
        }
        else if (bSquared == a)
        {
            return b;
        }
        else
        {
            int bp1Squared = (b + 1) * (b + 1);
            if (bp1Squared < a)
            {
                b++;
            }
            else if (bp1Squared == a)
            {
                return ++b;
            }
            else
            {
                return b;
            }
        }
    }
}

int main(void)
{
    int
        a = 2;
    clock_t start = clock();
    int ans = squareRootFloor(a);
    clock_t end = clock();
    printf("num:%d\n", ans);
    printf("num*num:%d    real ans = %d\n", ans * ans, a);
    // printf("takes:%G\n", end - start);
    return 0;
}