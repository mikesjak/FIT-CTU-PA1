#include <stdio.h>
#include <stdlib.h>

int main ( void ) {

    int x;

    for (int i = 0; i <= 99999; i++){
        
        x = rand() % 3;

        // +
        switch (x) {
            case 0:
                printf( "+ %d %d\n",rand() % 10000000, rand() % 10000 );
                break;
            case 1:
                printf("- %d %d\n",rand() % 10000000, rand() % 10000 );
                break;
            case 2:
                printf("? %d\n", rand() % 1001);
            break;
            default:
                return 1;
        }

    }
    return 0;
}
