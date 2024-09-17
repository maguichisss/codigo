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
 *       'a' -> GL.GL_FUNC_ADD
 *       's' -> GL.GL_FUNC_SUBTRACT
 *       'r' -> GL.GL_FUNC_REVERSE_SUBTRACT
 *       'm' -> GL_MIN
 *       'x' -> GL_MAX
 */

public class BlendEqn implements GLEventListener, KeyListener {
    
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static char tecla;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Demonstrating the Blend Equation Modes");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new BlendEqn());
        canvas.addKeyListener(new BlendEqn());
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
        
        gl.glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
        gl.glBlendFunc(GL.GL_ONE, GL.GL_ONE);
        gl.glEnable(GL.GL_BLEND);
        
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
        
        gl.glTranslatef(0.0f, 0.0f, -6.0f);
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        gl.glColor3f(0.0f, 0.0f, 1.0f);
        gl.glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
        
        switch(tecla){
            case 'a':
                /* Colors are added as: (1,1,0) + (0,0,1) = (1,1,1) which
                * will produce a white square on a yellow background. */
                gl.glBlendEquation(GL.GL_FUNC_ADD);
            break;
            case 's': case 'S':
                /* Colors are subtracted as: (0,0,1) - (1,1,0) = (-1,-1,1)
                * which is clamped to (0, 0, 1), producing a blue square
                * on a yellow background. */
                gl.glBlendEquation(GL.GL_FUNC_SUBTRACT);
            break;
            case 'r': case 'R':
                /* Colors are subtracted as: (1,1,0) - (0,0,1) = (1,1,-1)
                * which is clamped to (1, 1, 0). This produces yellow for
                * both the square and the background. */
                gl.glBlendEquation(GL.GL_FUNC_REVERSE_SUBTRACT);
            break;
            case 'm': case 'M':
                /* The minimum of each component is computed, as
                * [min(1,0),min(1,0),min(0,1)] which equates to (0,0,0).
                * This will produce a black square on the yellow
                * background. */
                gl.glBlendEquation(GL.GL_MIN);
            break;
            case 'x': case 'X':
                /* The minimum of each component is computed, as
                * [max(1, 0), max(1, 0), max(0, 1)] which equates to
                * (1, 1, 1). This will produce a white square on the
                * yellow background. */
                gl.glBlendEquation(GL.GL_MAX);
            break;
                
            case 27:
                System.exit( 0 );
            break;     
                
        }
        gl.glFlush();
        
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
    
    public void keyTyped(KeyEvent ke) {
        
    }
    
    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
    }
    
    public void keyReleased(KeyEvent ke) {}
}