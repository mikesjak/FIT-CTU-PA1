#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[102];
    int freq;
    int position;
} TCode;

typedef int (*Comp)(const void *, const void *);

int cmpCodes (const TCode * aPtr, const TCode * bPtr) {
    int a = aPtr->freq, b = bPtr->freq;
    return a == b ? 0 : ( a < b ? 1 : -1);
}

void addCode( TCode * codes, int * count, char * Name ){

    int flag = 0,
        cmpValue = -1;

    for (int i = 0; i <= (*count); i++){

        cmpValue = strcmp(Name,codes[i].name);

        if ( cmpValue == 0){
            codes[i].freq ++;
            flag = 1;
            break;
        }
        if (EOF) break;
    }
    
    if (flag != 1){
        codes[(*count)].freq = 1;
        strcpy(codes[(*count)].name,Name);
        codes[(*count)].position = (*count);
        (*count)++;
    }
    flag = 0;
}

void printCodes (TCode * codes, int count){

    qsort(codes, count, sizeof(codes[0]), (Comp)cmpCodes);

    if (count >= 10){
        for (int i = 0; i < 10; i++){
        printf("%s %dx\n", codes[i].name, codes[i].freq);
        }   
    }
    else {
        for (int i = 0; i < count; i++){
        printf("%s %dx\n", codes[i].name, codes[i].freq);
        }
    }
}

int main ( void ) {

    TCode * codes = NULL;

    int count = 0,
        capacity = 0;
    char tmp[102];

    while ( scanf(" %101s", tmp) == 1) {
        
        if (count >= capacity){
            capacity = (capacity * 2) + 4;
            codes = (TCode*) realloc ( codes, capacity * sizeof(codes[0]) + 100 );
        }
        addCode( codes, &count, tmp );
    }


    printCodes(codes, count);

    free(codes);
    return 0;
}
