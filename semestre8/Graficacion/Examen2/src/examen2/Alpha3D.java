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
 *       'a' -> start animation
 *       'r' -> restart animation
 *       'p' -> pause animation
 */

public class Alpha3D implements GLEventListener, KeyListener {
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static char tecla;
    static boolean animar = false;
    static final float MAXZ = 0.0f;
    static final float MINZ =  -18.0f;
    static final float ZINC  = 0.1f;
    static float solidZ = MAXZ;
    static float transparentZ = MINZ;
    static int sphereList, cubeList;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Three-Dimensional Blending");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new Alpha3D());
        canvas.addKeyListener(new Alpha3D());
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
        
        // Set material properties.
        float[] specular = {1f, 1f, 1f};
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_SPECULAR, specular, 0);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 100f);
        
        // Prepare light parameters.
        float[] lightPos = { 1.0f, 1.0f, 1f, 0f};
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, lightPos, 0);
        
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_DEPTH_TEST);
        sphereList = gl.glGenLists(1);
        gl.glNewList(sphereList, GL.GL_COMPILE);
        glut.glutSolidSphere(0.4, 32, 32);
        gl.glEndList();
        cubeList = gl.glGenLists(1);
        gl.glNewList(cubeList, GL.GL_COMPILE);
        glut.glutSolidCube(1f);
        gl.glEndList();
        
    }
    
    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glLoadIdentity();
        gl.glTranslatef(0.0f, 0.0f, 0.0f);
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        
//--------------------------------------------------------------        
        dibujaEsfera();
        dibujaCubo();
        if(animar)
            animate();
        
//--------------------------------------------------------------        
        gl.glFlush();
        
        
    }
    
    public void dibujaCubo(){
        float mat_transparent[] = { 0.0f, 0.8f, 0.8f, 0.6f };
        float mat_emission[] = { 0.0f, 0.3f, 0.3f, 0.6f };
        gl.glPushMatrix();
            gl.glTranslatef( 0.15f, 0.15f, transparentZ);
            gl.glRotatef(15.0f, 1.0f, 1.0f, 0.0f);
            gl.glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
            gl.glMaterialfv(GL.GL_FRONT, GL.GL_EMISSION, mat_emission, 0);
            gl.glMaterialfv(GL.GL_FRONT, GL.GL_DIFFUSE, mat_transparent, 0);
            gl.glEnable(GL.GL_BLEND);
            gl.glDepthMask(false);
            gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE);
            gl.glCallList(cubeList);
            gl.glDepthMask(true);
            gl.glDisable(GL.GL_BLEND);
        gl.glPopMatrix();
    }
    
    public void dibujaEsfera(){
        float mat_solid[] = { 0.75f, 0.75f, 1.0f, 1.0f };
        float mat_zero[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        gl.glPushMatrix();
            gl.glTranslatef( 0.15f, 0.15f, solidZ);
            gl.glMaterialfv(GL.GL_FRONT, GL.GL_EMISSION, mat_zero, 0);
            gl.glMaterialfv(GL.GL_FRONT, GL.GL_DIFFUSE, mat_solid, 0);
            gl.glEnable(GL.GL_BLEND);
            gl.glDepthMask(false);
            gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE);
            gl.glCallList(sphereList);
            //gl.glDepthMask(true);
            gl.glDisable(GL.GL_BLEND);
        gl.glPopMatrix();
    }
    
    public void animate(){
        if (solidZ <= MINZ || transparentZ >= MAXZ){
            solidZ = MAXZ;
            transparentZ = MINZ;
        }
        else {
            solidZ -= ZINC;
            transparentZ += ZINC;
        }
    }
    
    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
        System.err.println("solidZ___"+solidZ);
        System.err.println("transparentZ___"+transparentZ);
        
        switch(tecla){
            case 'a': case 'A':
                animar = true;
                break;
            case 'r': case 'R':
                solidZ = MAXZ;
                transparentZ = MINZ;
                break;
            case 'p': case 'P':
                animar = false;
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