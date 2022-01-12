#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int wordsCompare (char *** words1, char *** words2, int WCa, int WCb) {

  int value = 0;
  int flag = 0;

  for (int i = 0; i < WCa; i++){

    for (int j = 0; j < WCb; j++){

      value = strcmp((*words1)[i],(*words2)[j]);
      //printf("Porovnavam %s s %s = %d | %d\n", (*words1)[i],(*words2)[j], value, flag );
      if (value == 0){
        flag = 1;
        break;
      }
    }
    if (flag == 0){
      //printf("Stringy nejsou stejne.\n");
      return 0;
    }
  flag = 0;
  }
  //printf("=========================\n");
  for (int i = 0; i < WCb; i++){
    for (int j = 0; j < WCa; j++){
      value = strcmp( (*words2)[i],(*words1)[j] );
      //printf("Porovnavam %s s %s = %d\n", (*words2)[i],(*words1)[j], value);
      if (value == 0){
        flag = 1;
        break;
      }
    }
    if (flag == 0){
      //printf("Stringy nejsou stejne.\n");
      return 0;
    }
    flag = 0;
  }
  return 1;
}

void wordSeparator( const char * a, const char * b, int * WCa, int * WCb, char *** words1, char *** words2 ) {

  char tmp[1000000]={};
  int WCaa = 0;
  int WCbb = 0;
  int index = 0;
  int aLenght = strlen(a);
  int bLenght = strlen(b);
  
  
  for (int i = 0; i < aLenght; i++) {
    int let = isalpha(a[i]);
    //printf("%d - ", let);
    if ( let != 0 ){
      tmp[index]=tolower(a[i]);
      //printf("%c", tmp[index]);
      index++;
      if (i == (aLenght-1)) {
        //printf(" - WC = %d\n", WCaa);
        tmp[index+1]='\0';
        WCaa++;
        * words1 = (char **) realloc( *words1, (WCaa * sizeof(**words1) + 4) );
        (*words1)[WCaa-1] = (char *) malloc((strlen(tmp)+10) * sizeof(char));
        strcpy((*words1)[WCaa-1], tmp);
        memset(tmp, 0, strlen(tmp));
        index = 0;
      }
    } 
   // if(i!= 0) printf("let = %d,i= %d, isalpha_pred = %d\n",let, i,  isalpha(a[i-1]));
    if (let == 0 && i != 0 && isalpha(a[i-1]) != 0) {
      //printf("Prisel jsem do for cyclu\n");
      //printf(" - WC = %d\n", WCaa);
      tmp[index]='\0';
      WCaa += 1;
      * words1 = (char **) realloc( *words1, (WCaa * sizeof(**words1) + 4));
      (*words1)[WCaa-1] = (char *) malloc( (strlen(tmp)+10) * sizeof(char) );
      strcpy((*words1)[WCaa-1], tmp);
      memset(tmp,0,strlen(tmp));
      index = 0;
    }
  }
  //printf("=================================================\n");

  for (int i = 0; i < bLenght; i++){

    int let = isalpha(b[i]);

    if( let != 0 ){
      tmp[index]=tolower(b[i]);
      //printf("%c", tmp[index]);
      index++;
      if ( i == (bLenght-1)){
        //printf(" - WC = %d\n", WCbb);
        tmp[index+1]='\0';
        WCbb += 1;
        * words2 = (char **) realloc( *words2, (WCbb * sizeof(**words2)) + 4);
        (*words2)[WCbb-1] = (char *) malloc((strlen(tmp)+20) * sizeof(char));
        strcpy((*words2)[WCbb-1], tmp);
        memset(tmp, 0, strlen(tmp));
        index = 0;
      }
    }
    if (let == 0 && i != 0 && isalpha(b[i-1]) != 0){
      //printf(" - WC = %c\n", WCbb);
      tmp[i]='\0';
      WCbb += 1;
      * words2 = (char**) realloc( *words2, (WCbb * sizeof(**words2) ) + 4);
      (*words2)[WCbb-1] = (char *) malloc((strlen(tmp)+20) * sizeof(char));
      strcpy((*words2)[WCbb-1],tmp);
      memset(tmp, 0, strlen(tmp));
      index = 0;
    }
  }
  *WCa = WCaa;
  *WCb = WCbb;
  //printf("============");
  
}


int sameWords ( const char * a, const char * b )
{
  int WCa = 0,
      WCb = 0;
  int compare = 0;
  char ** words1 = (char **) malloc((WCa + 1) * sizeof(char*));
  char ** words2 = (char **) malloc((WCb + 1) * sizeof(char*));

  wordSeparator( a, b, &WCa, &WCb, &words1, &words2);

  compare = wordsCompare(&words1, &words2, WCa, WCb);
  if (compare == 1){
    printf("Stringy sjou stejne\n");
  }

  printf("returnuju %d\n", compare);
  if (compare == 0){
    for (int i = 0; i < WCa; i++){
      free(words1[i]);
    }
    for (int j = 0; j < WCb; j++){
      free(words2[j]);
    }
    free(words1);
    free(words2);
    return 0;
  }
  if (compare == 1){
    for (int i = 0; i < WCa; i++){
      free(words1[i]);
    }
    for (int j = 0; j < WCb; j++){
      free(words2[j]);
    }
    free(words1);
    free(words2);
    return 1;
  }
  return 0;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  assert ( sameWords ( "Hello students.", "HELLO studEnts!" ) == 1 );
  assert ( sameWords ( " He said 'hello!'", "'Hello.' he   said." ) == 1 );
  assert ( sameWords ( "He said he would do it.", "IT said: 'He would do it.'" ) == 1 );
  assert ( sameWords ( "one two three", "one two five" ) == 0 );
  return 0;
}
#endif /* __PROGTEST__ */
