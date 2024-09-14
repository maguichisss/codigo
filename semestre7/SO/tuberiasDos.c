#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main( int argc, char **argv )
{
  pid_t pid;
  int tuberiaA[2], tuberiaB[2], readbytes;
  char mensaje[MAX];

  if( pipe( tuberiaA ) == -1 || pipe( tuberiaB ) == -1 ){
    printf("Error al crear las tuberias");
    exit(-1);
  }
  
  if( ( pid=fork() ) == -1){
    printf("error en fork");
    exit(-1);
  }

  if( pid == 0 )
  { // hijo
    close( tuberiaA[1] ); /* cerramos el lado de escritura de tuberiaA */
    close( tuberiaB[0] ); /* cerramos el lado de lectura de tuberiaB */

    while( (readbytes=read( tuberiaA[0], mensaje, MAX ) ) > 0)
      write( 1, mensaje, readbytes );
    close( tuberiaA[0] );

    strcpy( mensaje, "Soy tu hijo hablandote por la otra tuberia.\n" );
    write( tuberiaB[1], mensaje, strlen( mensaje ) );
    close( tuberiaB[1] );
  }
  else
  { // padre
    close( tuberiaA[0] ); /* cerramos el lado de lectura de tuberiaA */
    close( tuberiaB[1] ); /* cerramos el lado de escritura de tuberiaB */

    strcpy( mensaje, "Soy tu padre hablandote por una tuberia.\n" );
    write( tuberiaA[1], mensaje, strlen( mensaje ) );
    close( tuberiaA[1]);

    while( (readbytes=read( tuberiaB[0], mensaje, MAX )) > 0)
      write( 1, mensaje, readbytes );
    close( tuberiaB[0]);
  }
  waitpid( pid, NULL, 0 );

}