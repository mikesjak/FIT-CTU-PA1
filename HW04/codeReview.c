#include <stdio.h>
//konstanty, funkce

#define ID_limit 100000

/*-----------------------------------------------------------------------------------+
    uniqueAccessLog function counts unique accesses.                                 |
    It goes thrue a period in the array that has the IDs stored.                     |
    For every ID in Access it creates 'True' (1) in uniqueAccessLog.                 |
    Then it counts all the true values and returns the result.                       |
    It also has to fill the whole array with 0 so it can be used multiple times.     |
------------------------------------------------------------------------------------*/

void uniqueAccessCounter( int start, int end, int* uniqueAccessLog, int* access){

    int id = 0, UAcount = 0;
    for ( int i = start; i <= end; i ++ ){
        id = access[i];
        uniqueAccessLog[id] = 1;
    }
    for ( int j = 0; j < ID_limit; j++){
        UAcount += uniqueAccessLog[j];
        uniqueAccessLog[j] = 0;
    }
    printf("> %d / %d\n", UAcount,(end-start+1));;
}

/*----------------------------------------------------------------+
    visitsCounter function counts how many times was the ID seen. |
------------------------------------------------------------------*/

void visitsCounter (int * numberOfVisits, int id) {

    if (numberOfVisits[id] == 0){
        printf("> prvni navsteva\n");
        }
    else {
        printf("> navsteva #%d\n", numberOfVisits[id]+1);
    }

}

int main ( void ){
    
    static int numberOfVisits[ID_limit];
    static int access[1000000];
    static int uniqueAccessLog[ID_limit];

    int count = 0, 
        start, end, scan;
    char sign;

    printf("Pozadavky:\n");
    while(scanf(" %c", &sign) == 1){
        switch (sign){
            default:
                printf("Nespravny vstup.\n");
                return 1;
                break;
            case '+':
                int id;
                scan = scanf("%d", &id);
                if (scan != 1
                 || id < 0
                 || id >= ID_limit
                 || count >= 1000000){
                    printf("Nespravny vstup.\n");
                    return 1;
                }
                
                visitsCounter ( numberOfVisits, id);
                
                access[count] = id;
                numberOfVisits[id] ++;
                count ++;

                break;

            case '?':
                scan = scanf(" %d %d", &start, &end);
                if (scan != 2
                    || start > end
                    || start < 0
                    || end >= count){
                    printf("Nespravny vstup.\n");
                    return 1;
                }

                uniqueAccessCounter( start, end, uniqueAccessLog, access);

                break;            
        }
    }

    if(!feof(stdin)){
        return 0;
    }

    return 0;
}
