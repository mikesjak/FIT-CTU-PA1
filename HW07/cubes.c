#include <stdio.h>
#include <stdlib.h>

/*
Function inspired from Geek4Geeks
https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
*/

void printCubes ( int * cubes, int * help_arr, int start, int end, int index, int length, int * counter){

// tower is ready to be printed
    if( index == length ){
        for ( int i = 0; i < length; i++ ){
            printf("%d", help_arr[i]);
            if (i < length-1) {
                printf(", ");
            }
        }
        printf("\n");
        (*counter) ++;
        return;
    }

// creating all possible combinations
    for ( int i = start; end >= i; i++ ){
        help_arr[index] = cubes[i];
        printCubes(cubes, help_arr, i+1, end, index+1, length, counter);

// checking duplicates
// using the fact that the cubes are sorted so the duplicates are one after another
        while(cubes[i]==cubes[i+1]){
            i++;
        }
    }
}

int cmpfunc ( const void * a, const void * b ){
   return ( *(int*)b - *(int*)a );
}

int main ( void ) {

    int counter = 0;
    int arraylen = 0;

// scanning length of array cubes
    printf("Pocet kostek:\n");
    if ( scanf(" %d", &arraylen) != 1 ){
        printf("Nespravny vstup.\n");
        return 1;
    }
    if (arraylen <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }

// allocing arrays
    int * cubes = (int *) malloc( ( arraylen + 2 ) * sizeof( * cubes ) );
    int * help_arr = (int *) malloc( ( arraylen + 2 ) * sizeof( * help_arr ) );

// scanning all cubes
    printf("Velikosti:\n");
    for ( int i = 0; i < arraylen; i++ ){
        if (scanf(" %d", &cubes[i]) != 1) {
            printf("Nespravny vstup.\n");
            free(help_arr);
        free(cubes);
            return 1;
        }
        if ( cubes[i] <= 0 ){
            printf("Nespravny vstup.\n");
            free(help_arr);
            free(cubes);
            return 1;
        }
    }

// sorting cubes so I dont have to check if cubes are in a right order
    qsort( cubes, arraylen, sizeof(int), cmpfunc );

// calling for towers in different heights
    for( int i = arraylen; i >= 1; i-- ){
        printCubes( cubes, help_arr, 0, arraylen-1, 0, i, &counter );
    }
    printf("Celkem: %d\n", counter);

// Freeing allocated memory
    free(help_arr);
    free(cubes);
    return 0;
}
