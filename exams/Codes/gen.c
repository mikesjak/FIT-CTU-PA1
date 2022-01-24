#include <stdio.h>
#include <stdlib.h>

int main ( void ) {

    for ( int i = 0; i <= 100000; i++ ) {
        printf( "%d\n", (rand() % 100000 + 10000)); 
    }

    return 0;
}
