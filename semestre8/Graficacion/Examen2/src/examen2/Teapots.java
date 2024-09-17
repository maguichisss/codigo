package examen2;

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
 * @materia: Graficación por Computadora
 *
 * @grupo: 2803
 *
 * @fecha 27/05/2014
 *       
 */

public class Teapots implements GLEventListener{
    static GL gl;
    static GLU glu;
    static GLUT glut;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Teapots.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Teapots());
        frame.add(canvas);
        frame.setSize(820, 640);
        //final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {
                    public void run() {
                        //animator.stop();
                        System.exit(0);
                    }
                }).start();
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        //animator.start();
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
    }
    
    public void display(GLAutoDrawable drawable) {
        int i, j;
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);

renderTeapot(5.0f, 10.0f, 0.329412f, 0.223529f, 0.027451f, 0.780392f, 0.568627f, 0.113725f, 0.992157f, 0.941176f, 0.807843f, 0.21794872f);
renderTeapot(10.0f, 16.0f, 0.19225f, 0.19225f, 0.19225f, 0.50754f, 0.50754f, 0.50754f, 0.508273f, 0.508273f, 0.508273f, 0.4f);
renderTeapot(10.0f, 4.0f, 0.0f, 0.0f, 0.0f, 0.1f, 0.35f, 0.1f, 0.45f, 0.55f, 0.45f, 0.25f);
renderTeapot(15.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.7f, 0.6f, 0.6f, 0.25f);

        gl.glFlush();
    }
    
    void renderTeapot(  float x, float y,                       //position
            float ambr,  float ambg,  float ambb,   //ambient color
            float difr,  float difg,  float difb,   //difussion color
            float specr, float specg, float specb,  //specular color
            float shine){                           //shiness
        float matAmb[] ={ ambr,  ambg,  ambb, 1.0f};
        float matDif[] ={ difr,  difg,  difb, 1.0f};
        float matSpec[]={specr, specg, specb, 1.0f};
        gl.glPushMatrix();
        gl.glTranslated(x, y, 0.0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_AMBIENT, matAmb, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_DIFFUSE, matDif, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_SPECULAR, matSpec, 0);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 128.0f*shine);
        glut.glutSolidTeapot(2.5);
        gl.glPopMatrix();
    }
    
    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        gl.glViewport(0,0,width,height);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        gl.glOrtho(0.0f, 20.0f, 0.0f, 20.0f, -10.0f, 10.0f);
        gl.glMatrixMode(GL.GL_MODELVIEW);
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
    
    
}