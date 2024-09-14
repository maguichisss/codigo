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
  }//FIN PEDIR RECURSOS
  
  /*INICIO IMPRIME TODA LA INFORMACION*/
  printf("\n\nProcesos: %d\n",nProcesos);
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
  for(i=0; i<mRecursos; i++){
    for(j=0; j<nProcesos; j++)
      recursosDisponibles[i] += matrizRecursosAsignados[j][i];
    recursosDisponibles[i] = recursosMaximos[i]-recursosDisponibles[i];
  }

  printf("\nRecursos disponibles:\n ");
  for(i=0; i<mRecursos; i++)
    printf("%d\t",recursosDisponibles[i]);
  printf("\n");
  
  for(k=0; k<nProcesos; k++){
    aux=0;
    printf("K = %d\n",k+1);
    for(i=0; i<nProcesos; i++){
      procesoFin[i]=0;
      for(j=0; j<mRecursos; j++){
	printf("%d <= %d --- ",matrizRecursosNecesarios[i][j], recursosDisponibles[j]);
	if(matrizRecursosNecesarios[i][j] <= recursosDisponibles[j]+matrizRecursosAsignados[i][j]){
	  procesoFin[i]++;
	  printf(" *  %d ",procesoFin[i]);
	}
	printf("\n");
      }
      if(procesoFin[i] == mRecursos){
	for(j=0; j<mRecursos; j++){
	  recursosDisponibles[j] -= matrizRecursosNecesarios[i][j];
	  matrizRecursosAsignados[i][j] += matrizRecursosNecesarios[i][j];
	  recursosDisponibles[j] += matrizRecursosAsignados[i][j];
	  if(matrizRecursosAsignados[i][j] == matrizRecursosMaximos[i][j])
	    matrizRecursosAsignados[i][j] = 0;
	  matrizRecursosNecesarios[i][j] = 0;
//	  printf("%d = ", recursosDisponibles[j]);
//	  printf(" %d = %d\n", matrizRecursosAsignados[i][j], matrizRecursosNecesarios[i][j]);
	  
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
  }
  
/*
2 2
10 9
6 2 3 0
3 1 5 4

3 3
9 3 6
3 1 2 0 2 0
6 6 1 1 3 2
3 2 1 1 4 1

 */
  //FIN ALGORITMO DEL BANQUERO
  
  
  
  
  printf("\nProceso Fin:\n ");
  for(i=0; i<nProcesos; i++)
    printf("%d\t",procesoFin[i]);

  if(seguro)
    printf("\nEstado seguro :D\n");
  

}
/*
EJEMPLOS

2 2
10 9
6 2 3 0
3 1 5 4

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
5 3 5 9
3 1 2 0 2 0 8 0
4 2 1 0 3 1 2 1
1 0 0 0 2 0 1 1
2 0 2 1 2 1 5 2
4 1 0 0 3 0 7 1

*/