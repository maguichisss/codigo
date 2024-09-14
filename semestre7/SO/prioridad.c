#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t a,b,c,d,e;
	int v[5][2],s=10,i,j;
	a = getpid();
	printf("Proceso actual %d\n", getpid());
	
	b = fork();
	c = fork(),
	d = fork();
	e = fork();
	
	v[1][0] = 7;
	v[2][0] = 4;
	v[3][0] = 2;
	v[4][0] = 5; 
	v[1][1] = b;
	v[2][1] = c;
	v[3][1] = d;
	v[4][1] = e;
	
	if (v[1][1]<0 || v[2][1]<0 || v[3][1]<0 || v[4][1]<0)
	{
		printf("Fallo la creacion del proceso \n");
		return -1;
	}
	for (i = 1; i<4; i++)
	{
		if (v[i+1][0]>v[i][0])
		{
			s = v[i][0];
			j = v[i][1];	
			v[i][0] = v[i+1][0];
			v[i][1] = v[i+1][1];
			v[i+1][0] = s;
			v[i+1][1] = j;
		}
	}
	for (i = 1; i<4; i++)
	{
		if (v[i+1][0]>v[i][0])
		{
			s = v[i][0];
			j = v[i][1];	
			v[i][0] = v[i+1][0];
			v[i][1] = v[i+1][1];
			v[i+1][0] = s;
			v[i+1][1] = j;
		}
	}
	for (i = 1; i<4; i++)
	{
		if (v[i+1][0]>v[i][0])
		{
			s = v[i][0];
			j = v[i][1];	
			v[i][0] = v[i+1][0];
			v[i][1] = v[i+1][1];
			v[i+1][0] = s;
			v[i+1][1] = j;
		}
	}
	 
	if(v[1][1] == 0 && v[2][1] != 0 && v[4][1] != 0 && v[3][1] != 0)
	{		
		printf("\n Proceso hijo1 PID %d PPID %d con prioridad %d\n", getpid(), getppid(),v[1][0]);
	}
	if(v[2][1] == 0 && v[1][1] != 0 && v[4][1] != 0 && v[3][1] != 0)
	{
		sleep(1);
		printf("\n Proceso hijo2 PID %d PPID %d con prioridad %d\n", getpid(), getppid(),v[2][0]);
	}
	if(v[3][1] == 0 && v[1][1] != 0 && v[2][1] != 0 && v[4][1] != 0)
	{
		sleep(2);
		printf("\n Proceso hijo3 PID %d PPID %d con prioridad %d\n", getpid(), getppid(),v[3][0]);
	}	
	if(v[4][1] == 0 && v[1][1] != 0 && v[2][1] != 0 && v[3][1] != 0)
	{
		sleep(3);
		printf("\n Proceso hijo4 PID %d PPID %d con prioridad %d\n", getpid(), getppid(),v[4][0]);
	}	
	if(v[4][1]>0 && v[3][1]>0 && v[2][1]>0 && v[1][1]>0)
	{
		sleep(4);
		printf("\n En el proceso padre PID %d \n", getpid());
	}
}
	
		
	

