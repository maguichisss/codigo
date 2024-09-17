package examen2;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;
import java.awt.Frame;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
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
 *  'i' --->  la flecha rota a la izquierda
 *  'd' --->  la flecha rota a la derecha
 *  's' --->  inicia el movimiento
 *  'p' --->  pausa el movimiento
 *  'r' --->  reinicia
 *  'q' --->  salir
 *
 */

public class Flecha implements GLEventListener,  KeyListener, MouseListener {
    GL gl;
    GLU glu;
    GLUT glut;
    float v,a;
    static float angulo, t;
    static int blancoX, blancoY, move;
    static boolean translate;
    
    public static void main(String[] args) {
        Frame frame = new Frame("Flecha.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Flecha());
        canvas.addKeyListener(new Flecha());
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
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        
        a = -9.81f;
        v = 150;
        t = 0;
        angulo = 0;
        blancoX=500;
        blancoY=500;
        translate=false;
        move=0;
        
    }
    
    public void display(GLAutoDrawable drawable) {
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        
        dibujaFlecha();
        
        gl.glFlush();
        
    }
    
    void dibujaFlecha(){
        if(translate)
            move++;
        
        //flecha
        gl.glPushMatrix();
        gl.glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        gl.glTranslatef(0.0f, move, 0.0f);
        gl.glColor3f(0.8f, 0.0f, 0.0f);     //Rectangulo rojo
        gl.glRectf(10,0,20,100);
        gl.glColor3f(0.3f, 0.3f, 0.3f);     //Triangulo gris
        gl.glBegin(GL.GL_TRIANGLES);
        gl.glVertex2f(0,100);
        gl.glVertex2f(15,130);
        gl.glVertex2f(30,100);
        gl.glEnd();
        gl.glPopMatrix();
        
    }
    
    public void keyTyped(KeyEvent ke) {
        
        switch(ke.getKeyChar()){
            case 'I': case 'i':
                if(angulo>0)        angulo=1;
                else                angulo ++;
                break;
                
            case 'D': case 'd':
                if(angulo<-85)      angulo=-86;
                else                angulo --;
                break;
                
            case 's': case 'S':
                translate=true;
                break;
                
            case 'p': case 'P':
                translate=false;
                break;
                
            case 'r': case 'R':
                move=0;
                translate=false;
                angulo=0;
                break;
            case 'q': case 'Q':
                System.exit(0);
                break;
                
            default: break;
        }
    }
    
    public void mouseClicked(MouseEvent click) {
        blancoX = click.getX();
        blancoY = click.getY();
    }
    
    public void drawCircle(float px, float py, float radio){
        float x, y, angle=0;
        gl.glBegin(GL.GL_POLYGON);
        gl.glColor3d(1.0,0.0,0.0);
        for(int i=0;i<=360;i++)
        {
            x=(float) (radio*Math.cos(angle)+px);
            y=(float) (radio*Math.sin(angle)+py);
            angle++;
            gl.glVertex2d(x,y);
        }
        gl.glEnd();
    }
    
    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        gl.glClearColor(0.6f,0.8f,1.0f,0.0f);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    }
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) { }
    public void keyPressed(KeyEvent ke) {}
    public void keyReleased(KeyEvent ke) {}
    public void mousePressed(MouseEvent me) {}
    public void mouseReleased(MouseEvent me) {}
    public void mouseEntered(MouseEvent me) {}
    public void mouseExited(MouseEvent me) {}
    
}