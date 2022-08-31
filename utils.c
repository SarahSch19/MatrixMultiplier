/*
Utils functions
Sarah Schlegel
Created : 12.12.2020
Last updated : 31.08.2022
*/

#include "utils.h"


size_t scanInt () {
    size_t number ;
    scanf("%zd", &number) ;
    fflush(stdin) ;
    return number ;
}

void printError (char *message) {
    fprintf(stderr, "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n") ;
    fprintf(stderr, "%s", message) ;
    fprintf(stderr, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n") ;
}

void printHeader (char *message) {
    printf("\n\n*****************************\n") ;
    printf("%s", message) ;
    printf("*****************************\n") ;
}

void printMessage (char *message) {
    printf("\n\n") ;
    printf("%s", message) ;
    printf("-----------------------------\n") ;
}

void displayMenu () {
    printf("Menu :\n") ;
    printf("   0 - quit\n") ;
    printf("   1 - start computation\n") ;
}
