/*-------------------------------------------------------*/
/* PROGRAMA QUE DISTINGUE EL TIPO DE DATO DIGITADO       */
/* ALUMNA: ALEJANDRA PEREZ HERNANDEZ                     */
/* GRUPO: 1103                                           */
/* FECHA DE ELABORACION: 26/10/2010                      */
/*-------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
main()
{
    int c;
    printf("Presiona una tecla\n");
    /* getchar se almacena en c*/
    c = getchar();
    /*si la tecla que precionas es c esta entre '0' y '9',  va a imprimir el valor*/
    if('0' <= c && c <= '9')
        printf("La tecla %c es un numero\n",c);
    /*si lo que se presiona no esta en el rango dira que es letra*/
    else
        printf("La tecla %c es letra\n",c);
    system("pause");
}

