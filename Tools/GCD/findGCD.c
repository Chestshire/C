#include <stdio.h>

int gcd_1(int a, int b)
{
    return b == 0 ? a : gcd_1(b, a % b);
}

int gcd_2(int a, int b)
{

    return 0;
}

int main(void)
{
    int a = 0, b = 0, gcd = 0;
    scanf("%d %d", &a, &b);
    gcd = gcd_1(a, b);
    //gcd = gcd_2(a, b);
    printf("GCD: %d", gcd);
    return 0;
}
