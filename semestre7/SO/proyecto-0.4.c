#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main(){
  srand(time(NULL));
  int mRecursos, nProcesos;
  //se solicitan los recursos y los procesos
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
  int i, j, k, aux, seguro=1;
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
  }//FIN PEDIR RECURSOS
  
  /*INICIO ALGORITMO DEL BANQUERO*/
  for(i=0; i<mRecursos; i++){
    for(j=0; j<nProcesos; j++){
      printf("+ %d + ", matrizRecursosAsignados[j][i]);
      recursosDisponibles[i] += matrizRecursosAsignados[j][i];
    }
    printf(" = %d \n",recursosDisponibles[i]);
  }
  for(i=0; i<mRecursos; i++){
    printf("+ %d ++ %d + ",recursosMaximos[i], recursosDisponibles[i]);
    recursosDisponibles[i] = recursosMaximos[i]-recursosDisponibles[i];
    printf("%d +\n",recursosDisponibles[i]);
  }
  
  for(i=0; i<nProcesos; i++){
    procesoFin[i] = 1;
    for(j=0; j<mRecursos; j++)
      if(matrizRecursosNecesarios[i][j] > recursosDisponibles[j])
	procesoFin[i]=0;
    for(j=0; j<mRecursos; j++)
      if(procesoFin[i] && matrizRecursosNecesarios[i][j] > 0){
//	printf("+ %d ++ %d + %d +\n",procesoFin[i], matrizRecursosNecesarios[i][j], recursosDisponibles[j]);
	aux = matrizRecursosNecesarios[i][j];
	matrizRecursosNecesarios[i][j] -= recursosDisponibles[j];
	recursosDisponibles[j] += aux;
	
      }  
  }//FIN ALGORITMO DEL BANQUERO

  /*INICIO IMPRIME TODA LA INFORMACION*/
  printf("Procesos: %d\n",nProcesos);
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

}
/*
EJEMPLOS

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
9 3 6 
3 2 2 
6 1 3 
3 1 4 
4 2 2

3 5 
5 2 4 
3 2 2 
5 1 3 
9 0 2 
2 2 2 
4 3 3

4 5 
5 2 4 9
3 2 2 8
5 1 3 2
1 0 2 6
2 2 2 5
4 0 3 7

*/