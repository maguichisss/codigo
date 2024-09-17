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
 *
 *
 * @materia: Graficación por Computadora
 *
 * @grupo: 2803
 *
 * @fecha 27/05/2014
 * 
 *  left click --->  blue++
 *  right click --->  red++
 *  center click --->  green++
 *
 */

public class ColorMaterial implements GLEventListener, MouseListener {
    
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static int spin = 0;
    static float[] diffuse = { 1f,   1f,   1f, 1f};
        
    
    public static void main(String[] args) {
        Frame frame = new Frame("Using glColorMaterial()");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new ColorMaterial());
        canvas.addMouseListener(new ColorMaterial());
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
        float[] rgba = {1f, 1f, 1f};
        float[] ambient = {.1f, .1f, .1f};
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_AMBIENT, ambient, 0);
        gl.glMaterialfv(GL.GL_FRONT, GL.GL_SPECULAR, rgba, 0);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 50f);

        // Prepare light parameters.
        float[] lightPos = { 1, 1, 1, 0};
        float[] lightColorAmbient  = {  .1f,   .1f,   .1f, 1f};    //luz ambiental
        
        // Set light parameters.
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_POSITION, lightPos, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_AMBIENT, lightColorAmbient, 0);
        
        
        
        
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
        
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT );
        gl.glTranslatef(0.0f, 0.0f, -3.0f);
//---------------------------------------------------------------------------        
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_DIFFUSE, diffuse, 0);
        gl.glLightfv(GL.GL_LIGHT0, GL.GL_SPECULAR, diffuse, 0);
        // Enable lighting in GL.
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_DEPTH_TEST);
        
        gl.glColorMaterial(GL.GL_FRONT, GL.GL_DIFFUSE);
        gl.glEnable(GL.GL_COLOR_MATERIAL);
//---------------------------------------------------------------------------
        // Dibuja esfera
        final float radius = 1f;
        final int slices = 64;
        final int stacks = 64;
        glut.glutSolidSphere(radius, slices, stacks);
        gl.glFlush();
        
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}
    
    public void mouseClicked(MouseEvent me) {
        
        if (me.isMetaDown()) {
            if(diffuse[0]<1)
                diffuse[0] += .1f;
            else
                diffuse[0]=0;
            System.out.println("Derecho rojo="+diffuse[0]);      //rojo
            
        }else if(me.isAltDown()){
            if(diffuse[1]<1)
                diffuse[1] += .1f;
            else
                diffuse[1]=0;
            System.out.println("Centro verde="+diffuse[1]);       //verde
            
        }else if(me.isShiftDown()){
            System.out.println("Shift");       //verde     
            
        }else{
            if(diffuse[2]<1)
                diffuse[2] += .1f;
            else
                diffuse[2]=0;
            System.out.println("Izquierdo azul="+diffuse[2]);    //azul
            
        }
        
    }
    
    public void mousePressed(MouseEvent me) {}   
    public void mouseReleased(MouseEvent me) {}   
    public void mouseEntered(MouseEvent me) {}
    public void mouseExited(MouseEvent me) {}
}

