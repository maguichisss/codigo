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
 *       'r' -> rotate
 */

public class AntialiasedLines implements GLEventListener, KeyListener {
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static char tecla;
    static float rotAngle = 0f;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Antialiased Lines");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new AntialiasedLines());
        canvas.addKeyListener(new AntialiasedLines());
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
       
        float values[] = { 0.5f, 0.5f, 0.5f};
        gl.glGetFloatv(GL.GL_LINE_WIDTH_GRANULARITY, values, 0);
        System.err.printf("GL_LINE_WIDTH_GRANULARITY value is %3.1f\n",values[0]);
        gl.glGetFloatv(GL.GL_LINE_WIDTH_RANGE, values, 0);
        System.err.printf("GL_LINE_WIDTH_RANGE values are %3.1f %3.1f\n",values[0], values[1]);
        gl.glEnable(GL.GL_LINE_SMOOTH);
        gl.glEnable(GL.GL_BLEND);
        gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA);
        gl.glHint(GL.GL_LINE_SMOOTH_HINT, GL.GL_DONT_CARE);
        gl.glLineWidth(2.5f);

        
    }
    
    /* Draw 2 diagonal lines to form an X */
    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glTranslatef(0.0f, 0.0f, -6.0f);
        
//--------------------------------------------------------------        
        
        gl.glColor3f(0.0f, 1.0f, 0.0f);
        gl.glPushMatrix();
        gl.glRotatef(-rotAngle, 0.0f, 0.0f, 0.1f);
        gl.glBegin(GL.GL_LINES);
        gl.glVertex2f(-2f, 2f);
        gl.glVertex2f( 2f, -2f);
        gl.glEnd();
        gl.glPopMatrix();

        gl.glColor3f(0.0f, 0.0f, 1.0f);
        gl.glPushMatrix();
        gl.glRotatef(rotAngle, 0.0f, 0.0f, 0.1f);
        gl.glBegin(GL.GL_LINES);
        gl.glVertex2f( 2f, 2f);
        gl.glVertex2f(-2f, -2f);
        gl.glEnd();
        gl.glPopMatrix();
  
//--------------------------------------------------------------        
        gl.glFlush();
    
    }
    
    public void dibujaCubo(){}
    
    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
        
        switch(tecla){
            case 'r': case 'R':
                rotAngle += 20;
                if (rotAngle >= 360) 
                    rotAngle = 0;
                System.err.println("Angle:  "+rotAngle);
                
                break;
            case 27: /* Escape key */
                System.exit(0);
                break;
                
            default:
                break;
                
        }
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
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
    public void keyTyped(KeyEvent ke) {}
    public void keyReleased(KeyEvent ke) {}
}