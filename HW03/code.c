#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int leapYearCounter (int year){
    return year / 4 + year / 400 - year / 100 - year / 4000;
}

int endHour ( int minute ){

    int jouly = 0;

    // Ulozene hodnoty v joulech v intervalu od 0-59-00
    int zmeny[60] = { 4, 5, 2, 3, 3, 1, 5, 4, 1, 6,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 7,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 4,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 5,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 5,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 5};


    // minuty
    for(int i = minute; i <= 60; i ++){
        jouly = jouly + zmeny[i];
        jouly += 200;
    }
   //printf("%lld\n", jouly);
    return jouly;
}

int endDay ( int hour ){

    int jouly = 0;

    // Ulozene hodnoty v joulech v intervalu od 0-59-00
    int zmeny[24] = { 4, 5, 2, 3, 3, 1, 5, 4, 1, 6,
                        4, 5, 2, 3, 3, 1, 5, 4, 1, 7,
                        4, 5, 2};

    // minuty
    for(int i = hour; i <= 24; i ++){
        jouly = jouly + zmeny[i];
        jouly += 12200;
    }
    //printf("%d\n", jouly);
    return jouly;
}

int isLeap ( int year) {
    if ( year % 4 == 0
    && ( year % 100 != 0 || year % 400 == 0 ) && ( year % 4000 != 0) ){
        return 1;
    }
    else {
        return 0;
    }
}

int dateToIndex(int day, int month, int year) {
    if ( year < 1600 
        || month < 1 
        || month > 12
        || day < 1){
            return 0;
    }

    long long n;
    int leap = isLeap(year);
    
    if ( (month == 1 && day > 31)
      || (month == 2 && leap == 0 && day > 28)
      || (month == 2 && leap == 1 && day > 29)
      || (month == 3 && day > 31)
      || (month == 4 && day > 30)
      || (month == 5 && day > 31)
      || (month == 6 && day > 30)
      || (month == 7 && day > 31)
      || (month == 8 && day > 31)
      || (month == 9 && day > 30)
      || (month == 10 && day > 31)
      || (month == 11 && day > 30)
      || (month == 12 && day > 31)){
          return 0;
      }
    if (leap == 1 && month > 2){
        day += 1;
    }
    switch ( month ) {
        case 1: n = day; break;
        case 2: n = day + 31; break;
        case 3: n = (day + 59); break;
        case 4: n = day + 90; break;
        case 5: n = day + 120; break;
        case 6: n = day + 151; break;
        case 7: n = day + 181; break;
        case 8: n = day + 212; break;
        case 9: n = day + 243; break;
        case 10: n = day + 273; break;
        case 11: n = day + 304; break;
        case 12: n = day + 334; break;
        default: return 0;
    }
    
    return n;
}

int energyConsumption ( int y1, int m1, int d1, int h1, int i1,
                        int y2, int m2, int d2, int h2, int i2, long long int * consumption )
{
    int leap1 = isLeap(y1);
    int leap2 = isLeap(y2);
    long long total =0;

    // Nespravne vstupy
    if ( y1 < 1600
      || y2 < 1600
      || m1 < 1 
      || m1 > 12
      || m2 < 1
      || m2 > 12
      || d1 < 1
      || d2 < 1
      || h1 < 0
      || h1 > 23
      || h2 < 0
      || h2 > 23
      || i1 < 0
      || i1 > 59
      || i2 < 0
      || i2 > 59)
      {
        return 0;
    }
    // platnost d1
    if ( (m1 == 1 && d1 > 31)
      || (m1 == 2 && leap1 == 0 && d1 > 28)
      || (m1 == 2 && leap1 == 1 && d1 > 29)
      || (m1 == 3 && d1 > 31)
      || (m1 == 4 && d1 > 30)
      || (m1 == 5 && d1 > 31)
      || (m1 == 6 && d1 > 30)
      || (m1 == 7 && d1 > 31)
      || (m1 == 8 && d1 > 31)
      || (m1 == 9 && d1 > 30)
      || (m1 == 10 && d1 > 31)
      || (m1 == 11 && d1 > 30)
      || (m1 == 12 && d1 > 31))
      {
          return 0;
    }
    // platnost d2
    if ( (m2 == 1 && d2 > 31)
      || (m2 == 2 && leap2 == 0 && d2 > 28)
      || (m2 == 2 && leap2 == 1 && d2 > 29)
      || (m2 == 3 && d2 > 31)
      || (m2 == 4 && d2 > 30)
      || (m2 == 5 && d2 > 31)
      || (m2 == 6 && d2 > 30)
      || (m2 == 7 && d2 > 31)
      || (m2 == 8 && d2 > 31)
      || (m2 == 9 && d2 > 30)
      || (m2 == 10 && d2 > 31)
      || (m2 == 11 && d2 > 30)
      || (m2 == 12 && d2 > 31))
      {
          return 0;
    } 
    // Osetreni time2 > time 1
    if (y2 < y1){
        return 0;
    }
    else if (y2 == y1){
        if ( m2 < m1){
            return 0;
            //printf("Mesice\n");
        }
        else if ( m2 == m1){
            if ( d2 < d1){
                //printf("Dny");
                return 0;
            }
            else if ( d2 == d1){
                if ( h2 < h1 ){
                    //printf("Hodiny");
                    return 0;
                }
                else if ( h1 == h2 ){
                    if ( i2 < i1){
                        printf("Minuty");
                        return 0;
                    }
                    /*
                    else if (i2 == i1){
                        total = 0;
                        return 0;
                    }*/
                }
            }
        }
    }


    int konst_day = 292886;


    ///////////////////////////////////////////////////
    // Minutes
    long long i1_1 = endHour(i1);
    long long i2_1 = endHour(i2);

    long long totalM = i1_1 - i2_1;
    //////////////////////////////////////////////////////
    // Hours
    long long h1_1 = endDay(h1);
    long long h2_1 = endDay(h2);

    long long totalH = h1_1 + (konst_day-h2_1);
    //////////////////////////////////////////////////////
    //Days
    long long d1_1 = dateToIndex(d1, m1, y1);
    long long d2_1 = dateToIndex(d2, m2, y2);
    
    long long DaysCounter = d2_1 - d1_1 -1;

    if ( isLeap(y2) == 1 && y1 != y2 ){
        DaysCounter -= 1;
    }
    else if (isLeap(y1) == 1 && y1 != y2){
        DaysCounter += 1;
    }
    if ((isLeap(y1) == 1 && isLeap(y2) == 1)&& y1 != y2){
        DaysCounter +=1;
    }
    long long totalD = DaysCounter*konst_day;

    ////////////////////////////////////////////////////////
    // Years

    long long lpy1 = leapYearCounter(y1);
    long long lpy2 = leapYearCounter(y2);

    long long nlpy1 = y1 - lpy1;
    long long nlpy2 = y2 - lpy2;        
   
    long long totalY1 = 365*nlpy1 + 366*lpy1;
    long long totalY2 = 365*nlpy2 + 366*lpy2;

    printf("total Y1 - %lld\n", totalY1);
    printf("total Y2 - %lld\n", totalY2);

    long long YearsInDays = totalY2 - totalY1;

    long long totalYears = YearsInDays * konst_day;
    ////////////////////////////////////////////////////////
    // Just to be sure
    
    printf("%lld - %lld = %lld\n", d2_1, d1_1, DaysCounter);
    printf("Dny - %lld\n", totalD);
    printf("Hodiny - %lld\n", totalH);
    printf("Minuty - %lld\n", totalM);
    
   //////////////////////////////////////////////////////////
   // Final sum

    total = totalM + totalH + totalD + totalYears;
    *consumption = total;
    printf("%lld\n", *consumption);
    return 1;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int consumption = 0;

//energyConsumption ( 1968, 5, 19, 6, 55, 2092, 5, 18, 21, 15, &consumption );

  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  1, &consumption ) == 1
           && consumption == 204LL );
  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  1, 18, 45, &consumption ) == 1
           && consumption == 67116LL );
  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  2, 11, 20, &consumption ) == 1
           && consumption == 269497LL );
  assert ( energyConsumption ( 2021,  1,  1, 13, 15,
                               2021, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81106033LL );
  assert ( energyConsumption ( 2024,  1,  1, 13, 15,
                               2024, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81398919LL );
 
  assert ( energyConsumption ( 2021, 10,  1,  0,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 146443LL );
  assert ( energyConsumption ( 2021, 10,  1,  0, 15,
                               2021, 10,  1,  0, 25, &consumption ) == 1
           && consumption == 2035LL );
                     
  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 0LL );
  assert ( energyConsumption ( 2400,  2, 29, 12,  0,
                               2400,  2, 29, 12,  0, &consumption ) == 1
           && consumption == 0LL );         

 
  assert ( energyConsumption ( 2021, 11,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2021, 10, 32, 12,  0,
                               2021, 11, 10, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2100,  2, 29, 12,  0,
                               2100,  2, 29, 12,  0, &consumption ) == 0 );
                  
 assert ( energyConsumption ( 1900,  1,  1, 13, 15,
                               1900, 10,  5, 11, 20, &consumption ) == 1
            && consumption == 81106033LL );
    
  return 0;
}
#endif /* __PROGTEST__ */
