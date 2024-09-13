/*Marzo 8 manejo de archivos, creacion de, hecho por la maestra*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
     char nom[60];
     FILE *Arch;  /* Crear un archivo*/
     Arch=fopen("E:\datos.data","w");/*Ponemos toda la ruta, w formato del archivo, si existe un archivo borra el contenido y escribe el nuevo*/
     if (Arch==NULL)    /*si no existe el w lo crea no nos servira para guardar*/       
     {
        printf("Error: No se pudo abrir el archivo");
        getch();
        exit(1);/*Debe llevar un entero, exit esta en stdlib*/       
     }
     printf("¿Como te llamas?");
     gets(nom);
     fprintf(Arch,"%s",nom);
     fclose(Arch);
     Arch=fopen("E:\datos.data","r");
     if(Arch==NULL)
     {
        printf("Error:  No se pudo abrir el archivo");
        exit(1);
     }
     printf("\n El contenido del archivo es: \n");
     fscanf(Arch,"%s",nom);
     printf("%s",nom);
     getch();
     fclose(Arch);
}    
 
