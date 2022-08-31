/*
Matrix header file
Sarah Schlegel
Created : 12.12.2020
Last updated : 31.08.2022
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "utils.h"

typedef struct Matrix {
    size_t lin ;
    size_t col ;
    float **matrix ;
} Matrix ;


Matrix initMatrix () ;
float **allocEmptyMatrix(size_t lin, size_t col) ;
float **enterMatrix (size_t lin, size_t col) ;
void freeMatrix (Matrix m) ;
void printMatrix (Matrix m) ;
Matrix multiply (Matrix m1, Matrix m2) ;

#endif
