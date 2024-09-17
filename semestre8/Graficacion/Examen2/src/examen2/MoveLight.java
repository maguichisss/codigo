package examen2;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
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

public class MoveLight implements GLEventListener, MouseListener {
    
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static int spin = 0;
    static float[] diffuse = { 1f,   1f,   1f, 1f};
        
    public static void main(String[] args) {
        Frame frame = new Frame("Moving a Light with Modeling Transformations");
        GLCanvas canvas = new GLCanvas();

        canvas.addGLEventListener(new MoveLight());
        canvas.addMouseListener(new MoveLight());
        frame.add(canvas);
        frame.setSize(640, 480);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                // Run this on another thread than the AWT event queue to
                // make sure the call to Animator.stop() completes before
                // exiting
                new Thread(new Runnable() {

                    public void run() {
                        animator.stop();
                        System.exit(0);
                    }
                }).start();
            }
        });
        // Center frame
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        animator.start();
    }

    public void init(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        
        gl.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        gl.glShadeModel(GL.GL_SMOOTH);
        
        // Enable lighting in GL.
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_DEPTH_TEST);
        
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
    
        if (height <= 0) { // avoid a divide by zero error!
        
            height = 1;
        }
        final float h = (float) width / (float) height;
        gl.glViewport(0, 0, width, height);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluPerspective(45.0f, h, 1.0, 20.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
    }

    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();

        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glPushMatrix();
        gl.glTranslatef(0.0f, 0.0f, -5.0f);
        gl.glPushMatrix();
        gl.glRotated(spin, 0.0, 1.0, 0.0);
        
        float[] position = { 0.0f, 0.0f, 2.5f, 1.0f };
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, position, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, diffuse, 0);
        gl.glTranslated(0.0, 0.0, 2.5);
        gl.glDisable(GL.GL_LIGHTING);
        
        gl.glColor3f(1.0f, 0.0f, 0.0f);
        glut.glutSolidCube(0.1f);
        gl.glEnable(GL.GL_LIGHTING);
        gl.glPopMatrix();
        
        gl.glColor3f(0.0f, 1.0f, 1.0f);
        glut.glutSolidTorus(0.275, 0.85, 32, 32);
        gl.glPopMatrix();
        gl.glFlush();
        
        spin = (spin + 1) % 360;
        
        //color cada 120 grados
        
        if(spin%360<=120){
                diffuse[0] = 0.2f;
                diffuse[1] = 1f;
                diffuse[2] = 0.2f;
            }else if(spin%360>=240){
                diffuse[0] = 0.2f;
                diffuse[1] = 0.2f;
                diffuse[2] = 1f;
            }else{
                diffuse[0] = 1f;
                diffuse[1] = 0.2f;
                diffuse[2] = 0.2f;
            }
        
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}

    public void mouseClicked(MouseEvent me) {
        
        spin = (spin + 30) % 360;
        System.out.println("x: "+spin);
        
    }

    public void mousePressed(MouseEvent me) {
        
    }

    public void mouseReleased(MouseEvent me) {
        
    }

    public void mouseEntered(MouseEvent me) {
        
    }

    public void mouseExited(MouseEvent me) {
        
    }
}

