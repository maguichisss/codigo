package examen2;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
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
 *
 *
 * @materia: Graficación por Computadora
 *
 * @grupo: 2803
 *
 * @fecha 27/05/2014
 *
 * The following keys change the selected blend equation mode
 *
 *       't' -> changes triangle
 */

public class Alpha implements GLEventListener, KeyListener {
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static char tecla;
    static boolean leftFirst = true;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Blending Example");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new Alpha());
        canvas.addKeyListener(new Alpha());
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
        gl.glBlendFunc(GL.GL_SRC0_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA);
        gl.glEnable(GL.GL_BLEND);
        gl.glShadeModel(GL.GL_FLAT);
        
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
        gl.glLoadIdentity();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        gl.glTranslatef(0.0f, 0.0f, -6.0f);
        
        if (leftFirst) {
            drawLeftTriangle();
            drawRightTriangle();
        }else {
            drawRightTriangle();
            drawLeftTriangle();
        }
        gl.glFlush();

        
    }
    
    public void drawLeftTriangle(){
        /* draw yellow triangle on LHS of screen */
        gl.glBegin(GL.GL_TRIANGLES);
        gl.glColor4f(1.0f, 1.0f, 0.0f, 0.75f);
        gl.glVertex3f(-1f, -1f, 0.0f);
        gl.glVertex3f(-1f,  1f, 0.0f);
        gl.glVertex3f( 1f,  0f, 0.0f);
        gl.glEnd();
    }
    
    public void drawRightTriangle(){
        /* draw cyan triangle on RHS of screen */
        gl.glBegin(GL.GL_TRIANGLES);
        gl.glColor4f(0.0f, 1.0f, 1.0f, 0.75f);
        gl.glVertex3f( 1f,  1f, 0.0f);
        gl.glVertex3f( 1f, -1f, 0.0f);
        gl.glVertex3f(-1f,  0f, 0.0f);
        gl.glEnd();
    }
    
    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
        switch(tecla){
            case 't': case 'T':
                leftFirst = !leftFirst;
                if(leftFirst)
                    System.err.println("Azul---right");
                else
                    System.err.println("Amarillo---left");
                break;
                
            case 27: /* Escape key */
                System.exit(0);
                break;
                
            default:
                break;
                
        }
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
    public void keyTyped(KeyEvent ke) {}
    public void keyReleased(KeyEvent ke) {}
}