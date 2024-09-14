#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
main(){
  int continuar = 0;
  srand(time(NULL));
  do{
    printf("+++++++++++Empieza+++++++++++\n\n");
    int mRecursos, nProcesos, i, j, k;
    //se solicitan los recursos y los procesos
  //  printf("Cuantos recursos: ");
  //  scanf("%d",&mRecursos);
    mRecursos=rand()%10+1;
  //  printf("Cuantos procesos: ");
  //  scanf("%d",&nProcesos);
    nProcesos=rand()%10+1;
    printf("\n");
    int bank[nProcesos][mRecursos];
    int recursosDisponibles[mRecursos];
    int recursosMaximos[mRecursos];
    int totalProcesos[nProcesos];
    int procesoBloqueado[nProcesos];
    int seguro=nProcesos;
    //RECURSOS DISPONIBLES
    for(i=0; i<mRecursos; i++){
  //    printf("Unidades disponibles del recurso %d: ",i+1);
  //    scanf("%d",&recursosDisponibles[i]);
	recursosMaximos[i]=5+rand()%16;
	recursosDisponibles[i]=recursosMaximos[i]-rand()%5-1;
    }
    //PEDIMOS LOS RECURSOS QUE NECESITA CADA PROCESO
    for(i=0; i<nProcesos; i++){
      procesoBloqueado[i]=0;
      for(j=0; j<mRecursos; j++){
  //	printf("Unidades del recurso %d que necesita el proceso %d: ",j+1,i+1);
  //      scanf("%d",&bank[i][j]);
	  bank[i][j]=rand()%11;
	  if(bank[i][j] > recursosDisponibles[j])
	    procesoBloqueado[i]=1;
      }
    }
    /*IPRIME TOD LA INFORMACION*/
    printf("Procesos: %d\n",nProcesos);
    printf("Recursos: %d\n",mRecursos);
    printf("Recursos Maximos:\n ");
    for(i=0; i<mRecursos; i++)
      printf("%d\t",recursosMaximos[i]);
    printf("\nRecursos disponibles:\n ");
    for(i=0; i<mRecursos; i++)
      printf("%d\t",recursosDisponibles[i]);
    printf("\n+++Matriz+++");
    printf("\n");
    for(i=0; i<nProcesos; i++){
      for(j=0; j<mRecursos; j++)
	printf("%d\t", bank[i][j]);
      printf("\n");
    }//FIN DE IMPRIME TODA LA INFORMACION
    /*DICE SI ALGUN PROCESO ENTRA EN ESTADO INSEGURO*/
    for(i=0; i<nProcesos; i++)
	if(procesoBloqueado[i]){
	  printf("Estado inseguro en el proceso %d\n",i+1);
	  seguro--;
	}
    if(seguro == nProcesos){
      printf("Estado seguro\n");
      continuar = 0;
    }
    else
      continuar = 1;
     //FIN ESTADO INSEGURO
    printf("\n\n+++++++++++Termina+++++++++++\n");
  }while(continuar);
}
/*
EJEMPLOS

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