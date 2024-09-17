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
 * @materia: Graficación por Computadora
 *
 * @grupo: 2803
 *
 * @fecha 27/05/2014
 *       
 */

public class PiramideSierpinsky implements GLEventListener, KeyListener {

    static GL gl;
    static GLU glu;
    static GLUT glut;
    static int RECURSTION_DEPTH=9;
    static double vistaX, vistaY, vistaZ;
        
    public static void main(String[] args) {
        Frame frame = new Frame("Moving a Light with Modeling Transformations");
        GLCanvas canvas = new GLCanvas();

        canvas.addGLEventListener(new PiramideSierpinsky());
        canvas.addKeyListener(new PiramideSierpinsky());
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
        glu = new GLU();
        gl.glEnable (GL.GL_DEPTH_TEST);
        vistaX = 0.8;
        vistaY = 0.8;
        vistaZ = 0.8;
        gl.glClearColor (1.0f, 1.0f, 1.0f,0);
        gl.glPointSize (1);
    }
    
    public void display(GLAutoDrawable drawable) {
        float[] vertex1 = {0.0f, 2.5f, 5.0f};
        float[] vertex2 = {5.0f, 0.0f, 0.0f};
        float[] vertex3 = {-5.0f, 0.0f, 0.0f};
        float[] vertex4 = {0.0f, 5.0f, 0.0f};
        
        gl.glLoadIdentity();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glMatrixMode (GL.GL_PROJECTION);
        gl.glLoadIdentity();
        gl.glOrtho (-6.0, 6.0, -2.5, 6.0, -6.0, 6.0);
        glu.gluLookAt(vistaX, vistaY, vistaZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        gl.glMatrixMode (GL.GL_MODELVIEW);
        piramideS (vertex1, vertex2, vertex3, vertex4, 0);
        gl.glFlush();
    }
    
    void piramideS (float vertex1[], float vertex2[], float vertex3[], float vertex4[], int current_depth){
        
        float[] new_vertex1 = new float [3];
        float[] new_vertex2 = new float [3];
        float[] new_vertex3 = new float [3];
        float[] new_vertex4 = new float [3];
        float[] new_vertex5 = new float [3];
        float[] new_vertex6 = new float [3];
        
        if (current_depth >= RECURSTION_DEPTH)
            return;
        
        gl.glBegin (GL.GL_POINTS);
        gl.glColor3f (1.0f, 0.0f, 1.0f);
        gl.glVertex3fv(vertex1, 0);
        
        
        gl.glColor3f (1.0f, 0.0f, 1.0f);
        gl.glVertex3fv (vertex2,0);
        
        gl.glColor3f (0.0f, 0.0f, 1.0f);
        gl.glVertex3fv (vertex3,0);
        
        gl.glColor3f (0.0f, 0.0f, 1.0f);
        gl.glVertex3fv (vertex4,0);
        gl.glEnd();
        
        new_vertex1[0] = (vertex1[0]+vertex2[0])/2;
        new_vertex1[1] = (vertex1[1]+vertex2[1])/2;
        new_vertex1[2] = (vertex1[2]+vertex2[2])/2;
        
        new_vertex2[0] = (vertex1[0]+vertex3[0])/2;
        new_vertex2[1] = (vertex1[1]+vertex3[1])/2;
        new_vertex2[2] = (vertex1[2]+vertex3[2])/2;
        
        new_vertex3[0] = (vertex1[0]+vertex4[0])/2;
        new_vertex3[1] = (vertex1[1]+vertex4[1])/2;
        new_vertex3[2] = (vertex1[2]+vertex4[2])/2;
        
        new_vertex4[0] = (vertex2[0]+vertex3[0])/2;
        new_vertex4[1] = (vertex2[1]+vertex3[1])/2;
        new_vertex4[2] = (vertex2[2]+vertex3[2])/2;
        
        new_vertex5[0] = (vertex2[0]+vertex4[0])/2;
        new_vertex5[1] = (vertex2[1]+vertex4[1])/2;
        new_vertex5[2] = (vertex2[2]+vertex4[2])/2;
        
        new_vertex6[0] = (vertex3[0]+vertex4[0])/2;
        new_vertex6[1] = (vertex3[1]+vertex4[1])/2;
        new_vertex6[2] = (vertex3[2]+vertex4[2])/2;
        
        piramideS (vertex1, new_vertex1, new_vertex2, new_vertex3, current_depth+1);
        piramideS (vertex2, new_vertex1, new_vertex4, new_vertex5, current_depth+1);
        piramideS (vertex3, new_vertex2, new_vertex4, new_vertex6, current_depth+1);
        piramideS (vertex4, new_vertex3, new_vertex5, new_vertex6, current_depth+1);
        
    }
    
    public void keyPressed(KeyEvent ke) {
        double xAntes, yAntes,zAntes;
        int codigo;
        xAntes = vistaX;
        yAntes = vistaY;
        zAntes = vistaZ;
        codigo = ke.getKeyCode();
        
        System.out.println(codigo);
        
        switch(codigo){
            case KeyEvent.VK_LEFT: 
                vistaX = rotaX(xAntes,zAntes,-Math.PI/10);
                vistaZ = rotaZ(xAntes,zAntes,-Math.PI/10);
            break;
                
            case KeyEvent.VK_RIGHT: 
                vistaX = rotaX(xAntes,zAntes,Math.PI/10);
                vistaZ = rotaZ(xAntes,zAntes,Math.PI/10);
            break;
                
            case KeyEvent.VK_DOWN: 
                vistaY = rotaX(yAntes,zAntes,-Math.PI/10);
                vistaZ = rotaZ(yAntes,zAntes,-Math.PI/10);
            break;
                
            case KeyEvent.VK_UP: 
                vistaY = rotaX(yAntes,zAntes,Math.PI/10);
                vistaZ = rotaZ(yAntes,zAntes,Math.PI/10);
            break;
                
            default: break;
        }
    }
    
    double rotaX(double x, double z, double t){
        return(x*Math.cos(t)-z*Math.sin(t));
    }    
    double rotaZ(double x, double z, double t){
        return(x*Math.sin(t)+z*Math.cos(t));
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

