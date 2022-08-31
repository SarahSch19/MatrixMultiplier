/*
Matrix functions
Sarah Schlegel
Created : 12.12.2020
Last updated : 31.08.2022
*/

#include "matrix.h"

Matrix initMatrix () {
    Matrix m ;

    printf("Enter number of lines : ") ;
    m.lin = scanInt();
    printf("Enter number of columns : ") ;
    m.col = scanInt() ;

    m.matrix = allocEmptyMatrix(m.lin, m.col) ;
    m.matrix = enterMatrix(m.lin, m.col) ;
    printMatrix(m) ;

    return m ;
}

float **allocEmptyMatrix(size_t lin, size_t col) {
    float **m ;
    size_t i ;

    m = malloc(lin * sizeof(float *)) ;
    if (m == NULL)
        return NULL ;

    for (i = 0 ; i < lin ; ++i) {
        m[i] = malloc(col * sizeof(int)) ;
        if (m[i] == NULL)
            return NULL ;
            // unset all if errors
    }
    return m ;
}

float **enterMatrix (size_t lin, size_t col) {
    float **m ;
    size_t i ;
    size_t j ;

    m = allocEmptyMatrix(lin, col) ;
    printMessage("Entering matrix data\n") ;
    for (i = 0 ; i < lin ; ++i) {
        for (j = 0 ; j < col ; ++j) {
            printf("Enter m[%zd][%zd] : ", i, j) ;
            scanf("%f", &m[i][j]) ;
            fflush(stdin) ;
        }
    }

    return m ;
}


Matrix multiply (Matrix m1, Matrix m2) {
    Matrix result ;
    float tmp ;
    size_t i ;
    size_t j ;
    size_t k ;

    result.lin = m1.lin ;
    result.col = m2.col ;

    result.matrix = allocEmptyMatrix(result.lin, result.col) ;

    for (i = 0 ; i < result.lin ; ++i) {
        for (j = 0 ; j < result.col ; ++j) {
            tmp = 0.0 ;
            for (k = 0 ; k < m1.col ; ++k) {
                tmp += m1.matrix[i][k] * m2.matrix[k][j] ;
            }
            result.matrix[i][j] = tmp ;
        }
    }

    return result ;
}


void freeMatrix (Matrix m) {
    if (m.matrix != NULL) {
        for (size_t i = 0 ; i < m.lin ; ++i) {
            if (m.matrix[i] != NULL)
                free(m.matrix[i]) ;
        }
        free(m.matrix) ;
    }
}



void printMatrix (Matrix m) {
    if (m.matrix == NULL) return ;
    printMessage("Matrix output\n") ;
    for (size_t i = 0 ; i < m.lin ; ++i) {
        for (size_t j = 0 ; j < m.col ; ++j) {
            printf("%2.2f |", m.matrix[i][j]) ;
        }
        printf("\n") ;
    }
}
