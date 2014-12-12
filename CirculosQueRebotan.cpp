#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <time.h>
#define Delta 4.0
#define total 1000
#define r 10

void inicializa(void);
//void tecladoEspecial (int key, int cx, int cy);
void dibuja(void);
void traslacion(void);
void Circulo(float);
void linea(void);
int ran,ran1;
float angulo;
float traslada[total][2];
float C[total][2];
float colors[total][3];

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("CIRCULO");
    glutDisplayFunc(dibuja);
    //glutSpecialFunc(tecladoEspecial);
    inicializa();
    glutIdleFunc(traslacion);
    glutMainLoop();
    return 0;
}

void inicializa(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);

    int i;
    for(i=0; i<total; i++){
        traslada[i][0] = -310 + rand()%620;
        traslada[i][1] = -230 + rand()%460;
        C[i][0]=C[i][1] = 1+rand()%10;
        colors[i][0] = ((float)rand()/(float)(RAND_MAX)) * 1;
        colors[i][1] = ((float)rand()/(float)(RAND_MAX)) * 1;
        colors[i][2] = ((float)rand()/(float)(RAND_MAX)) * 1;
    }
}

void dibuja(){
    glClear(GL_COLOR_BUFFER_BIT);/*sirve para limpiar el buffer*/
    glMatrixMode(GL_MODELVIEW);/*establece el modo de la textura*/
    glLoadIdentity();
    Circulo(r);
    //linea();
    glutSwapBuffers();
}

void linea(){
/*
     glLineWidth(1.0);
     glBegin(GL_LINE_STRIP);
     glColor3f(1.0,1.0,1.0);
     glVertex2f(ran1,trasladay);
     glVertex2f(0,0);
     glEnd();
     glBegin(GL_LINE_STRIP);
     glColor3f(1.0,0.0,1.0);
     glVertex2f(trasladax,trasladay);
     glVertex2f(0,0);
     glEnd();
     */
}

void Circulo(float radio)
{
     glClear(GL_COLOR_BUFFER_BIT);
     float delta,angulo;
     int i,j;
     float x,y;
     delta=2*3.1416/360;
     angulo=0.0;

     for(j=0; j<total; j++){
         glBegin(GL_POLYGON);
         glColor3f(colors[j][0],colors[j][1],colors[j][2]);
         for(i=0;i<360;i++)
         {
            x=radio*cos(angulo)+traslada[j][0];
            y=radio*sin(angulo)+traslada[j][1];
            angulo+=delta;
            glVertex2f(x,y);
         }
         glEnd();
     }

     glutSwapBuffers();

}


void traslacion(void)
{
    int i;
    for(i=0; i<total; i++){
        traslada[i][0]+=C[i][0];
        traslada[i][1]+=C[i][1];
        glutPostRedisplay();
        if(traslada[i][0]>=320-r)
        {     C[i][0]=-C[i][0];}
        if(traslada[i][1]>=240-r)
        {     C[i][1]=-C[i][1];}
        if(traslada[i][0]<=-320+r)
        {     C[i][0]=-C[i][0];}
        if(traslada[i][1]<=-240+r)
        {     C[i][1]=-C[i][1];}
    }
    glutPostRedisplay();
}

void tecladoEspecial (int key, int cx, int cy)
{
/*
	switch(key)
	{
		case GLUT_KEY_RIGHT:
             if (CX<0)CX=-CX;
             trasladax += CX;
		break;

		case GLUT_KEY_LEFT:
             if (CX>0)CX=-CX;
			trasladax -= CX;
		break;

		case GLUT_KEY_UP:
             if (CY<0) CY=-CY;
  			 trasladay += CY;
		break;

		case GLUT_KEY_DOWN:
             if (CY>0)
             CY=-CY;
			trasladay -= CY;
		break;
	}
	glutPostRedisplay();
	*/
}

