#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agendita
{
    char nombre[50];
    char direc[60];
    char tel[20];
    char mail[30];
    char contra[12];
}age;

static age reg, reg1;
char agend[]="agenda.txt";
char copy[]="agendacpy.txt";
FILE *arch;
FILE *copia;

registro()
{
    printf("\nEn lugar de usar espacios( ) usa guion bajo ( _ )\n\n");
    printf("\nNombre: ");
    gets(reg.nombre);
    printf("\nDireccion: ");            //ingresa los datos
    gets(reg.direc);                    //abre el archivo ARCH
    printf("\nTelefono: ");             //guarda en ARCH
    gets(reg.tel);
    printf("\nMail: ");
    gets(reg.mail);
    printf("\nContrasenia: ");
    gets(reg.contra);
    arch=fopen(agend,"a");
    if(arch==NULL)
    {
        printf("\nEl archivo no pudo ser creado\n");
        exit(1);
    }
    fprintf(arch,"%s\n%s\n%s\n%s\n%s\n",reg.nombre,reg.direc,reg.tel,reg.mail,reg.contra);
    fprintf(arch,"\0");
    fclose(arch);
    printf("\n\nAgregado exitosamente!!!\n");
    printf("\nPresiona enter para continuar");
    getch();
}
buscar()
{
    printf("\nNombre: ");
    gets(reg.nombre);                       //Busca en ARCH el nombre escrito
    arch=fopen(agend,"r");                //si lo encuentra lo imprime y sale del ciclo
    if(arch==NULL)
    {
        printf("\nError!!!\n\n");
        getch();
        main();
    }
    system("cls");
    printf("\n\t\tBUSCAR\n\n");
    while(!feof(arch))                      //si no regresa al main
    {
        fscanf(arch,"%s\n%s\n%s\n%s\n%s\n",&reg1.nombre,&reg1.direc,&reg1.tel,&reg1.mail,&reg1.contra);
        if(strcmp(reg1.nombre,reg.nombre)==0)
        {
            printf("Nombre: %s\n",reg1.nombre);
            printf("Direccion: %s\n",reg1.direc);
            printf("Telefono: %s\n",reg1.tel);
            printf("Mail: %s\n",reg1.mail);
            printf("Contrasenia: %s\n\n",reg1.contra);
            break;
        }
    }
    fclose(arch);
    if(strcmp(reg.nombre,reg1.nombre)!=0)
    {
        printf("\nNo existe ese nombre\n");
    }
    printf("\nPresiona enter para continuar");
    getch();
}

modificar()
{
    printf("\n\t\tMODIFICAR\n\n");
    printf("\nEscribe tu nombre y contrasenia para poder modificar\n");
    printf("\nNombre: ");
    gets(reg.nombre);                           //Pide tu nombre y contraseña para modificar
    printf("\nContrasenia: ");                   //busca en ARCH y si son correctos continua
    gets(reg.contra);                           //si alguno es incorrecto regresa al main
    arch=fopen(agend,"r");
    if(arch==NULL)
    {
        printf("\nError!!!\n\n");
        getch();
        main();
    }
    while(!feof(arch))
    {
        fscanf(arch,"%s %s %s %s %s\n",&reg1.nombre,&reg1.direc,&reg1.tel,&reg1.mail,&reg1.contra);
        if(strcmp(reg.nombre,reg1.nombre)==0)
        if(strcmp(reg.contra,reg1.contra)==0)
        break;
    }
    fclose(arch);
    if(strcmp(reg.nombre,reg1.nombre)!=0 || strcmp(reg.contra,reg1.contra)!=0 )
    {
        printf("\nUsuario o contrasenia incorrecta!!! ");
        getch();
        main();
    }
    system("cls");
    arch=fopen(agend,"r");                  //Compara el nombre que leyo de ARCH
    copia=fopen(copy,"w");                  //y compara con el dado por el usuario
    while(!feof(arch))                      //y si son diferentes escribe en COPIA
    {
        fscanf(arch,"%s %s %s %s %s\n",&reg1.nombre,&reg1.direc,&reg1.tel,&reg1.mail,&reg1.contra);
        if(strcmp(reg.nombre,reg1.nombre)!=0)
        {
            fprintf(copia,"%s %s %s %s %s\n",reg1.nombre,reg1.direc,reg1.tel,reg1.mail,reg1.contra);
        }
    }
    fclose(arch);
    fclose(copia);

    printf("\n\t\tMODIFICAR\n\n");
    printf("\nRecuerda que en lugar de usar espacio( ) usa guion bajo ( _ )\n\n");
    printf("\nNombre nuevo: ");             //Ingresa datos nuevos
    gets(reg.nombre);                       //y agrega al archivo COPIA
    printf("\nDireccion nueva: ");
    gets(reg.direc);
    printf("\nTelefono nuevo: ");
    gets(reg.tel);
    printf("\nMail nuevo: ");
    gets(reg.mail);
    printf("\nContrasenia nueva: ");
    gets(reg.contra);
    copia=fopen(copy,"a");
    fprintf(copia,"%s %s %s %s %s\n",reg.nombre,reg.direc,reg.tel,reg.mail,reg.contra);
    fprintf(copia,"\0");
    fclose(copia);
    remove(agend);
    rename(copy,agend);
    printf("\nModificado con exito!!!");
    printf("\nPresiona enter para continuar");
    getch();
}
borrar()
{
    printf("\n\t\tBORRAR\n\n");
    printf("\nEscribe tu nombre y contrasenia para borrar\n");
    printf("\nNombre: ");
    gets(reg.nombre);                           //Pide tu nombre y contraseña para modificar
    printf("\nContraseña: ");                   //busca en ARCH y si son correctos continua
    gets(reg.contra);                           //si alguno es incorrecto regresa al main
    arch=fopen(agend,"r");
    if(arch==NULL)
    {
        printf("\nError!!!\n\n");
        getch();
        main();
    }
    while(!feof(arch))
    {
        fscanf(arch,"%s %s %s %s %s\n",&reg1.nombre,&reg1.direc,&reg1.tel,reg1.mail,&reg1.contra);
        if(strcmp(reg.nombre,reg1.nombre)==0)
        if(strcmp(reg.contra,reg1.contra)==0)
        break;
    }
    fclose(arch);
    if(strcmp(reg.nombre,reg1.nombre)!=0 || strcmp(reg.contra,reg1.contra)!=0 )
    {
        printf("\nUsuario o contrasenia incorrecta!!! ");
        getch();
        main();
    }
    arch=fopen(agend,"r");
    copia=fopen(copy,"w");                              //El nombre que deseas borrar
    if(arch==NULL)                                      //lo compara con todos los nombres de ARCH
    {                                                   //cuando son diferentes los escribe en COPIA
        printf("\nEl archivo no pudo ser creado\n");    //sino existe el nombre
        exit(1);                                        //regresa al main
    }
    while(!feof(arch))
    {
        fscanf(arch,"%s %s %s %s %s\n",&reg1.nombre,&reg1.direc,&reg1.tel,&reg1.mail,&reg1.contra);
        if(strcmp(reg.nombre,reg1.nombre)!=0)
            fprintf(copia,"%s %s %s %s %s\n",reg1.nombre,reg1.direc,reg1.tel,reg1.mail,reg1.contra);
    }
    fprintf(copia,"\0");
    fclose(arch);
    fclose(copia);
    remove(agend);                        //remueve ARCH
    rename(copy,agend);                   //renombra COPIA como ARCH
    printf("\nBorrado con exito!!!");
    printf("\nPresiona enter para continuar");
    getch();
}

agenda()
{
    int i;
    age aux;
    for(i=0; i<40; i++)
    {        aux.nombre[i]="";    }
    for(i=0; i<50; i++)
    {        aux.direc[i]="";    }
    for(i=0; i<31; i++)
    {        aux.tel[i]="";    }
    for(i=0; i<21; i++)
    {        aux.mail[i]="";    }

    printf("\n\t\tAGENDA\n\n");
    arch=fopen(agend,"r");
    if(arch==NULL)
    {
        printf("\nError!!!\n\n");
        getch();
        main();
    }
    while(!feof(arch))
    {                                   //Imprime en pantalla todo lo que este en ARCH
        fscanf(arch,"%s %s %s %s %s\n",&aux.nombre,&aux.direc,&aux.tel,&aux.mail,&aux.contra);
        printf("Nombre: %s\n",aux.nombre);
        printf("Direccion: %s\n",aux.direc);
        printf("Telefono: %s\n",aux.tel);
        printf("Mail: %s\n\n",aux.mail);
//        printf("Contrasenia: %s\n\n",reg1.contra);
    }
    fclose(arch);
    printf("\nPresiona enter para continuar");
    getch();
}

borrart()
{
    char seg,segu;
    arch=fopen(agend,"r");
    if(arch==NULL)
    {
        printf("\nError!!!\n\n");
        getch();
        main();
    }
    fclose(arch);
    printf("\nEstas seguro que deseas borrar todos los contactos? s/n: ");
    scanf("%s",&seg);
    if(seg=='s' || seg=='S')
    {
        printf("\nSeguro seguro que deseas borrar todos los contactos? s/n: ");
        scanf("%s",&segu);
        if(segu=='s' || segu=='S')
        {
            arch=fopen(agend,"w");
            printf(arch,"\0");
            fclose(arch);
            printf("\nContactos borrados con exito!!!\n\n");
        }
        else
        printf("\nLos contactos NO han sido borrados\n\n");
    }
    else
    printf("\nLos contactos NO han sido borrados\n\n");
    printf("\nPresiona enter para continuar");
    getch();
}

main()
{
    char resp,opc;
    do
    {
        regresa:
        system("cls");
        printf("\n\tAgenda telefonica\t\n");
        printf("\n1.-Ingresar contactos\n");
        printf("\n2.-Buscar\n");
        printf("\n3.-Modificar\n");
        printf("\n4.-Agenda\n");
        printf("\n5.-Borrar\n");
        printf("\n6.-Borrar todo\n");
        printf("\n7.-Salir\n");
        printf("\n\nElige una opcion y presione enter: ");
        scanf("%s",&opc);
        fflush(stdin);
        system("cls");
        switch(opc)
        {
            case '1':
                registro();
                break;
            case '2':
                buscar();
                break;
            case '3':
                modificar();
                break;
            case '4':
                agenda();
                break;
            case '5':
                borrar();
                break;
            case '6':
                borrart();
                break;
            case '7':
                printf("\n\nPONGANOS 10 !!!   :D\n\n");
                exit(1);

            default:
            goto regresa;
        }
    } while(opc);
}
