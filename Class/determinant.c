#include <assert.h>
#include <stdio.h>

//  recursion function          l is the length of the original array;  n is the
//  length of current array.
long long determinantRecur(int l, int n, int *P, int limit[]) {
  long long sum = 0;

  for (int i = 0, count = 0; i < l; ++i) {
    if (!limit[i]) {  // if this row is true, then leave this row
      if (n == 1) {
        return *(P + i * l);
      }
      limit[i] = 1;
      if (count % 2 == 0) {
        sum += (*(P + i * l)) * determinantRecur(l, n - 1,P + 1, limit);
      } else {
        sum -= (*(P + i * l)) * determinantRecur(l, n - 1, P + 1, limit);
      }
      limit[i] = 0;
      ++count;
    }
  }
  return sum;
}

long long determinant(int n, int A[n][n]) {
  // YOUR CODE GOES HERE
  int limit[10] = {0};
  return determinantRecur(n, n, &A[0][0], limit);
}

/* int main(void) {
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int B[4][4] = {{5, 4, 3, 4}, {2, 3, 2, 3}, {1, 1, 1, 1}, {7, 4, 6, 5}};
  assert(determinant(3, A) == 0);
  assert(determinant(4, B) == 2);
  return 0;
} */
