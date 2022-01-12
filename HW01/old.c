#include <stdio.h>
#include <math.h>

#define EPS 1e-6

// porovnavani dvojice geometrickych obrazcu
// - obvod
// - obsah
// Trojuhelnik - T a 3 cifry
// Obdelnik - R a 2 cifry
// Ctverec - S a 1 cifra

int main ( void ){
    char ob1;
    char ob2;

    double a1=0.1, b1=0.1, c1=0.1;
    double a2=1, b2=1, c2=1;
    double o1=1, s1=1, o2=1, s2=1;
    double o12=1, o22=1;
    double ac1=1, ab1=1, bc1=1,
           ac2=1, ab2=1, bc2=1;
    int value1=0, value2=0;

// Spravne inputy 1
    printf("Obrazec #1\n");
    scanf(" %c[]", &ob1);
    
    if ( ob1 == 'T'){
        value1 = scanf(" %lf %lf %lf", &a1, &b1, &c1);
    }
    if ( ob1 == 'R'){
        value1 = scanf(" %lf %lf", &a1, &b1);
    }
    if ( ob1 == 'S'){
        value1 = scanf(" %lf", &a1);
    }
////
///printf("%lf %lf %lf", a1, b1, c1);
///printf("%lf %lf %lf", a2, b2, c2);
// Chybove inputy 1
    // spatny nazev obrazce
    if ( ob1 != 'T' && ob1 != 'R' && ob1 != 'S'){
        printf("Nespravny vstup.\n");
        return 1;
    }
    // value of scanf
    if ( ob1 == 'T' && value1 != 3){
        printf("Nespravny vstup.\n");
        return 1;
    }
    if ( ob1 == 'R' && value1 != 2){
        printf("Nespravny vstup.\n");
        return 1;
    }
    if ( ob1 == 'S' && value1 != 1){
        printf("Nespravny vstup.\n");
        return 1;
    }
    // osetreni velikosti stran
    if ( a1 <= 0 || b1 <= 0 || c1 <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }
    //  - resit pomery stran trojuhelniku
    if (ob1 == 'T' ){
        ab1 = a1+b1;
        ac1 = a1+c1;
        bc1 = b1+c1;
        if ( fabs ( ab1-c1 ) <= EPS * ( fabs( ab1 ) + fabs( c1 )) ||
             fabs ( ac1-b1 ) <= EPS * ( fabs( ac1 ) + fabs( b1 )) ||
             fabs ( bc1-a1 ) <= EPS * ( fabs( bc1 ) + fabs( a1 )) ){
        printf("Nespravny vstup.\n");
        return 1;
        }
    }
    //  - resit rovnost stran u obdelniku
    if ( ob1 == 'R' && fabs (a1 - b1) <= EPS * ( fabs ( a1) + fabs ( b1 ))){
        printf("Nespravny vstup.\n");
        return 1;
    }
// Spravne inputy 2
    printf("Obrazec #2\n");
    scanf(" %c[]", &ob2);

     if ( ob2 == 'T'){
        value2 = scanf(" %lf %lf %lf", &a2, &b2, &c2);
    }
    if ( ob2 == 'R'){
        value2 = scanf(" %lf %lf", &a2, &b2);
    }
    if ( ob2 == 'S'){
        value2 = scanf(" %lf", &a2);
    }

// Chybove inputy 2
    // spatny nazev obrazce
    if ( ob2 != 'T' && ob2 != 'R' && ob2 != 'S'){
        printf("Nespravny vstup.\n");
        return 1;
    }
    // value of scanf
    if ( ob2 == 'T' && value2 != 3){
        printf("Nespravny vstup.\n");
        return 1;
    }
    if ( ob2 == 'R' && value2 != 2){
        printf("Nespravny vstup.\n");
        return 1;
    }
    if ( ob2 == 'S' && value2 != 1){
        printf("Nespravny vstup.\n");
        return 1;
    }
    // osetreni velikosti stran
    if ( a2 <= 0 || b2 <= 0 || c2 <= 0){
        printf("Nespravny vstup.\n");
        return 1;
    }
    //  - resit pomery stran trojuhelniku
    if (ob2 == 'T' ){
        ab2 = a2+b2;
        ac2 = a2+c2;
        bc2 = b2+c2;
        if ( fabs ( ab2-c2 ) <= EPS * ( fabs( ab2 ) + fabs( c2 )) ||
             fabs ( ac2-b2 ) <= EPS * ( fabs( ac2 ) + fabs( b2 )) ||
             fabs ( bc2-a2 ) <= EPS * ( fabs( bc2 ) + fabs( a2 )) ){
        printf("Nespravny vstup.\n");
        return 1;
        }
    }
    //  - resit rovnost stran u obdelniku
    if ( ob2 == 'R' && fabs (a2 - b2) <= EPS * ( fabs ( a2) + fabs ( b2 ))){
        printf("Nespravny vstup.\n");
        return 1;
    }
// vypoces obsahu a obvodu 1
    if ( ob1 == 'T' ){
        o1 = a1 + b1 + c1;
        o12 = o1 / 2;
        s1 = sqrt(o12*(o12-a1)*(o12-b1)*(o12-c1));
    }
    if ( ob1 == 'R'){
        o1 = (2*a1+2*b1);
        s1 = a1*b1;
    }
    if ( ob1 == 'S'){
        o1 = 4*a1;
        s1 = a1*a1;
    }
// vypocet obvodu a obsahu 2
    if ( ob2 == 'T' ){
        o2 = a2 + b2 + c2;
        o22 = o2 / 2;
        s2 = sqrt(o22*(o22-a2)*(o22-b2)*(o22-c2));
    }
    if ( ob2 == 'R'){
        o2 = (2*a2+2*b2);
        s2 = a2*b2;
    }
    if ( ob2 == 'S'){
        o2 = 4*a2;
        s2 = a2*a2;
    }
// Pro moje uklidneni
//  printf("%c %lf %lf %lf\n", ob1, a1, b1, c1);
//  printf("%lf %lf\n", o1, s1);
//  printf("%c %lf %lf %lf\n", ob2, a2, b2, c2);
//  printf("%lf %lf\n", o2, s2);
// obvody


    if ( (o1 - o2) > EPS * ( o1 + o2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obvod: trojuhelnik #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obvod: trojuhelnik #1 > obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obvod: trojuhelnik #1 > ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obvod: ctverec #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obvod: ctverec #1 > obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obvod: ctverec #1 > ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obvod: obdelnik #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obvod: obdelnik #1 > obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obvod: obdelnik #1 > ctverec #2\n");
        }
    }
    else if (fabs( o1 - o2 ) <= EPS * ( o1 + o2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obvod: trojuhelnik #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obvod: trojuhelnik #1 = obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obvod: trojuhelnik #1 = ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obvod: ctverec #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obvod: ctverec #1 = obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obvod: ctverec #1 = ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obvod: obdelnik #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obvod: obdelnik #1 = obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obvod: obdelnik #1 = ctverec #2\n");
        }
    }
    else if ( (o2 - o1) > EPS * (o1 + o2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obvod: trojuhelnik #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obvod: trojuhelnik #1 < obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obvod: trojuhelnik #1 < ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obvod: ctverec #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obvod: ctverec #1 < obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obvod: ctverec #1 < ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obvod: obdelnik #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obvod: obdelnik #1 < obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obvod: obdelnik #1  ctverec #2\n");
        }
    }
// obsahy
    if ( (s1 - s2) > EPS * ( s1 + s2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obsah: trojuhelnik #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obsah: trojuhelnik #1 > obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obsah: trojuhelnik #1 > ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obsah: ctverec #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obsah: ctverec #1 > obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obsah: ctverec #1 > ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obsah: obdelnik #1 > trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obsah: obdelnik #1 > obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obsah: obdelnik #1 > ctverec #2\n");
        }
    }
    else if ( fabs(s1-s2) <= EPS * ( s1 + s2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obsah: trojuhelnik #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obsah: trojuhelnik #1 = obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obsah: trojuhelnik #1 = ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obsah: ctverec #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obsah: ctverec #1 = obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obsah: ctverec #1 = ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obsah: obdelnik #1 = trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obsah: obdelnik #1 = obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obsah: obdelnik #1 = ctverec #2\n");
        }
    }
    else if ( (s2 - s1) > EPS * ( s1 + s2 )){
        if ( ob1 == 'T' && ob2 == 'T'){
            printf("Obsah: trojuhelnik #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'R'){
            printf("Obsah: trojuhelnik #1 < obdelnik #2\n");
        }
        if ( ob1 == 'T' && ob2 == 'S'){
            printf("Obsah: trojuhelnik #1 < ctverec #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'T'){
            printf("Obsah: ctverec #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'R'){
            printf("Obsah: ctverec #1 < obdelnik #2\n");
        }
        if ( ob1 == 'S' && ob2 == 'S'){
            printf("Obsah: ctverec #1 < ctverec #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'T'){
            printf("Obsah: obdelnik #1 < trojuhelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'R'){
            printf("Obsah: obdelnik #1 < obdelnik #2\n");
        }
        if ( ob1 == 'R' && ob2 == 'S'){
            printf("Obsah: obdelnik #1  ctverec #2\n");
        }
    }
    return 0;
}
