#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*Comp)(const void *,const void *);

typedef struct{
    char m_Name[101];
    int m_Amount;
}TItem;

typedef struct{
    TItem * m_Array;
    int m_Count;
    int m_Cap;
}TProducts;

int betterCmp(const char *a, const char *b){
    if(a[0] == b[0]) return strcmp(a,b);
    if(a[0] < b[0]) return -1;
    return 1;
}
int binarySearch(TProducts * products, const char * item, int * index){
    if(products->m_Count == 0){
        *index = -1;
        return 0;
    }
    if(betterCmp(item, products->m_Array[0].m_Name) < 0){
        *index = -1;
        return 0;
    }
    int left = 0;
    int right = products->m_Count -1;
    int mid;
    while(left <= right){
        mid = (left + right)/2;
        int cmp = betterCmp(products->m_Array[mid].m_Name, item);
        if(cmp == 0){
            *index = mid;
            return 1;
        }
        else if(cmp < 0){
            left = mid + 1;
            *index = mid;
        }
        else{
            right = mid - 1;
        }
    }
    return 0;
}
void arrPush(TProducts * products, char * item, int amount, int index){
    if(products->m_Count >= products->m_Cap){
        products->m_Cap = products->m_Cap*2 +4;
        products->m_Array = (TItem *) realloc(products->m_Array, products->m_Cap*sizeof(TItem));
    }
    TItem tmp = {};
    strcpy(tmp.m_Name, item);
    tmp.m_Amount = amount;
    int insPos = index +1;
    for(int pos = products->m_Count -1; pos >= insPos; pos--){
        products->m_Array[pos + 1] = products->m_Array[pos];
    }
    products->m_Array[insPos] = tmp;
    products->m_Count++;
}
void addProduct(TProducts * products, char * item, int amount){
    int index;
    int found = binarySearch(products, item, &index);
    if(found){
        products->m_Array[index].m_Amount += amount;
        printf("Pridano.\n");
        return;
    }
    arrPush(products, item, amount, index);
    printf("Vytvoreno.\n");
    return;
}
void printArr(TProducts * products){
    for(int i = 0; i < products->m_Count; i++){
        printf("%s %d\n", products->m_Array[i].m_Name, products->m_Array[i].m_Amount);
    }
}

void delProduct(TProducts * products, char * item, int amount){
    int index;
    int found = binarySearch(products, item, &index);
    if(found){
        if(products->m_Array[index].m_Amount >= amount){
            products->m_Array[index].m_Amount -= amount;
            printf("Odebrano.\n");
            return;
        }
        printf("Nedostatek zbozi.\n");
        return;
    }
    printf("Nedostatek zbozi.\n");
    return;
}
void findProducts(TProducts * products, char * item){
    int index;
    int found = binarySearch(products, item, &index);
    if(found){
        printf("Kusu: %d.\n", products->m_Array[index].m_Amount);
        return;
    }
    printf("Kusu: 0.\n");
}
int main(void){
    char sign;
    int res;
    TProducts products = {};
    printf("Prikazy.\n");
    while(scanf(" %c", &sign) == 1){
        char tmp[102];
        int amount;
        switch(sign){
            case '+':
                res = scanf(" %101s %d", tmp, &amount);
                if(res != 2 || strlen(tmp) > 100 || amount < 1){
                    printf("Nespravny vstup.\n");
                    return 1;
                }
                addProduct(&products, tmp, amount);
                break;
        
            case '-':
                res = scanf(" %101s %d", tmp, &amount);
                if(res != 2 || strlen(tmp) > 100 || amount < 1){
                    printf("Nespravny vstup.\n");
                    return 1;
                }
                delProduct(&products, tmp, amount);
                break;
            case '?':
                res = scanf(" %101s", tmp);
                if(res != 1 || strlen(tmp) > 100){
                    printf("Nespravny vstup.\n");
                    return 1;
                }
                findProducts(&products, tmp);
                break;
            default:
                printf("Nespravny vstup.\n");
                return 1;
        }
        
    }
    return 0;
}
