#include <stdio.h>

int main ( void ){

    int num, value;

    printf("ml' nob:\n");
    value = scanf("%d", &num);

    if (value != 1){
        printf("luj\n");
        return 1;
    }
    if (num > 5 || num < 1){
        printf("luj\n");
        return 1;
    }
    if (num == 1){
        printf("Qapla'\n");
        printf("noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
    }
    if (num == 2){
        printf("Qapla'\n");
        printf("Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
    }
    if (num == 3){
        printf("Qapla'\n");
        printf("qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
    }
    if (num == 4){
        printf("Qapla'\n");
        printf("Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
    }
    if (num == 5){
        printf("Qapla'\n");
        printf("leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
    }

    return 0;

}