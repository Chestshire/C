#include <stdio.h>

// euclidean algorithm
int gcdEu(int a, int b)
{
    return b == 0 ? a : gcdEu(b, a % b);
}

// stein algorithm. better when big prime numbers are involved.
int Min(int a, int b)
{
    return a < b ? a : b;
}

int abs(int a)
{
    return a >= 0 ? a : -a;
}

int gcdStein(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a % 2 == 0 && b % 2 == 0)
        return 2 * gcdStein(a >> 1, b >> 1);
    else if (a % 2 == 0)
        return gcdStein(a >> 1, b);
    else if (b % 2 == 0)
        return gcdStein(a, b >> 1);
    else
        return gcdStein(abs(a - b), Min(a, b));
}

int main(void)
{
    int a = 0, b = 0, gcd1 = 0, gcd2 = 0;
    scanf("%d %d", &a, &b);
    gcd1 = gcdEu(a, b);
    gcd2 = gcdStein(a, b);
    if (gcd1 != gcd2)
    {
        printf("someting's wrong");
    }
    else
    {
        printf("GCD_1 = GCD_2 : %d = %d", gcd1, gcd2);
    }
    return 0;
}
