#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 1
typedef struct registroAlumno
{
  char numcta[10];
  char nombre[30];
  char apeidoP[25];
  char apeidoM[25];
  int grupo;
}sr;
main()
{
  sr alumnos[n];
  int i,j,k;
  char nomarch[50];
  FILE *f;
  for(i=0; i<n; i++)
  {
    printf("\nIngresando datos del alumno %d",i+1);
    printf("\nNumero de cuenta:  ");
    gets(alumnos[i].numcta);
    printf("\nNombre:  ");
    gets(alumnos[i].nombre);
    printf("\nApellido paterno:  ");
    gets(alumnos[i].apeidoP);
    printf("\nApellido materno:  ");
    gets(alumnos[i].apeidoM);
    printf("\nGrupo:  ");
    scanf("%d",&alumnos[i].grupo);
    fflush(stdin);
  }

  printf("Nombre y ruta del archivo en donde deseas almacenar los registros de alumnos: \n\n");
  gets(nomarch);
  f=fopen(nomarch,"w");
  if(f==NULL)
  {
    printf("\nNo se pudo abrir el archivo.\nPulse una tecla para continuar\n");
    getch();
    exit(1);
  }
  for(i=0; i<n; i++)
  {
    fprintf(f,"%s ",alumnos[i].numcta);
    fprintf(f,"%s ",alumnos[i].nombre);
    fprintf(f,"%s ",alumnos[i].apeidoP);
    fprintf(f,"%s ",alumnos[i].apeidoM);
    fprintf(f,"%d \n",alumnos[i].grupo);
  }
  fclose(f);
  f=fopen(nomarch,"r");
  if(f==NULL)
  {
    printf("\nNo se pudo abrir el archivo.\nPulse una tecla para continuar\n");
    getch();
    exit(1);
  }
  sr leealumno;
  while(!feof(f))
  {
    fscanf(f,"%s",&leealumno.numcta);
    fscanf(f,"%s",&leealumno.nombre);
    fscanf(f,"%s",&leealumno.apeidoP);
    fscanf(f,"%s",&leealumno.apeidoM);
    fscanf(f,"%d\n",&leealumno.grupo);
    printf("\n%s %s %s %s %d\n",leealumno.numcta,leealumno.nombre,leealumno.apeidoP,leealumno.apeidoM,leealumno.grupo);
  }
  fclose(f);
  getch();
}
//cierra main
