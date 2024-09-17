package examen2;

import com.sun.opengl.util.Animator;
import static com.sun.opengl.util.BufferUtil.newByteBuffer;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.nio.ByteBuffer;
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
 */

public class Checkerboard implements GLEventListener, KeyListener {
    GL gl;
    GLU glu = new GLU();
    GLUT glut = new GLUT();
    static char tecla;
    static float rotAngle = 0f;
    /* Create checkerboard texture */
    static final int checkImageWidth = 64;
    static final int checkImageHeight = 64;
    static ByteBuffer checkImage =
            newByteBuffer(checkImageHeight * checkImageWidth * 4);
    static int texName;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Antialiased Lines");
        GLCanvas canvas = new GLCanvas();
        
        canvas.addGLEventListener(new Checkerboard());
        canvas.addKeyListener(new Checkerboard());
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
//-------------------------------------------------------------
        gl.glShadeModel(GL.GL_FLAT);
        gl.glEnable(GL.GL_DEPTH_TEST);
        makeCheckImage();
        gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 1);
        gl.glBindTexture(GL.GL_TEXTURE_2D, texName);
        gl.glTexParameterf(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_S, GL.GL_REPEAT);
        gl.glTexParameterf(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_T, GL.GL_REPEAT);
        gl.glTexParameterf(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAG_FILTER, GL.GL_NEAREST);
        gl.glTexParameterf(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MIN_FILTER, GL.GL_NEAREST);   
        gl.glTexImage2D(GL.GL_TEXTURE_2D, 
                0, GL.GL_RGBA, checkImageWidth, checkImageHeight,
                0, GL.GL_RGBA, GL.GL_UNSIGNED_BYTE, checkImage);
        
        gl.glEnable(GL.GL_TEXTURE_2D);   
//-------------------------------------------------------------       
    }
    
    /* Draw 2 diagonal lines to form an X */
    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glTranslatef(0.0f, 0.0f, -6.0f);     
//--------------------------------------------------------------       
        gl.glEnable(GL.GL_TEXTURE_2D);
        gl.glTexEnvf(GL.GL_TEXTURE_ENV, GL.GL_TEXTURE_ENV_MODE, GL.GL_REPLACE);
        gl.glBindTexture(GL.GL_TEXTURE_2D, texName);
        gl.glBegin(GL.GL_QUADS);
        gl.glTexCoord2f(0.0f, 0.0f); gl.glVertex3f(-2.0f, -1.0f, 0.0f);
        gl.glTexCoord2f(0.0f, 1.0f); gl.glVertex3f(-2.0f,  1.0f, 0.0f);
        gl.glTexCoord2f(1.0f, 1.0f); gl.glVertex3f( 0.0f,  1.0f, 0.0f);
        gl.glTexCoord2f(1.0f, 0.0f); gl.glVertex3f( 0.0f, -1.0f, 0.0f);
        gl.glTexCoord2f(0.0f, 0.0f); gl.glVertex3f( 1.0f, -1.0f, 0.0f);
        gl.glTexCoord2f(0.0f, 1.0f); gl.glVertex3f( 1.0f,  1.0f, 0.0f);
        gl.glTexCoord2f(1.0f, 1.0f); gl.glVertex3f(2.41421f, 1.0f, -1.41421f);
        gl.glTexCoord2f(1.0f, 0.0f); gl.glVertex3f(2.41421f, -1.0f, -1.41421f);
        gl.glEnd();
        gl.glFlush();
        gl.glDisable(GL.GL_TEXTURE_2D);      
//--------------------------------------------------------------       
    }
    
    private void makeCheckImage() {
        byte c;// = (byte) 0xFF;
        
        for (int i = 0; i < checkImageWidth; i++) {
            for (int j = 0; j < checkImageHeight; j++) {
                // c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
                c =   (byte) (  (  (i & 0x8) == 0 ? 0x00 : 0xff)//
                        ^ (byte)    (  (j & 0x8) == 0 ? 0x00 : 0xff)   );
                
                checkImage.put((byte) c);
                checkImage.put((byte) c);
                checkImage.put((byte) c);
                checkImage.put((byte) c);
            }
        }
        checkImage.rewind();
    }
    
    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
        int c, i, j, bit=3;
        for (i = 0; i < checkImageHeight; i++) {
            for (j = 0; j < checkImageWidth; j++) {
                c = ( ((i&bit))^((j&bit))) ;
                if(c==bit)
                    System.err.print("* ");
                else
                    System.err.print("  ");
            }
            System.err.println("");
        }
        
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