#include "stdio.h"

main()
{

 int i;
 char *puntero="sombrero";// el asteriscos siempre delante, para
                                 // cuando queramos asignar un valor

 for (i=0;i<(sizeof(double));i++)

      printf("%s\n",puntero+i); // OJO, no incrementamos el contenido

                                           // sumamos "i" a la direccion del puntero
    printf("%s\n", puntero);
}

