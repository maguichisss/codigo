#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 3
typedef struct alumno
{
        int grupo;
        char alumno[30];
        char numcta[12];
        char materia[20];
        float promedio;
}alu;
main()
{
      int i;
      alu regis[n];
      printf("\t\tPrograma para el control de alumnos");
      for(i=0; i<n; i++)
      {
              printf("\nAlumno [ %d ]" ,i+1);
              printf("\nGrupo: ");
              scanf("%d",&regis[i].grupo);
              printf("Alumno: ");
              scanf("%s",&regis[i].alumno);
              printf("Numero de cuenta: ");
              scanf("%s",&regis[i].numcta);
              printf("Materia: ");
              scanf("%s",&regis[i].materia);
              printf("Promedio: ");
              scanf("%f",&regis[i].promedio);
              system("cls");
      }
      FILE *archivito;
      char ruta[60];
      printf("\nEscribe la ruta y nombre del archivo:  ");
      fflush(stdin);
      gets(ruta);
      archivito=fopen(ruta,"a");
      if(archivito==NULL)
      {
               printf("\nNo se pudo crear el archivo ");
               getch();
               exit(1);
      }
      //fprintf(archivito,"\nGrupo\tAlumno\tNo.cuenta\tMateria\t\tPromedio\n");
      for(i=0;i<n;i++)
      {
              fprintf(archivito,"%d\t",regis[i].grupo);
              fprintf(archivito,"%s\t",regis[i].alumno);
              fprintf(archivito,"%s\t",regis[i].numcta);
              fprintf(archivito,"%s\t",regis[i].materia);
              fprintf(archivito,"%f\n",regis[i].promedio);
      }
      fclose(archivito);

      archivito=fopen(ruta,"r");
      if(archivito==NULL)
      {
               printf("\nNo se pudo leer el archivo ");
               getch();
               exit(1);
      }
      alu leer;
      while(!feof(archivito))
      {
               //fscanf(archivito,"%s\t%s\t%s\t%s\t%s\n");
               fscanf(archivito,"%d\t%s\t%s\t%s\t%f\n",&leer.grupo,&leer.alumno,&leer.numcta,&leer.materia,&leer.promedio);
               printf("%d\t%s\t%s\t%s\t%f\n",leer.grupo,leer.alumno,leer.numcta,leer.materia,leer.promedio);
      }
      fclose(archivito);
      getch();

}
