package examen2;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

/**
 *
 * @author
 * Garces Brito Mauricio I.
 * Tavares Vázquez Carolina
 *
 * @materia Graficación por Computadora
 *
 * @grupo 2803
 *
 * @fecha 25/05/2014.
 *
 */

public class Mandelbrot3D implements GLEventListener{
    static GL gl;
    static GLU glu;
    static GLUT glut;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Mandelbrot3D.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Mandelbrot3D ());
        frame.add(canvas);
        frame.setSize(640, 480);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {
                    public void run() {
                        animator.stop();
                        System.exit(0);
                    }
                }).start();
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        animator.start();
    } //Fin del main
    
    public void init(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        glu = new GLU();
        glut = new GLUT();
        float ambiente[] = {0.0f,0.0f,0.0f,1.0f};
        float difuso[] = {1.0f,1.0f,1.0f,1.0f};
        float posicion[] = {0.0f,3.0f,3.0f,0.0f};
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, ambiente, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, difuso, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, posicion, 0);
        gl.glFrontFace(GL.GL_CW);
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_NORMALIZE);
        gl.glEnable(GL.GL_DEPTH_TEST);
        gl.glClearColor(1, 1, 1, 1);
    }
    
    public void display(GLAutoDrawable drawable) {
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();
        //gl.glTranslatef(0.0f, 0.0f, -6.0f);
        dibujaMandelbrot3D();
        gl.glFlush();
    }
    
    int mandel(Complejo c, Complejo z, int n){
        int r;
        if ((z.abs()<2.0) && (n<100)){
            z.mult(z);
            z.suma(c);
            r = mandel(c,z,n+1);
        } else{
            r = n;
        }
        return r;
    }
    
    void dibujaMandelbrot3D(){
        Complejo z,c;
        int color;
        double x,y,w;
        float ambiente[] = {0.329f,0.225f,0.027f,1.0f};
        float difuso[] = {0.78f,0.568f,0.113f,1.0f};
        float especular[] = {0.992f,0.941f,0.807f,1.0f};
        glu.gluLookAt(  1.0, 1.0, 1.0, 
                        0.0, 0.0, 0.0, 
                        0.0, 0.5, 0.0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_AMBIENT, ambiente, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_DIFFUSE, difuso, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_SPECULAR, especular, 0);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 128.0f*0.21794f);
        gl.glBegin (GL.GL_POINTS);
        for (x=-2.0;x<=2.2;x+=0.1){
            for (y=-2.0;y<=2.2;y+=0.1){
                z = new Complejo(0.0,0.0);
                c = new Complejo(x,y);
                color = mandel (c,z,0)%5;
                w = color/5.0;
                switch (color){
                    case 0:gl.glColor3f(1.0f, 0.0f, 0.0f);//rojo
                    break;
                    case 1:gl.glColor3f(0.0f, 1.0f, 0.0f);//verde
                    break;
                    case 2:gl.glColor3f(0.0f, 0.0f, 1.0f);//azul
                    break;
                    case 3:gl.glColor3f(1.0f, 1.0f, 0.0f);//amarillo
                    break;
                    case 4:gl.glColor3f(1.0f, 0.0f, 1.0f);//rosa
                    break;
                }
                gl.glPushMatrix();
                gl.glTranslated(x, w, y);
                glut.glutSolidSphere(0.1, 20, 7);
                gl.glPopMatrix();
                gl.glPushMatrix();
                gl.glTranslated(x, w, y);//glut.glutWireSphere(3, 20, 7);
                gl.glPopMatrix();}
        }
        gl.glEnd ();
        gl.glFlush ();
    }
    
    public void reshape(GLAutoDrawable drawable, int
            x, int y, int width, int height) {
        gl.glViewport(0,0,width,height);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        gl.glOrtho(-3.0,3.0,-3.0,3.0,-3.0,3.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
} // Fin de la Clase