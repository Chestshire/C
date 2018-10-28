#include <stdio.h>
#include <time.h>

int squareRootFloor(int a) {
  int copy = a, digits = 0, b = 0;
  // find how many disgits
  while (copy >= 1) {
    copy /= 10;
    digits++;
  }

  copy = a;
  for (int i = 0; i < digits / 2; i++) {
    copy /= 10;
  }

  b = copy;

  while (1) {
    int bSquared = b * b;
    if (bSquared > a) {
      b = (b / 2) - 1;
    } else if (bSquared == a) {
      return b;
    } else {
      int bp1Squared = (b + 1) * (b + 1);
      if (bp1Squared < a) {
        b++;
      } else if (bp1Squared == a) {
        return ++b;
      } else {
        return b;
      }
    }
  }
}

/*
test examples:
example 1: 987654323
 */

//  Divide every positive integer number (except 1) which is less than the input
//  number.        take 2.56 sec to prove the example 1
_Bool isPrimeNumber_1(int num) {
  if (num == 1) {
    return 0;
  }
  for (int i = 2; i < num; ++i) {
    if (num % i != 0) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

// Based on "isPrimeNumber_1",    only try the factors up to half of the input
// number.     take 1.43 sec to prove the example 1
_Bool isPrimeNumber_2(int num) {
  if (num == 1) {
    return 0;
  }
  for (int i = 2; i < num / 2; ++i) {
    if (num % i != 0) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

// since all the prime numbers are odd except "2", so this time will only try
// the odd numbers and 2,   take 0.71 sec to prove the example 1
_Bool isPrimeNumber_3(int num) {
  if (num == 1) {
    return 0;
  }
  // try 2 first
  if (num % 2 == 0) {
    return 0;
  }
  for (int i = 3; i < num / 2; i += 2) {
    if (num % i != 0) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

// This time only try the potential factors to sqrt(input number).  takes almost
// 0.0 sec for test example
_Bool isPrimeNumber_4(int num) {
  if (num == 1) {
    return 0;
  }
  int top = squareRootFloor(num) + 1;
  // try 2 first
  if (num % 2 == 0) {
    return 0;
  }
  for (int i = 3; i < top; i += 2) {
    if (num % i != 0) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

_Bool isPrimeNumber_5(int num) {
  if (num == 1) {
    return 0;
  }
  int top = squareRootFloor(num) + 1;
  // try 2 first
  if (num % 2 == 0) {
    return 0;
  }
  for (int i = 3; i < top; i += 2) {
    if (num % i != 0) {
      continue;
    } else {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  int num = 0;
  clock_t tStart, tFinish;
  double duration;

  printf("Please input the number for prime number test.\n");

  while (1) {
    // input
    scanf("%d", &num);

    tStart = clock();

    printf("Primes numbers:\n");

    for (int i = 1; i < num; ++i) {
      if (isPrimeNumber_4(i)) {
        printf("%d \n", i);
      }
    }

    tFinish = clock();
    duration = (double)(tFinish - tStart) / CLOCKS_PER_SEC;

    printf("Execution tooks %f seconds\n", duration);
  }

  return 0;
}