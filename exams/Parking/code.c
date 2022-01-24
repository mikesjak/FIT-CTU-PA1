#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TPlot {
    int patro;
    int misto;
    int obsazenost;
    char znacka[11];
} TPlot;

int main ( void ) {

    int patra = 0,
        mista = 0;

    int pocetmist = 0;

    printf("Velikost:\n");
    if ( scanf (" %d %d", &patra, &mista) != 2
        || patra <= 0
        || mista <= 0 ){
        printf("Spatny vstup.\n");
        return 1;
    }

    TPlot * parkoviste = (TPlot*) malloc (patra*mista * sizeof(TPlot));
    
    for (int i = 0; i < patra; i++) {
        for (int j = 0; j <= mista; j++){
            parkoviste[pocetmist].patro = i;
            parkoviste[pocetmist].misto = j;
            pocetmist++;
        }
    }

    char sign, tmpZnacka[12];
    int tmpPatro, tmpMisto;
    int magie;

    while (scanf(" %c", &sign) == 1){
        switch (sign) {
            default:
                break;
            case '+':
                
                if (scanf(" %d %d", &tmpPatro, &tmpMisto) != 2
                 || tmpPatro >= patra || tmpPatro < 0
                 || tmpMisto > mista || tmpMisto < 0){
                    printf("Nespravny vstup.\n");
                    return 1;
                 }

                if (scanf(" %11s", tmpZnacka) != 1
                 || strlen(tmpZnacka) > 10){
                     printf("Nespravny vstup.\n");
                    return 1;
                }

                magie = tmpPatro * (mista+1) + tmpMisto ;

                if (parkoviste[magie].obsazenost != 1){
                    strcpy(parkoviste[magie].znacka, tmpZnacka);
                    parkoviste[magie].obsazenost = 1;
                    printf("OK.\n");
                }
                else {
                    printf("Obsazeno %s\n", parkoviste[magie].znacka);
                }
                break;
            case '-':

                int flag = 0;

                if (scanf(" %11s", tmpZnacka) != 1
                 || strlen(tmpZnacka) > 10){
                     printf("Nespravny vstup.\n");
                    return 1;
                }
                for (int i = 0; i < pocetmist; i++){
                    if ( strcmp(parkoviste[i].znacka, tmpZnacka) == 0 ){
                        flag = 1;
                        printf("Ok.\n");
                        parkoviste[i].obsazenost = 0;
                        break;
                    }
                }
                if (flag != 1){
                    printf("Nenalezen.\n");
                }
                break;
        }
    }

    free(parkoviste);
    return 0;
}
