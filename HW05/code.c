#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure of Goods
typedef struct {
    char Name[101];
    int Amount;
} TGoods;

// C magic from flowerpot (cvicici) - Ondrej Wrzecionko
typedef int (*Comp)(const void *, const void *);

// Sorting function from flowerpot (cvicici) - Ondrej Wrzecionko
int cmpGoods ( const TGoods * aPtr, const TGoods * bPtr ) {
    int a = aPtr->Amount, b = bPtr->Amount;
    return a == b ? 0 : ( a < b ? 1 : -1 );
}

int main ( void ){

    TGoods * Goods = NULL;
    int count = 0, capacity = 0, NumberOfWatched = 0;
    TGoods tmp;
    char sign;

    printf("Pocet sledovanych:\n");
    if ( scanf(" %d", &NumberOfWatched) != 1
        || NumberOfWatched <= 0 ) {
            printf("Nespravny vstup.\n");
            free(Goods);
            return 1;
        }

    printf("Pozadavky:\n");
    while ( scanf(" %c", &sign) == 1 ){

        // Reallocation of memory
        if ( count >= capacity ){
            capacity = (capacity * 2) + 4;
            Goods = (TGoods *) realloc ( Goods, capacity * sizeof(Goods[0]) );
        }

        int flag = 0;
        int PrintedGoods = 0, index = 0,
            range = 1, sum = 0;

        switch (sign) {
            default:
                printf("Nespravny vstup.\n");
                free(Goods);
                return 1;

                break;
            case '#':
                
                // Sorting the Array from the biggest amount to the lowest
                qsort ( Goods, count, sizeof(Goods[0]), (Comp) cmpGoods );
                
                while (PrintedGoods < NumberOfWatched && count > PrintedGoods){
                    // Counting how many Goods has same amount
                    while ((Goods[index].Amount == Goods[index+1].Amount) && (index < count-1)){
                        range ++;
                        index ++;
                    } 
                    // If it is the only one with that amount, it prints its place in an Array+1 etc.
                    if ( range == 1 ){
                        printf("%d. %s, %dx\n", index+1, Goods[index].Name, Goods[index].Amount);
                        sum += Goods[index].Amount;
                        PrintedGoods++;
                        // printf("Index-%d | Range-%d\n", index, range);
                    }
                    // If range > 1 -> prints the Goods with the same amount of orders
                    else {
                        for ( int i = 0; i < range; i++){
                            printf("%d.-%d. %s, %dx\n",index-range+2, index+1, Goods[index-i].Name, Goods[index-i].Amount);
                            sum += Goods[index-i].Amount;
                            PrintedGoods ++;
                            // printf("Index-%d | Range-%d\n", index, range);
                        }
                    }
                    
                    range = 1;
                    index ++;
                    
                }

                printf("Nejprodavanejsi zbozi: prodano %d kusu\n", sum);

                break;
            case '+':
                if (scanf(" %100s", tmp.Name) != 1 
                    || strlen(tmp.Name) > 99){
                    printf("Nespravny vstup.\n");
                    return 1;
                    free(Goods);
                }
                tmp.Amount = 1;
                
                for (int i = 0; i < count; i++) {
                    int CompValue = strcmp(Goods[i].Name, tmp.Name);
                    if (CompValue == 0){
                        Goods[i].Amount += 1;
                        flag = 1;
                        // printf("%s %d\n", Goods[i].Name, Goods[i].Amount);
                    }
                }

                if (flag != 1) {
                    Goods[count] = tmp;
                    // printf("Nove zbozi.\n");
                    count++;
                }
                
                break;
            case '?':

                // Sorting the Array from the biggest amount to the lowest
                qsort ( Goods, count, sizeof(Goods[0]), (Comp) cmpGoods );

                // Counting how many Goods has same amount
                while (PrintedGoods < NumberOfWatched && count > PrintedGoods){
                    // Counting how many Goods has same amount
                    while ((Goods[index].Amount == Goods[index+1].Amount) && (index < count-1)){
                        range ++;
                        index ++;
                    } 
                    // Counting sum of goods with unique amounts
                    if ( range == 1 ){
                        //printf("%d. %s, %dx\n", index+1, Goods[index].Name, Goods[index].Amount);
                        sum += Goods[index].Amount;
                        PrintedGoods++;
                        // printf("Index-%d | Range-%d\n", index, range);
                    }
                    // Counting sum of multiple goods with same amount
                    else {
                        for ( int i = 0; i < range; i++){
                            //printf("%d.-%d. %s, %dx\n",index-range+2, index+1, Goods[index-i].Name, Goods[index-i].Amount);
                            sum += Goods[index-i].Amount;
                            PrintedGoods ++;
                            // printf("Index-%d | Range-%d\n", index, range);
                        }
                    }
                    
                    range = 1;
                    index ++;

                }

                printf("Nejprodavanejsi zbozi: prodano %d kusu\n", sum);

                break;
        }
    }

free(Goods);

return 0;   
}
