#include <stdio.h>

_Bool isLeapYear(int year)
{
    _Bool flag = 0;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        flag = 1;
    }
    return flag;
}

int main(void)
{
    int year;
    printf("Enter a year\n");
    scanf("%d", &year);
    printf(isLeapYear(year) ? ("year %d is a leap year\n") : ("year %d is not a leap year\n"),year);
    return 0;
}