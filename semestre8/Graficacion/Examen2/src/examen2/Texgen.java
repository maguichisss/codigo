package examen2;

import com.sun.opengl.util.*;
import static com.sun.opengl.util.BufferUtil.newByteBuffer;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.*;
import java.nio.*;
import javax.media.opengl.*;
import javax.media.opengl.glu.GLU;
import javax.swing.*;

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

public class Texgen extends JFrame implements GLEventListener, KeyListener {
    GL gl;
    GLU glu;
    GLUT glut;
    
    private static final int stripeImageWidth = 32;
    private final byte stripeImage[] = new byte[3 * stripeImageWidth];
    private final ByteBuffer stripeImageBuf = newByteBuffer(stripeImage.length);
    private final float sgenparams[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    
    public static void main(String[] args) {
        Frame frame = new Frame("Textgen.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Texgen());
        canvas.addKeyListener(new Texgen());
        frame.add(canvas);
        frame.setSize(820, 640);
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
        gl.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        
        makeStripeImage();
        gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 1);
        gl.glTexEnvf(GL.GL_TEXTURE_ENV, GL.GL_TEXTURE_ENV_MODE, GL.GL_MODULATE);
        gl.glTexParameterf(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_WRAP_S, GL.GL_REPEAT);
        gl.glTexParameterf(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_MAG_FILTER, GL.GL_LINEAR);
        gl.glTexParameterf(GL.GL_TEXTURE_1D, GL.GL_TEXTURE_MIN_FILTER, GL.GL_LINEAR);
        gl.glTexImage1D(GL.GL_TEXTURE_1D, 
                0, 3, stripeImageWidth, 
                0, GL.GL_RGB, GL.GL_UNSIGNED_BYTE, stripeImageBuf);
        
        gl.glTexGeni(GL.GL_S, GL.GL_TEXTURE_GEN_MODE, GL.GL_OBJECT_LINEAR);
        gl.glTexGenfv(GL.GL_S, GL.GL_OBJECT_PLANE, sgenparams, 0);
        
        gl.glEnable(GL.GL_DEPTH_TEST);
        gl.glDepthFunc(GL.GL_LESS);
        gl.glEnable(GL.GL_TEXTURE_GEN_S);
        gl.glEnable(GL.GL_TEXTURE_1D);
        gl.glEnable(GL.GL_CULL_FACE);
        gl.glEnable(GL.GL_LIGHTING);
        gl.glEnable(GL.GL_LIGHT0);
        gl.glEnable(GL.GL_AUTO_NORMAL);
        gl.glEnable(GL.GL_NORMALIZE);
        gl.glFrontFace(GL.GL_CW);
        gl.glCullFace(GL.GL_BACK);
        gl.glMaterialf(GL.GL_FRONT, GL.GL_SHININESS, 64.0f);
    }

    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glPushMatrix();
        gl.glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glut.glutSolidTeapot(2.0f);
        gl.glPopMatrix();
        gl.glFlush();
    }
    
    private void makeStripeImage() {
        for (int j = 0; j < stripeImageWidth; j++) {
            stripeImageBuf.put(((j <= 4) ? (byte) 255 : (byte) 0));
            stripeImageBuf.put(((j > 4) ? (byte) 255 : (byte) 0));
            stripeImageBuf.put((byte) 0);
        }
        stripeImageBuf.rewind();
    }
    
    public void keyPressed(KeyEvent key) {
        switch (key.getKeyCode()) {
            case KeyEvent.VK_ESCAPE:
                System.exit(0);
                break;
                
            default:
                break;
        }
    }
    
    public void reshape(GLAutoDrawable drawable, int x, int y, int w, int h) {
        gl = drawable.getGL();        //
        gl.glViewport(0, 0, w, h);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        if (w <= h)
            gl.glOrtho(-3.5, 3.5, -3.5 * (float) h / (float) w, 3.5 * (float) h
                    / (float) w, -3.5, 3.5);
        else
            gl.glOrtho(-3.5 * (float) w / (float) h, //
                    3.5 * (float) w / (float) h, -3.5, 3.5, -3.5, 3.5);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
    }
    
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {}
    public void keyTyped(KeyEvent key) {}
    public void keyReleased(KeyEvent key) {}
    public void dispose(GLAutoDrawable arg0) {}
    
}