#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
 
typedef struct TItem
{
    struct TItem * m_Next;
    char           m_Digit;
} TITEM;
 
TITEM * createItem ( char digit, TITEM * next )
{
    TITEM * n = (TITEM *) malloc (sizeof ( *n ));
    n -> m_Digit = digit;
    n -> m_Next = next;
    return n;
}
 
void deleteList (TITEM * l)
{
    while (l)
    {
        TITEM * tmp = l -> m_Next;
        free (l);
        l = tmp;
    }
}
#endif /* __PROGTEST__ */
 
int checkNumber ( TITEM* num ){
    if (num == NULL) return 0;
    while(num){
        if (num->m_Digit > '9' || num->m_Digit < '0'){
            return 0;
        }
        num = num->m_Next;
    }
    return 1;
}

int LLlenght (TITEM * list) {
    int lenght = 0;
    while (list){
        lenght ++;
        list = list->m_Next;
    }
    return lenght;
}
int cmpLL ( TITEM * listA, TITEM * listB) {
    int lenghtA, lenghtB;

    lenghtA = LLlenght(listA);
    lenghtB = LLlenght(listB);
    char * numberA = (char *) malloc (sizeof(char) * (lenghtA + 2) );
    char * numberB = (char *) malloc (sizeof(char) * (lenghtB + 2) );

    printf("LenA = %d, lenB = %d\n", lenghtA, lenghtB);

    for ( int i = lenghtA-1; i >= 0; i-- ){
        numberA[i]=listA->m_Digit;
        listA = listA->m_Next;
    }
    numberA[lenghtA] = '\0';
    printf("%s\n", numberA);
    for ( int i = lenghtB-1; i >= 0; i-- ){
        numberB[i]=listB->m_Digit;
        listB = listB->m_Next;
    }
    numberB[lenghtB] = '\0';
    printf("%s\n", numberB);
    if (strcmp(numberA,numberB) >= 0) {
        free(numberA);
        free(numberB);
        return 1;
    }
    free(numberA);
    free(numberB);
    return -1;
}

TITEM * maxOf (TITEM ** x, int nr)
{
    int value;
    for (int j = 0; j < nr; j++){
        value = checkNumber(x[j]);
        printf("val = %d\n", value);
        if ( value != 1) return NULL;
    }


    TITEM * max = x[0];
    for (int i = 1; i < nr; i++){
        if (cmpLL(max, x[i]) != 1){
            max = x[i];
            printf("menim max na %d", i);
        }
    }

    return max;
}
 
#ifndef __PROGTEST__
int main (int argc, char * argv [])
{
    TITEM * a[5];
 
    a[0] = createItem ( '4',
            createItem ( '3',
             createItem ( '2',
              createItem ( '1', NULL ))));
    a[1] = createItem ( '2',
            createItem ( '3',
             createItem ( '4',
              createItem ( '5', NULL))));
    assert ( maxOf ( a, 2 ) == a[1] );
    deleteList( a[0] );
    deleteList( a[1] );
 
    a[0] = createItem ( '0',
            createItem ( '0',
             createItem ( '0',
              createItem ( '1', NULL ))));
    a[1] = createItem ( '2',
            createItem ( '0',
             createItem ( '0',
              createItem ( '1', NULL ))));
    a[2] = createItem ( '1',
            createItem ( '0',
             createItem ( '0',
              createItem ( '1', NULL))));
    a[3] = createItem ( '2',
            createItem ( '0',
             createItem ( '0',
              createItem ( '1',
               createItem ( '0',
                createItem ( '0', NULL ))))));
    assert ( maxOf ( a, 4 ) == a[1] );
    deleteList ( a[0] );
    deleteList ( a[1] );
    deleteList ( a[2] );
    deleteList ( a[3] );
 
    a[0] = createItem ( '1',
            createItem ( '0',
             createItem ( '0',
              createItem ( '0',
               createItem ( '0',
                createItem ( '0', NULL ))))));
    a[1] = createItem ( '0',
            createItem ( '0',
             createItem ( '1', NULL )));
    a[2] = createItem ( '1',
            createItem ( '0',
             createItem ( '0',
              createItem ( '0',
               createItem ( '0',
                createItem ( '9', NULL ))))));
    a[3] = createItem ( '0',
            createItem ( '0',
             createItem ( '0',
              createItem ( '0',
               createItem ( '0',
                createItem ( '0',
                 createItem ( '0',
                  createItem ( '0',
                   createItem ( '0',
                    createItem ( '0',
                     createItem ( '0',
                      createItem ( '0',
                       createItem ( '0',
                        createItem ( '0',
                         createItem ( '0', NULL )))))))))))))));
    assert ( maxOf (a, 4) == a[2] );
    deleteList ( a[0] );
    deleteList ( a[1] );
    deleteList ( a[2] );
    deleteList ( a[3] );
 
    a[0] = createItem ( '0',
            createItem ( '0',
             createItem ( '0',
              createItem ( '0',
               createItem ( '0',
                createItem ( '0',
                 createItem ( '0',
                  createItem ( '0',
                   createItem ( '0',
                    createItem ( '0',
                     createItem ( '0',
                      createItem ( '0',
                       createItem ( '0',
                        createItem ( '0',
                         createItem ( '0',
                          createItem ( '0',
                           createItem ( '0',
                            createItem ( '0',
                             createItem ( '0',
                              createItem ( '0',
                               createItem ( '0',
                                createItem ( '1', NULL ))))))))))))))))))))));
    a[1] = createItem ( '1',
            createItem ( '0',
             createItem ( '0',
              createItem ( '0',
               createItem ( '0',
                createItem ( '0',
                 createItem ( '0',
                  createItem ( '0',
                   createItem ( '0',
                    createItem ( '0',
                     createItem ( '0',
                      createItem ( '0',
                       createItem ( '0',
                        createItem ( '0',
                         createItem ( '0',
                          createItem ( '0',
                           createItem ( '0',
                            createItem ( '0',
                             createItem ( '0',
                              createItem ( '0',
                               createItem ( '0',
                                createItem ( '1', NULL ))))))))))))))))))))));
    assert ( maxOf ( a, 2 ) == a[1] );
    deleteList ( a[0] );
    deleteList ( a[1] );
 
    a[0] = createItem ( '3',
            createItem ( '2',
             createItem ( '1', NULL )));
    a[1] = createItem ( '6',
            createItem ( '5',
             createItem ( '4', NULL )));
    a[2] = createItem ( '9',
            createItem ( 'c',
             createItem ( 'b',
              createItem ( '9',
               createItem ( '9', NULL )))));
    assert ( maxOf ( a, 3 ) == NULL);
    deleteList ( a[0] );
    deleteList ( a[1] );
    deleteList ( a[2] );
 
    return 0;
}
#endif /* __PROGTEST__ */
