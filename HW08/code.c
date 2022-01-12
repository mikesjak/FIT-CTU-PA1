#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TEmployee
{
  struct TEmployee         * m_Next;
  struct TEmployee         * m_Bak;
  char                     * m_Name;
} TEMPLOYEE;

#endif /* __PROGTEST__ */

// Deletes one Employee
TEMPLOYEE * employeeDelete ( TEMPLOYEE * a ){

  TEMPLOYEE * next = a->m_Next;
  free(a->m_Name);
  free(a);
  return next;
}

// Creates one new Employee
TEMPLOYEE * newEmployee ( const char * name, TEMPLOYEE * next ){

  // Allocating memory, settiong temporary variable to store current name
  TEMPLOYEE * a = ( TEMPLOYEE *) malloc (sizeof(*a) + 5);
  char * tmp = (char *) malloc (strlen(name) + 1);

  strcpy(tmp, name);

  // Setting data to new Employee
  a -> m_Name = tmp;
  a -> m_Next = next;
  a -> m_Bak = NULL;

  return a;
}

TEMPLOYEE * cloneList ( TEMPLOYEE * src ){

  if (src == NULL){
    return NULL;
  }

  TEMPLOYEE * source = src;

  int count = 0,
      counter = 1;

// Creating first Employee
  TEMPLOYEE * lastMade;
  lastMade = newEmployee(src->m_Name, NULL);
  lastMade->m_Bak = NULL;

  TEMPLOYEE *newhead = lastMade;

// Helping indexes to move in array A
  TEMPLOYEE * index = src;
  TEMPLOYEE * index2 = src;

// Helping indexes to move in array B
  TEMPLOYEE * index4 = newhead;
  TEMPLOYEE * index3 = newhead;

  src = src->m_Next;

// Cloning without m_Bak
  while ( src != NULL ){

    TEMPLOYEE * now = NULL;
    now = newEmployee(src->m_Name, NULL);
    now->m_Bak = NULL;

    lastMade->m_Next = now;
    lastMade = now;

    src = src->m_Next;
  }

// Cloning m_Baks
  while ( index != NULL ){

    // Skiping empty pointers
    if (index->m_Bak == NULL){

      index3 = index3->m_Next;
      index = index->m_Next;
      continue;
    }

    // Searching address to point at
    if (index->m_Bak != NULL){
      while ( index->m_Bak != index2 ){
        count ++;
        index2 = index2->m_Next;
      }

      //printf("bak %d = %d\n",counter-1, count);
      
      // Setting the right address to point at
      for (int i = 0; i < count; i ++){
        index4 = index4->m_Next;
      }

      //printf(" -> Bak: = %d\n", index4);
      index3->m_Bak = index4;

      // Reevaluating indexes 
      count = 0;

      index2 = source;
      index4 = newhead;

      index3 = index3->m_Next;
      index = index->m_Next;
    }

    // Printing counter
    counter ++;
  }  
  count = 0;
  return newhead;
} 

void freeList ( TEMPLOYEE * src ){

  TEMPLOYEE * head;
  head = src;

  // Deleting step by step
  while ( head != NULL ){
    head = employeeDelete (head);
  }
  src = NULL;

}

#ifndef __PROGTEST__
int                main         ( int               argc,  char            * argv [] )
{
  TEMPLOYEE * a, *b;
  char tmp[100];

  assert ( sizeof ( TEMPLOYEE ) == 3 * sizeof ( void * ) );
  a = NULL;
  a = newEmployee ( "Peter", a );
  a = newEmployee ( "John", a );
  a = newEmployee ( "Joe", a );
  a = newEmployee ( "Maria", a );
  a -> m_Bak = a -> m_Next;
  a -> m_Next -> m_Next -> m_Bak = a -> m_Next -> m_Next -> m_Next;
  a -> m_Next -> m_Next -> m_Next -> m_Bak = a -> m_Next;
  a -> m_Next -> m_Next ->  m_Bak = a -> m_Next -> m_Next -> m_Next;
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Bak == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  b = cloneList ( a );
  strncpy ( tmp, "Moe", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
  strncpy ( tmp, "Victoria", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
  strncpy ( tmp, "Peter", sizeof ( tmp ) );
  a = newEmployee ( tmp, a );
  b -> m_Next -> m_Next -> m_Next -> m_Bak = b -> m_Next -> m_Next;
  assert ( a
           && ! strcmp ( a -> m_Name, "Peter" )
           && a -> m_Bak == NULL );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Victoria" )
           && a -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "Moe" )
           && a -> m_Next -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Maria" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == NULL );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Bak == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Bak == NULL );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next -> m_Next ); 
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next ); 
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  freeList ( a );
  b -> m_Next -> m_Bak = b -> m_Next;
  a = cloneList ( b );
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Bak == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Bak == a -> m_Next );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Bak == a -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == NULL );
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Bak == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Bak == b -> m_Next );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Bak == b -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == NULL );

  freeList ( b );
  freeList ( a );

  return 0;
}
#endif /* __PROGTEST__ */
