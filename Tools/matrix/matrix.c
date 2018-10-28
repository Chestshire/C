// implements functions for matrix.h
// matrix operations

#include "matrix.h"
#include <stdio.h>

/* ------------------------------- condition test ------------------------------
 */
// returns 1 if can add
int canAdd(struct matrix A, struct matrix B) {
  return ((A.m == B.m) && (A.n == B.n)) ? 1 : 0;
}

// returns 1 if can multiply
int canMultiply(struct matrix A, struct matrix B) {
  return (A.n == B.m) ? 1 : 0;
}

/* ------------------------------- Operation ------------------------------ */
// return the addittion of two matrices
struct matrix mAddition(struct matrix A, struct matrix B, double *arr) {
  struct matrix Addition;

  if (!canAdd(A, B)) {
    return Addition;
  }

  Addition.m = A.m;
  Addition.n = B.n;

  return Addition;
}

// return the multiplication of two matrices  (Oder matters)
struct matrix mMultiplication(struct matrix A, struct matrix B, double *arr) {
  struct matrix Multiplication;

  if (!canMultiply(A, B)) {
    return Multiplication;
  }

  double sum = 0.0;

  for (int i = 0; i < A.m; ++i) {
    for (int j = 0; j < B.n; ++j) {
      for (int k = 0; k < A.n; ++k) {
        sum += (*(A.matrix + j * A.n + k)) * (*(B.matrix + k * B.n + i));
      }
      arr[j * B.n + i] = sum;
      sum = 0.0;
    }
  }

  Multiplication.m = A.m;
  Multiplication.n = B.n;
  Multiplication.matrix = arr;

  return Multiplication;
}

// return the inverse of matrix A
struct matrix inverseOf(struct matrix A, double *arr) {
  struct matrix Inverse;

  return Inverse;
}

/* ------------------------------- I/O ------------------------------ */
// print the matrix
void printMatrix(struct matrix A) {
  for (int row = 0; row < A.m; ++row) {
    printf("|");
    for (int col = 0; col < A.n - 1; ++col) {
      printf("%0.3lf,\t", *(A.matrix + row * A.n + col));
    }
    printf("%0.3lf|\n", *(A.matrix + (row + 1) * A.n - 1));
  }
}

// write in a matrix
struct matrix inputMatrixSize() {
  int m = 0;
  int n = 0;
  printf("Please input m and n in the format of \"m,n\"\n");
  scanf("%d,%d", &m, &n);

  struct matrix A = {m, n};

  return A;
}

// add pointer to a matrix
double *inputMatrixPointer(struct matrix A, double *arr) {
  printf("Please input the content for the matrix in the format of  \"a1 a2 "
         "a3...\"\n");
  double nu = 0.0;
  double de = 0.0;
  for (int row = 0; row < A.m; ++row) {
    for (int col = 0; col < A.n; ++col) {
      scanf("%lf/%lf", &nu, &de);
      *(arr + row * A.n + col) = nu / de;
    }
  }
  return arr;
}
