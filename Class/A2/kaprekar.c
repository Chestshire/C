#include <stdio.h>
#include <assert.h>

#define SIZE 4

//calculate powers
int power(int num, int pow)
{
  return (pow > 0) ? num * power(num, pow - 1) : 1;
}

//swap two addresses
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

//sorting in arrays
void bubbleSort(int arr[])
{
  for (int i = 0; i < SIZE; ++i)
  {
    for (int j = i + 1; j < SIZE; ++j)
    {
      if (arr[i] < arr[j])
      {
        swap(&arr[i], &arr[j]);
      }
    }
  }
}

//the maximum of the combination could be
int max(int *array)
{
  int num = 0;
  for (int i = 0; i < SIZE; ++i)
  {
    num += array[i] * power(10, 3 - i);
  }
  return num;
}

int min(int *array)
{
  int num = 0;
  for (int i = 0; i < SIZE; ++i)
  {
    num += array[i] * power(10, i);
  }
  return num;
}

//return the address of a array that includes 4 digits
int *returnArray(int num)
{
  static int array[SIZE];
  array[0] = num % 10;
  for (int i = 1; i < SIZE; ++i)
  {
    array[i] = (num / power(10, i)) % 10;
  }
  bubbleSort(array);
  return array;
}

// The operating function (gate)
int kaprekar(int N)
{
  int size = 0;
  int copy = N;

  while (copy >= 1)
  {
    copy /= 10;
    ++size;
  }
  if (size > 4 || N == 0)
  {
    return -1;
  }
  //Add zeroes
  else if (size < 4)
  {
    N *= power(10, 4 - size);
  }

  int diff = N, a = 0, b = 0, count = 0;
  int *digits;

  do
  {
    digits = returnArray(diff);
    a = max(digits);
    b = min(digits);
    printf("%04d - %04d = %04d\n",a,b,a-b);    
    diff = a - b;
    ++count;
  } while (diff != 0 && diff != 6174);
  if (diff == 0)
  {
    count = 0;
  }
  return count;
}

/* int main(void)
{
  int t1 = kaprekar(6174);
  int t2 = kaprekar(6767);
  int t3 = kaprekar(1);
  int t4 = kaprekar(1111);
  int t5 = kaprekar(0);
  printf("%d", t1 == 1 && t2 == 4 && t3 == 5 && t4 == 0 && t5 == -1);
  return 0;
} */
