/*
Matrix multiplier
Sarah Schlegel
Created : 12.12.2020
Last updated : 31.08.2022
*/

#include "utils.h"

int matrixMultiply () ;
void printMatrix (float **m, size_t lin, size_t col) ;
float **enterMatrix (size_t lin, size_t col) ;
float ** multiplyMatrix (float **m1, float **m2, size_t lin, size_t col) ;
void freeMatrix (float **m, size_t lin) ;

int main () {
    size_t choice = 1 ;
    while (choice == 1 || choice == 0) {
        displayMenu() ;
        printf("Choose : ") ;
        choice = scanInt() ;
        if (choice == 0) {
            printMessage("Quitting…\n") ;
            return 0 ;
        }
        if (choice == 1) matrixMultiply() ;
    }
    printError("Wrong choice\n") ;
    return 1 ;
}


int matrixMultiply () {
    float **m1 = NULL ;
    float **m2 = NULL ;
    float **m = NULL ;
    size_t linM1 ;
    size_t colM1 ;
    size_t linM2 ;
    size_t colM2 ;

    printf("Enter M1 lines : ") ;
    linM1 = scanInt();
    printf("Enter M1 columns : ") ;
    colM1 = scanInt() ;

    printf("Enter M2 lines : ") ;
    linM2 = scanInt() ;
    printf("Enter M2 columns : ") ;
    colM2 = scanInt() ;

    if (colM1 != linM2) {
        printError("These matrices can't be multiplied\n") ;
        return 1 ;
    }

    m1 = enterMatrix(linM1, colM1) ;
    printMatrix(m1, linM1, colM1) ;
    m2 = enterMatrix(linM2, colM2) ;
    printMatrix(m2, linM2, colM2) ;

    m = multiplyMatrix(m1, m2, linM1, colM2) ;
    printMatrix(m, linM1, colM2) ;

    freeMatrix(m1, linM1) ;
    freeMatrix(m2, linM2) ;
    freeMatrix(m, linM1) ;
    return 0 ;
}

float **enterMatrix (size_t lin, size_t col) {
    float **m ;
    size_t i ;
    size_t j ;

    m = malloc(lin * sizeof(float *)) ;
    if (m == NULL)
        return NULL ;

    for (i = 0 ; i < lin ; ++i) {
        m[i] = malloc(col * sizeof(int)) ;
        if (m[i] == NULL)
            return NULL ;
    }
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

float ** multiplyMatrix (float **m1, float **m2, size_t lin, size_t col) {
    float **m = NULL ;
    float tmp ;
    size_t i ;
    size_t j ;
    size_t k ;

    m = malloc(lin * sizeof(float *)) ;
    if (m == NULL)
        return NULL ;

    for (i = 0 ; i < lin ; ++i) {
        m[i] = malloc(col * sizeof(int)) ;
        if (m[i] == NULL)
            return NULL ;
    }

    for (i = 0 ; i < lin ; ++i) {
        for (j = 0 ; j < col ; ++j) {
            tmp = 0.0 ;
            for (k = 0 ; k < col ; ++k) {
                tmp += m1[i][k] * m2[k][j] ;
            }
            m[i][j] = tmp ;
        }
    }

    return m ;
}

void freeMatrix (float **m, size_t lin) {
    if (m != NULL) {
        for (size_t i = 0 ; i < lin ; ++i) {
            if (m[i] != NULL)
                free(m[i]) ;
        }
        free(m) ;
    }
}

void printMatrix (float **m, size_t lin, size_t col) {
    printMessage("Matrix\n") ;
    for (size_t i = 0 ; i < lin ; ++i) {
        for (size_t j = 0 ; j < col ; ++j) {
            printf("%2.2f |", m[i][j]) ;
        }
        printf("\n") ;
    }
}
