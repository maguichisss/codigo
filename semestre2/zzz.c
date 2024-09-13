#include <stdio.h>
#include <string.h>

main()
{
  char info[15];
  float cl, ex, nf;
  int a, control=-1, n=0;

  struct escuela
  {
   char nombre[20];
   int clases;
   float examen, notafinal;
  }datos[20];

  printf("\nIntroduzca nombre y primer apellido del alumno\n(Si quiere salir escriba SALIR)\n(Si quiere mostrar la lista escriba LISTA): ");

  do
  {
  if(n!=0)
   printf("\nIntroduzca nombre y primer apellido del alumno: ");
  fflush(stdin);
  scanf("%[^\n]s", &info);

  if(strncmp(info, "salir", 5)==0 || strncmp(info, "SALIR", 5)==0)
    break;

  else if(strncmp(info, "lista", 5)==0 || strncmp(info, "LISTA", 5)==0)
  {
   printf("|          NOMBRE|     CLASES|   N.EXAMEN|     N.FINAL|\n");

   for (a=0;a<=control;a++)
   {
   printf("|----------------|-----------|-----------|------------|\n");
   printf("|%15s |%10i |%10.2f |%5.2f|\n", datos[a].nombre, datos[a].clases, datos[a].examen, datos[a].notafinal);
   }
  }

  else
  {
  do
    {
      printf("\n\nIntroduzca el numero de clases a las que ha asistido el alumno (max. = 15)==> ");
      fflush(stdin);
      scanf("%f", &cl);

      if(cl>=16 || cl<0)
        printf("\nEl dato introducido no es valido\n");

    }while(cl>15 || cl<0);

    do
    {
      printf("\nIntroduzca la nota que el alumno obtuvo en el examen (0<--->9) ==> ");
      fflush(stdin);
      scanf("%f", &ex);

      if(ex<0 || ex>9)
        printf("\nEl dato introducido no es valido\n");

    }while(ex<0 || ex>9);

    nf=(cl/15)+ex;


   control++;
   strcpy(datos[control].nombre, info);
   datos[control].clases=cl;
   datos[control].examen=ex;
   datos[control].notafinal=nf;
  }
  n++;
  }while(n!=0 && (strncmp(info, "salir", 5)!=0 || strncmp(info, "SALIR", 5)!=0));
}
