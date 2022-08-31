/*
Matrix multiplier
Sarah Schlegel
Created : 12.12.2020
Last updated : 31.08.2022
*/

#include "matrix.h"

int matrixMultiply () ;

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
    Matrix m1 ;
    Matrix m2 ;
    Matrix multiplied ;

    printHeader("Init matrix 1\n") ;
    m1 = initMatrix() ;

    printHeader("Init matrix 2\n") ;
    m2 = initMatrix() ;

    if (m1.col != m2.lin) {
        printError("These matrices can't be multiplied\n") ;
        freeMatrix(m1) ;
        freeMatrix(m2) ;
        return 1 ;
    }

    printHeader("Multiplying matrices\n") ;
    multiplied = multiply(m1, m2) ;
    printMatrix(multiplied) ;

    freeMatrix(m1) ;
    freeMatrix(m2) ;
    freeMatrix(multiplied) ;
    return 0 ;
}
