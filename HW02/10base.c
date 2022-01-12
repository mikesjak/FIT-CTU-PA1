#include <stdio.h>
#include <math.h>

int digits(int sekvence, int soustava){
    if (sekvence != 0){
        return floor((int)abs(log10(sekvence) / log10(soustava) + 1e-7) + 1);
    }
    else{
        return 1;
    }
}

int konvertorSoustav(int cislo, int soustava){
    int posun = 0, zbytek = 0;

    char prevedeneCislo[64];
    char znaky[37] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    while (cislo > 0){
        zbytek = cislo % soustava;
        cislo = (cislo - zbytek) / soustava;
        prevedeneCislo[posun] = znaky[zbytek];
        posun++;
    }
    posun = posun -1;
    posun = posun * (-1);
    if (posun > 0){
        printf("0\n");
    }
    else{
        for (int i = fabs(posun); i >= 0; i -= 1){
            printf("%c", prevedeneCislo[i]);
            if (i == 0){
                printf("\n");
            }
        }
    }
    //////////////////////////////////////////////////
    /* reset promennych
    zbytek = 0;
    cislo = 0;
    soustava = 0;
    posun = 0;
    */

    return 0;
}

int main(void){

    int sekvence, soustava = 0;

    printf("Pozice a soustava:\n");
    while (scanf(" %d %d", &sekvence, &soustava) == 2){
        if (soustava < 2 || soustava > 36){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (sekvence < 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        if (sekvence == 0){
            printf("0\n");
            printf("^\n");
        }

        else if (sekvence > 0){
            int a = 0;
            int velikostA = 0;
            while (sekvence > velikostA){
                a += 1;
                velikostA = velikostA + digits(a, soustava);
            }
            int velikostcifry = digits(a, soustava);
            int rozdil = velikostA - sekvence;
            int posun = velikostcifry - rozdil;

            if (soustava == 10){
                printf("%d\n", a);
            }
            else{
                konvertorSoustav(sekvence, soustava);
            }

            int i;

            for (i = posun - 1; i > 0; i -= 1){
                printf(" ");
            }
            printf("^\n");

            //////////////////////////////////////////////
            // Reset promennych;
            sekvence = 0;
            velikostcifry = 0, velikostA = 0;
            rozdil = 0, posun = 0;
            a = 0, i = 0;
        }
    }
    if (soustava == 0){
        printf("Nespravny vstup.\n");
        return 1;
    }

    if (!feof(stdin)){
        printf("Nespravny vstup.\n");
        return 1;
    }
    return 0;
}
