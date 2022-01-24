#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TCar {
    int m_Time;
    char m_Sign[12];
} TCar;

void addCar ( int time, char * sign, TCar * logs, int count ) {
    if (count == 0){
        logs[0].m_Time = time;
        strcpy(logs[0].m_Sign, sign);
        return;
    }
    for ( int i = 0; i <= count; i++ ){
        if ( strcmp(sign, logs[i].m_Sign) == 0 ){
            printf("Auto se stejnou znackou uz tu je.\n");
            return;
        }
    }
    logs[count+1].m_Time = time;
    strcpy(logs[count+1].m_Sign,sign);
}

int takeCar ( int time, char * sign, TCar * logs, int count ) {

    int result = 0;

    for (int i = 0; i <= count; i++) {
        if ( strcmp(sign, logs[i].m_Sign) == 0 ){
            result = time-logs[i].m_Time;
            printf("RZ: %s, ", logs[i].m_Sign);
            memset(logs[i].m_Sign, 0, strlen(logs[i].m_Sign));
            logs[i].m_Time = -1;
            if (result < 0) {
                printf("Nespravny vstup.\n");
                return -1;
            }
            return result;
        }
    }
    printf("Auto nenalezeno.\n");
    return -1;
}

void prizeCounter ( int time ) {
    int prize = -10;

    if ( time <= 30 && time >= 0 ){
        prize = 0;
    }
    else if ( time <= 60 && time > 30 ){
        prize = 30;
    }
    else if ( time > 60 && time < 24*60 ){
        prize = time/60 * 40;
        if (prize % 60 != 0){
            prize += 40;
        }
    }
    else if ( time > 24*60 ) {
        prize = time/(24*60) * 1000;
        if (prize % (24*60) != 0){
            prize += 1000;
        }
    }
    if ( prize >= 0 ){
        printf("cena: %d\n", prize);
    }
    
}

int main ( void ) {

    TCar * logs = NULL;

    int capacity = 0,
        count = 0;

    int hours, minutes,
        lastH = 0, lastM = 0;
    char func;
    char tmpSign[12];
    int time = 0;
    int stayed;

    printf("Log:\n");

    while ( scanf("%d:%d %c ", &hours, &minutes, &func) == 3) {

        if ( count+2 >= capacity ) {
            capacity = (capacity * 2) + 4;
            logs = (TCar*) realloc (logs, capacity * sizeof(logs[0]) + 100 );
        }

        if ( lastH >= hours && lastM > minutes ) {
            printf("Nesprávný vstup.\n");
            free(logs);
            return 1;
        }

        switch (func) {
            case '+':
                scanf(" %11s", tmpSign);
                if (strlen(tmpSign) >= 11){
                    printf("Nesprávný vstup.\n");
                    free(logs);
                    return 1;
                }
                addCar( (60*hours + minutes), tmpSign, logs, count );
                count ++;
                printf("OK\n");
                break;
            case '-':
                scanf(" %11s", tmpSign);
                if (strlen(tmpSign) >= 11){
                    printf("Nesprávný vstup.\n");
                    free(logs);
                    return 1;
                }
                stayed = takeCar( (60*hours + minutes)+time, tmpSign, logs, count );
                prizeCounter(stayed);
                break;
            case '=':
                if ( hours != 0 || minutes != 0 ) {
                    printf("Nesprávný vstup.\n");
                    free(logs);
                    return 1;
                }
                lastH = 0;
                lastM = 0;
                time += 24*60;
                break;
            default:
                printf("Nesprávný vstup.\n");
                free(logs);
                return 1;
        }
        
    }
    count = 0;
    for (int i = 0; i <= count; i ++) {
        if (logs[i].m_Time == -1) {
            count ++;
        }
    }
    printf("Pocet automobilu v garazi: %d\n", count);
    return 0;
}
