#include <stdio.h>
#include <stdlib.h>

int main ( void ) {

    int patra, mista;
    scanf("%d %d", &patra, &mista);
    int x;

    printf(" %d %d", patra, mista);

    for (int i = 0; i <= 500000; i++){
        
        x = rand() % 2;

        // +
        if (x == 0){
            printf("+ %d %d %d\n",rand() % patra, rand() % mista, rand() % 100000);
        }
        else {
            printf("- %d\n", rand() % 100000);
        }

    }
    return 0;
}
