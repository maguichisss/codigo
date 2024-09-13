/* fichero ordena2.c */
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
main(void)
{
    char **cadena, *aux;
    int i, j, n;
    char temp[20];
    // clrscr();
    printf("%s%s\n", "Este programa ordena diez nombres",
           "introducidos por teclado.");
    printf("Introduzca los diez nombres:\n");
    cadena = (char**)malloc(10*sizeof(char*));
    for (i=0; i<10; i++)
    {
        printf("Nombre %d: ", i+1);
        scanf(" %[^\n]", temp);
        cadena[i] = (char*)malloc((strlen(temp)+1)*sizeof(char));
        strcpy(cadena[i], temp);
    }
    for (i=0; i<9; i++)
        for (j=i+1; j<10; j++)
            if ((strcmp(cadena[i], cadena[j])) > 0)
            {
                aux = cadena[i];
                cadena[i] = cadena[j];
                cadena[j] = aux;
            }
    printf("La lista ordenada es:\n");
    for (i=0; i<10 ; i++)
        printf("%s\n", cadena[i]);
    getche();
}
