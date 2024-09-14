#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
  int mRecursos, nProcesos;
  //SE SOLICITAN RECURSOS Y PROCESOS
//  printf("Cuantos recursos: ");
  scanf("%d",&mRecursos);
//  printf("Cuantos procesos: ");
  scanf("%d",&nProcesos);
  printf("\n");
  int matrizRecursosMaximos[mRecursos][nProcesos];
  int matrizRecursosAsignados[mRecursos][nProcesos];
  int matrizRecursosNecesarios[mRecursos][nProcesos];
  int recursosDisponibles[mRecursos];
  int recursosMaximos[mRecursos];
  int totalProcesos[nProcesos];
  int procesoFin[nProcesos];
  int i, j, k, aux, seguro=0;
  /*INICIO RECURSOS MAXIMOS*/
  for(i=0; i<mRecursos; i++){
//    printf("Unidades MAXIMAS disponibles del recurso %d: ",i+1);
    scanf("%d",&recursosMaximos[i]);
    recursosDisponibles[i] = 0;
  }//FIN RECURSOS MAXIMOS

  /*INICIO PEDIMOS LOS RECURSOS MAXIMOS Y ASIGNADOS DE CADA PROCESO*/
  for(i=0; i<nProcesos; i++){
    for(j=0; j<mRecursos; j++){
      matrizRecursosMaximos[i][j] = 0;
      matrizRecursosAsignados[i][j] = 0;
//      printf("Unidades MAXIMAS del recurso %d que necesita el proceso %d: ",j+1,i+1);
      scanf("%d",&matrizRecursosMaximos[i][j]);
//      printf("Unidades ASIGNADAS del recurso %d que necesita el proceso %d: ",j+1,i+1);
      scanf("%d",&matrizRecursosAsignados[i][j]);
      matrizRecursosNecesarios[i][j] = matrizRecursosMaximos[i][j]-matrizRecursosAsignados[i][j];
    }
  }
  //CALCULA LOS RECURSOS DISPONIBLES
  //SUMANDO EL RECURSO ASIGNADO A LOS PROCESOS
  //Y RESTANDO DE LOS RECURSOS MAXIMOS
  for(i=0; i<mRecursos; i++){
    for(j=0; j<nProcesos; j++)
      recursosDisponibles[i] += matrizRecursosAsignados[j][i];
    recursosDisponibles[i] = recursosMaximos[i]-recursosDisponibles[i];
  }
  //FIN PEDIR RECURSOS

  /*INICIO IMPRIME TODA LA INFORMACION*/
  printf("\nProcesos: %d\n",nProcesos);
  printf("Recursos: %d\n",mRecursos);
  printf("Recursos Maximos:\n ");
  for(i=0; i<mRecursos; i++)
    printf("%d\t",recursosMaximos[i]);
  printf("\nRecursos disponibles:\n ");
  for(i=0; i<mRecursos; i++)
    printf("%d\t",recursosDisponibles[i]);
  printf("\n+++Matriz Recursos Maximos+++");
  printf("\n");
  for(i=0; i<nProcesos; i++){
    for(j=0; j<mRecursos; j++)
      printf("%d\t", matrizRecursosMaximos[i][j]);
    printf("\n");
  }
  printf("\n+++Matriz Recursos Asignados+++");
  printf("\n");
  for(i=0; i<nProcesos; i++){
    for(j=0; j<mRecursos; j++)
      printf("%d\t", matrizRecursosAsignados[i][j]);
    printf("\n");
  }
  printf("\n+++Matriz Recursos Necesarios+++");
  printf("\n");
  for(i=0; i<nProcesos; i++){
    for(j=0; j<mRecursos; j++)
      printf("%d\t", matrizRecursosNecesarios[i][j]);
    printf("\n");
  }//FIN IMPRIME TODA LA INFORMACION

  /*INICIO ALGORITMO DEL BANQUERO*/

  for(k=0; k<nProcesos; k++){
    aux=0;
    for(i=0; i<nProcesos; i++){
      procesoFin[i]=0;
      for(j=0; j<mRecursos; j++){
        if(matrizRecursosNecesarios[i][j] <= recursosDisponibles[j]+matrizRecursosAsignados[i][j])
          procesoFin[i]++;
      }
      if(procesoFin[i] == mRecursos){
        for(j=0; j<mRecursos; j++){
          recursosDisponibles[j] -= matrizRecursosNecesarios[i][j];
          matrizRecursosAsignados[i][j] += matrizRecursosNecesarios[i][j];
          recursosDisponibles[j] += matrizRecursosAsignados[i][j];
          if(matrizRecursosAsignados[i][j] == matrizRecursosMaximos[i][j])
            matrizRecursosAsignados[i][j] = 0;
          matrizRecursosNecesarios[i][j] = 0;
        }
      }
    }
    for(i=0; i<nProcesos; i++)
      if(procesoFin[i] == mRecursos)
        aux++;
    if(aux == nProcesos){
      seguro=1;
      break;
    }
  }//FIN ALGORITMO DEL BANQUERO
  //SI TODOS LOS PROCESOS TIENEN FIN -> ESTADO SEGURO!!!
  if(seguro)
    printf("\nEstado seguro :D\n");
  else
    printf("\nEstado inseguro :C\n");
  
  printf("\nRecursos disponibles:\n ");
  for(i=0; i<mRecursos; i++)
    printf("%d\t",recursosDisponibles[i]);
    
return 0;
}
/*
EJEMPLOS

2 2
10 9
6 2 3 0
3 1 5 4

3 3
7 3 6
3 1 2 0 2 0
6 3 1 1 3 2
3 2 1 1 4 1

3 4
9 3 6
3 1 2 0 2 0
6 6 1 1 3 2
3 2 1 1 4 1
4 0 2 0 2 2

3 3
3 3 2
2 7 5
3 0 2
2 4 3

3 4
6 2 4
3 1 2 0 2 1
6 0 1 0 3 0
3 1 1 1 4 2
4 2 2 0 2 0

3 5
5 2 4
3 1 2 0 2 0
4 1 1 0 3 1
1 0 0 0 2 0
2 0 2 1 2 1
4 1 0 0 3 0

4 5
4 3 5 9
3 1 2 0 2 0 8 0
4 1 1 0 3 1 2 1
1 0 0 0 2 0 1 1
2 0 2 1 2 1 5 2
4 1 0 0 3 0 7 1

*/
