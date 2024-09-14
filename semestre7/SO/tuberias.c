#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256
main(){
	int tuberia[2];
	int pid;
	char mensaje[MAX];
//creacion de la tuberia
	
	if(pipe(tuberia) == -1){
printf("FIN1\n");
		printf("Error tuberia\n");
		exit(-1);
	}
	if((pid = fork()) == -1){
printf("FIN2\n");
		printf("Error creando hijo\n");
		exit(-1);
	}
	else if(pid == 0){
printf("FIN3\n");
		while(read(tuberia[0], mensaje, MAX) > 0 && strcmp(mensaje, "FIN\n") != 0)
			printf("Mensaje: %s \n",mensaje);
		close(tuberia[0]);
		close(tuberia[1]);
		exit(0);
	}
	else{
printf("FIN4\n");
		while(fgets(mensaje, sizeof(mensaje), stdin) != NULL && write(tuberia[1], mensaje, strlen(mensaje)+1) > 0 && strcmp(mensaje, "FIN\n") != 0)
		{	printf("Come bien :D\n");	}
		close(tuberia[0]);
		close(tuberia[1]);
	}
printf("FINFINAL\n");
}
