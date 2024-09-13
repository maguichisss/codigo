/*#include<stdlib.h>
#include<stdio.h>
#include<time.h>
main()
{
    int n,i,j,k;
    int x,y,z,resp;
    char seguir;
    do
    {
        srand((unsigned)time(NULL));
        system("clear");
        printf("OPERACIONES ARITMETICAS");
        printf("\nCuantas operaciones deseas realizar?  ");
        scanf("%d",&n);
        int aciertos=0, errores=0;
        for(i=0; i<n; i++)
        {
            system("clear");
            j=rand()%4;
            x=rand()%10;
            y=rand()%10;
            switch(j)
            {
                case 0:
                z=x+y;
                printf("\n%d + %d = ",x,y);
                scanf("%f",&resp);
                if(resp==z)
                {
                    printf("\nLa respuesta es correcta, bien hecho!!!");
                    aciertos++;
                }
                else
                {
                    printf("\nLa respuesta es incorrecta, daaaaa!!!");
                    printf("\n%d + %d = %f",x,y,z);
                    errores++;
                }
                case 1:
                z=x-y;
                printf("\n%d - %d = ",x,y);
                scanf("%f",&resp);
                if(resp==z)
                {
                    printf("\nLa respuesta es correcta, bien hecho!!!");
                    aciertos++;
                }
                else
                {
                    printf("\nLa respuesta es incorrecta, daaaaa!!!");
                    printf("\n%d - %d = %f",x,y,z);
                    errores++;
                }
                case 2:
                z=x*y;
                printf("\n%d * %d = ",x,y);
                scanf("%f",&resp);
                if(resp==z)
                {
                    printf("\nLa respuesta es correcta, bien hecho!!!");
                    aciertos++;
                }
                else
                {
                    printf("\nLa respuesta es incorrecta, daaaaa!!!");
                    printf("\n%d * %d = %f",x,y,z);
                    errores++;
                }
                case 3:

                z=x*y;
                if(x==0)
                x=y;
                printf("\n%d / %d = ",z,x);
                scanf("%f",&resp);
                y=z/x;
                if(resp==y)
                {
                    printf("\nLa respuesta es correcta, bien hecho!!!");
                    aciertos++;
                }
                else
                {
                    printf("\nLa respuesta es incorrecta, daaaaa!!!");
                    printf("\n%d / %d = %f",z,x,y);
                    errores++;
                }
                default:
                break;
            }
        }
        printf("\nEl numero de aciertos es: %d",aciertos);
        printf("\nEl numero de errores es: %d",errores);
        printf("\nSi deseas seguir jugando presiona S  ");
        scanf("%s",&seguir);
    }
    while(seguir=='s' || seguir=='S');
    printf("\n\nGracias por juegar el juego\n");
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int p,u,n,r,x,y,z,respuesta,correc,incorrec,totalbuenas=0,totalmalas=0;
    char w;

    do
    {
    system("clear");
    correc=0;
    incorrec=0;
    printf("                Reto aritmetico\n\n\n\n");
    //system("cls");
    srand((unsigned)time(NULL));
    printf("\n\n\n\n Resolver las operaciones aritmeticas indicadas\n\n\n");
    //system("cls");
    printf("\n\n\n Cuantas operaciones deseas hacer? ");
    scanf("%d",&n);
    system("clear");
        for(r=0;r<n;r++)
    {
        system("clear");
        x= rand()%10;
        y= rand()%10;
        z= rand()%5;
        switch(z)
        {
            case 0:

            printf("Cual es el resultado de  %d + %d   \n",x,y);
            scanf("%d",&respuesta);
            if(respuesta== x+y)
            {
                //printf("\nresultado correcto ");
                correc++;
            }else
            {
                //printf("\nresultado incorrecto ");
                incorrec++;
            }
            break;

             case 1:

            printf("Cual es el resultado de %d - %d   \n",x,y);
            scanf("%d",&respuesta);
            if(respuesta== x-y)
            {
                //printf("\nresultado correcto ");
                correc++;
            }else
            {
                //printf("\nresultado incorrecto ");
                incorrec++;
            }
            break;

             case 2:

            printf("Cual es el resultado de  %d * %d   \n",x,y);
            scanf("%d",&respuesta);
            if(respuesta== x*y)
            {
                //printf("\nresultado correcto ");

                correc++;
            }else
            {
                //printf("\nresultado incorrecto ");

                incorrec++;
            }
            break;

             case 3:

            printf("Cual es el resultado del modulo %d / %d   \n",x,y);
            scanf("%d",&respuesta);
            if(respuesta == x%y)
            {
                //printf("\nresultado correcto ");
                correc++;
            }else
            {
                //printf("\nresultado incorrecto ");

                incorrec++;
            }
            break;

            case 4:

            u=x*y;

            if(x==0)
            x=y;
            printf("Cual es el resultado de dividir %d / %d   \n",u,x);
            scanf("%d",&respuesta);
            p=u/x;
            if(respuesta== p)
            {
                //printf("\nresultado correcto ");
                correc++;
            }
            else
            {
                //printf("\nresultado incorrecto ");

                incorrec++;
            }
            break;

        }
    }
     totalbuenas+=correc;
     totalmalas+=incorrec;
     system("clear");
     printf("En este ejercicios tuviste %d  respuestas Correctas y %d  respuestas incorrectas  \n",correc,incorrec);
     //getch();
     printf("Tu puntuacion final es %d",(correc*10-incorrec*5));
     //getch();
     system("clear");
    // printf("El total de tus presuestas correctas e incorrectas es %d y %d",totalbuenas,totalmalas);
     //getch();
    // system("cls");
     printf("Quieres seguir el juego, presiona la letra 's' para hacerlo ");
     scanf("%s",&w);
    }while(w=='s' || w=='S');
    system("cls");
    printf("El total de respuestas correctas es: %d",totalbuenas);
    printf("\nEl total de respuestas incorrectas es: %d\n",totalmalas);
    printf("Tu puntuacion final es %d",(totalbuenas*10-totalmalas*5));

}
