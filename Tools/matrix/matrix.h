// Contains matrix operations

#ifndef MATRIX_OPERATION
#define MATRIX_OPERATION

// struct for matrices
struct matrix{
    int m;                     // size of m (number of functions) 
    int n;                      // size of n (number of variables)
    double *matrix;            // pointer for the matrix, matrix should be a (m x n) matrix
};

/* ------------------------------- condition test ------------------------------ */
// returns 1 if can add
int canAdd(struct matrix A, struct matrix B);

// returns 1 if can multiply
int canMultiply(struct matrix A, struct matrix B);

/* ------------------------------- Operation ------------------------------ */
// return the addittion of two matrices
struct matrix mAddition(struct matrix A, struct matrix B, double *arr);

// return the multiplication of two matrices (Oder matters)
struct matrix mMultiplication(struct matrix A, struct matrix B, double *arr);

// return the inverse of matrix A
struct matrix inverseOf(struct matrix A, double *arr);

/* ------------------------------- I/O ------------------------------ */
// print the matrix
void printMatrix(struct matrix A);

// write in a matrix
struct matrix inputMatrixSize();

// return the pointer (add pointer to a matrix)
double * inputMatrixPointer(struct matrix A, double *arr);

#endif