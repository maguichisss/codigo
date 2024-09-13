#include <stdio.h>
#include <stdlib.h>

int main()
{
   char numPtr[5] = "1234";
   printf( "Convirtiendo la cadena \"%s\" en un numero: %d\n", numPtr, atoi(numPtr) );
   char letra[10];
   int let[10], tmp, i;
   printf("Presiona una tecla: ");
   /*for(i=0; i<10; i++)
   {
       //scanf("%s",&letra[i]);
       //tmp = atoi(letra);
       //printf("+%c+\n",letra[i]);
   }Ç*/
   for(i=0; i<10; i++)
   {
       //scanf("%s",&letra[i]);
       do
       {
           scanf("%s",&letra[i]);
           if(letra[i]<96 || letra[i]>123)
           {
               printf("Opcion invalida\n");
               getchar();
           }
           //system("cls");
       }while(letra[i]<96 || letra[i]>133 );
       let[i]=letra[i]-96;
   }
   for(i=0; i<10; i++)
    printf("+%c=%d+\n",let[i]+96,let[i]);
   return 0;
}
