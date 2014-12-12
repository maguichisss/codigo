#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include <time.h>
#define nColors 12
int k=1;
float colors[nColors][3];

void inicializa()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    int i;
    for(i=0; i<nColors; i++){
        colors[i][0] = ((float)rand()/(float)(RAND_MAX)) * 1;
        colors[i][1] = ((float)rand()/(float)(RAND_MAX)) * 1;
        colors[i][2] = ((float)rand()/(float)(RAND_MAX)) * 1;
    }
}

void plano()
{
    glLineWidth(1);
    glBegin(GL_LINE);
    glColor3f(1,1,1);
    glVertex2f(0,100);
    glVertex2f(0,-100);
    glEnd();
    glBegin(GL_LINE);
    glColor3f(1,1,1);
    glVertex2f(-100,0);
    glVertex2f(100,0);
    glEnd();
}


void fun()
{
    float i;
    glBegin(GL_LINE_STRIP);
    glColor3f(colors[k%nColors][0],colors[k%nColors][1],colors[k%nColors][2]);

    for(i=-10; i<10; i+=.1)
        glVertex2f(    10*cos(i*k),  10*sin(i*k)   );

    glEnd();
    glutSwapBuffers();















/*
     glBegin(GL_LINE_STRIP);
     glColor3f(0,1,0);
     for(i=-10; i<10; i+=.1)
     {
         glVertex2f  (5*cos(i)  , 10*sin(i*2)      );
     }
     glEnd();

     glBegin(GL_LINE_STRIP);
     glColor3f(1,1,0);
     for(i=-10; i<10; i+=.01)
     {
         glVertex2f  (i  ,   pow(i,10)-1       );
     }
     glEnd();

     glBegin(GL_LINE_STRIP);
     glColor3f(0,0,1);
     for(i=-10; i<10; i+=.1)
     {
         glVertex2f  (10*cos(i/6)  , 10*sin(i/6)      );
     }
     glEnd();
*/
}

void dibuja()
{
    glClear(GL_COLOR_BUFFER_BIT);/*sirve para limpiar el buffer*/
    glMatrixMode(GL_MODELVIEW);/*establece el modo de la textura*/
    glLoadIdentity();
    //plano();
    fun();
    glutSwapBuffers();
}

void tecladoEspecial (int key, int cx, int cy)
{

	switch(key)
	{
		case GLUT_KEY_UP:
             k++;
		break;

		case GLUT_KEY_DOWN:
             k--;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,550);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("FUNciones Grafiquitas");
    glutDisplayFunc(dibuja);
    inicializa();
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}
