#include<stdio.h>
#include<limits.h>
#include<float.h>
main()
{
    char ;
    short ;
    int ;
    long ;
    float ;
    double ;
    unsigned char ;
    unsigned short ;
    unsigned int ;
    unsigned long ;
    printf("Bytes que utiliza cada variable\n\n");
    printf("-%d- bytes utiliza la variable char\n",sizeof(char));
    printf("-%d- bytes utiliza la variable short\n",sizeof(short));
    printf("-%d- bytes utiliza la variable int\n",sizeof(int));
    printf("-%d- bytes utiliza la variable long\n",sizeof(long));
    printf("-%d- bytes utiliza la variable float\n",sizeof(float));
    printf("-%d- bytes utiliza la variable double\n",sizeof(double));
    printf("\nUNSIGNED\n\n");
    printf("-%d- bytes utiliza la variable char\n",sizeof(unsigned char));
    printf("-%d- bytes utiliza la variable short\n",sizeof(unsigned short));
    printf("-%d- bytes utiliza la variable int\n",sizeof(unsigned int));
    printf("-%d- bytes utiliza la variable long\n",sizeof(unsigned long));
    printf("\n\nTama%co de las variables\n\n",164);
    printf("char    = %d min %20d max\n",CHAR_MIN,CHAR_MAX);
    printf("short   = %d min %20d max\n",SHRT_MIN,SHRT_MAX);
    printf("int     = %d min %20d max\n",INT_MIN,INT_MAX);
    printf("long    = %d min %20d max\n",LONG_MIN,LONG_MAX);
    printf("float   = %d min\t\t %20d max\n",FLT_MIN,FLT_MAX);
    printf("double  = %d min\t\t %18d max\n",DBL_MIN,DBL_MAX);
    printf("\nUNSIGNED\n\n");
    printf("char    = %d max\n",UCHAR_MAX);
    printf("short   = %d max\n",USHRT_MAX);
    printf("int     = %d max\n",UINT_MAX);
    printf("long    = %d max\n",ULONG_MAX);

}
