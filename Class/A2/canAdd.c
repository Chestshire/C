#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

//returns true if the sum of two long number can fit in type long
bool can_add(long long num1, long long num2)
{
  //state remainder
  long long r = 0;

  bool flag = true;

  //Both are positive
  if (num1 >= 0 && num2 >= 0)
  {
    r = LONG_MAX - num1;
    if (num2 > r)
    {
      flag = false;
    }
  }
  //Both are negative
  else if (num1 < 0 && num2 < 0)
  {
    r = LONG_MIN - num1;
    if (num2 < r)
    {
      flag = false;
    }
  }
  //One is positive and one is negative
  else
  {
    long long positive = 0, negative = 0;
    if (num1 >= num2)
    {
      positive = num1;
      negative = num2;
    }
    else
    {
      positive = num2;
      negative = num1;
    }

    r = LONG_MAX + negative;
    positive += r;
    if (positive > LONG_MAX)
    {
      flag = false;
    }
  }

  return flag;
}

/* int main(void)
{
  printf("%d\n", can_add(LONG_MIN, LONG_MIN));
  printf("%d\n", can_add(LONG_MAX, LONG_MAX));
  printf("%d\n", can_add(LONG_MAX, LONG_MIN));
  printf("%d\n", can_add(LONG_MAX, 1));
  printf("%d\n", can_add(LONG_MIN, 1));
  printf("%d\n", can_add(LONG_MIN, -1));
  return 0;
} */
