// test for matrix

#include "matrix.h"
#include <stdio.h>

int main() {

  //struct matrix A = inputMatrixSize();
  //double arr1[A.m * A.n];
  //A.matrix = inputMatrixPointer(A, arr1);
  struct matrix A={3,3};
  double arr1[9]={4,-15,2,-2,8,-1,3,-10,1};
  A.matrix=arr1;

//   struct matrix B = inputMatrixSize();
//   double arr2[B.m * B.n];
//   B.matrix = inputMatrixPointer(B, arr2);

  struct matrix B={3,1};
  double arr2[3]={10,4,9};
  B.matrix=arr2;


  double arr3[A.m * B.n];
  struct matrix C = mMultiplication(A, B, arr3);

  printMatrix(C);

  return 0;
}