#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------------------------*
 + prida do skladu uvedeny pocet kusu       |
 - odebere ze skladu uvedeny pocet kusu     |
 ? kod vypise zadaneho produktu             |
-------------------------------------------*/

typedef struct {
    char Name[100];
    int Amount;
} TGoods;

typedef int (*Comp)(const void *, const void *);

int cmpGoods ( const TGoods * aPtr, const TGoods * bPtr ) {
    int a = aPtr->Amount, b = bPtr->Amount;
    return a == b ? 0 : ( a < b ? 1 : -1 );
}
void addProduct ( TGoods * goods, char * Name, int Amount, int * count ) {
    int compareValue = 0,
        flag = 0,
        counterPtr = 0;
    int i = 0;
    counterPtr = (*count);
    for ( i = 0; i <= counterPtr; i++){
        compareValue = strcmp(goods[i].Name, Name);
        if (compareValue == 0){
            goods[i].Amount += Amount;
            flag = 1;
            printf("Pridano.\n");
            break;
        }
    }
    if (flag == 0){
            printf("Nove zbozi.\n");
            goods[counterPtr].Amount = Amount;
            strcpy(goods[counterPtr].Name,Name);

            counterPtr++;
    }
    (*count) = counterPtr;
}
void takeProduct ( TGoods * goods, char * Name, int Amount, int * count  ) {
    int compareValue = 0,
        flag = 0,
        counterPtr = 0;
    int i = 0;
    counterPtr = (*count);
    for ( i = 0; i <= counterPtr; i++){
        compareValue = strcmp(goods[i].Name, Name);
        if (compareValue == 0){
            if (goods[i].Amount >= Amount){
                goods[i].Amount -= Amount;
                printf("Odebrano.\n");
            }
            else {
                printf("Nedostatek zbozi\n");
            }
            flag = 1;
            break;
        }
    }
    if (flag == 0){
            printf("Zbozi neni evidovano.\n");
    }
    (*count) = counterPtr;
}

void goodsCounter ( TGoods * goods, char * Name, int * count ) {
    int compareValue = 0,
        flag = 0,
        counterPtr = 0;
    int i = 0;
    counterPtr = (*count);
    for ( i = 0; i <= counterPtr; i++){
        compareValue = strcmp(goods[i].Name, Name);
        if (compareValue == 0){
            printf("Kusu: %d.\n", goods[i].Amount);
            flag = 1;
            break;
        }
    }
    if (flag == 0){
            printf("Zbozi neni evidovano.\n");
    }
}
int main ( void ){
    TGoods * goods = NULL;
    int count = 0,
        capacity = 0;
    TGoods tmp;
    char sign;
    printf("Prikazy:\n");
    while ( scanf(" %c %99s", &sign, tmp.Name) == 2 ){
        if ( strlen(tmp.Name) >= 100){
            free(goods);
            return 1;
        }
        if ( count >= capacity ){
            capacity = (capacity * 2) + 4;
            goods = (TGoods*) realloc (goods, capacity * sizeof(goods[0]) + 1000);
        }
        switch (sign) {
            default:
                printf("Nespravny vstup.\n");
                return 1;
                free(goods);
                break;
            case '+':
                if (scanf(" %d", &tmp.Amount) != 1
                 || tmp.Amount < 1){
                        free(goods);
                        return 1;
                }
                addProduct( goods, tmp.Name, tmp.Amount, &count);
                break;
            case '-':
                if (scanf(" %d", &tmp.Amount) != 1
                 || tmp.Amount < 1){
                        free(goods);
                        return 1;
                }
                takeProduct( goods, tmp.Name, tmp.Amount, &count );
                break;
            case '?':
                goodsCounter( goods, tmp.Name, &count );
                break;
        }
        memset(tmp.Name, 0, strlen(tmp.Name));
        tmp.Amount = 0;
    }
    free(goods);
    return 0;
}
