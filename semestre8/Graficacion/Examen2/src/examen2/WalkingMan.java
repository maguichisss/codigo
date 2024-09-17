package examen2;

import com.sun.opengl.util.Animator;
import java.awt.Frame;
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

public class WalkingMan implements GLEventListener {
    
    static GL gl;
    static GLU glu;
    
    double edificio=0;
    Man hombre[] = new Man[7];
    
    public static void main(String[] args)  {
        Frame frame = new Frame("WalkingMan.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new WalkingMan());
        frame.add(canvas);
        frame.setSize(640, 480);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {
            
            @Override
            public void windowClosing(WindowEvent e)
            {
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
        
        gl.glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
        gl.glMatrixMode (GL.GL_PROJECTION);
        glu.gluOrtho2D (-320, 320, -240, 240);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        
        int step=-300;
        for(int i=0; i<7; i++){
            hombre[i] = new Man(gl, step, 0);
            step+=100;
        }
    }
    
    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
//------------------------------------------------------------        
        fondo();
        for(int i=0; i<7; i++)
            hombre[i].camina();
//------------------------------------------------------------        
        gl.glFlush();
    }
    
    void fondo() {
        int i,l,n=0,z,vent1x=0,vent1y=0;
        if(edificio>-1000) edificio=edificio-2;
        else edificio = 0;
        gl.glLineWidth(5);
        gl.glBegin(GL.GL_QUADS);
        
        for(i=0;i<2;i++){
            //edificio1
            gl.glColor3d(0.4,0.4,0.4);
            gl.glVertex2d(500+edificio+n,-140);
            gl.glVertex2d(275+edificio+n,-140);
            gl.glVertex2d(275+edificio+n,300);
            gl.glVertex2d(500+edificio+n,300);
            //puerta
            gl.glColor3d(0.2,0.2,0.2);
            gl.glVertex2d(420+edificio+n,-140);
            gl.glVertex2d(355+edificio+n,-140);
            gl.glVertex2d(355+edificio+n,-30);
            gl.glVertex2d(420+edificio+n,-30);
            //ventanas
            gl.glColor3d(0.0,0.5,1.0);
            for(z=0;z<4;z++)
            {
                for(l=0;l<5;l++)
                {
                    gl.glVertex2d(485+edificio+n+vent1x,0+vent1y);
                    gl.glVertex2d(455+edificio+n+vent1x,0+vent1y);
                    gl.glVertex2d(455+edificio+n+vent1x,30+vent1y);
                    gl.glVertex2d(485+edificio+n+vent1x,30+vent1y);
                    vent1y=vent1y+55;
                }
                vent1y=0;
                vent1x=vent1x-55;
            }
            vent1x=0;
            //edificio2
            gl.glColor3d(0.45,0.45,0.45);
            gl.glVertex2d(275+edificio+n,-140);
            gl.glVertex2d(0+edificio+n,-140);
            gl.glVertex2d(0+edificio+n,200);
            gl.glVertex2d(275+edificio+n,200);
            //puerta
            gl.glColor3d(0.3,0.3,0.3);
            gl.glVertex2d(50+edificio+n,-140);
            gl.glVertex2d(225+edificio+n,-140);
            gl.glVertex2d(225+edificio+n,-40);
            gl.glVertex2d(50+edificio+n,-40);
            gl.glColor3d(0.08,0.15,0.8);
            gl.glVertex2d(55+edificio+n,-140);
            gl.glVertex2d(220+edificio+n,-140);
            gl.glVertex2d(220+edificio+n,-45);
            gl.glVertex2d(55+edificio+n,-45);
            gl.glEnd();
            gl.glColor3d(0.3,0.3,0.3);
            gl.glBegin(GL.GL_LINES);
            gl.glVertex2d(137.5+edificio+n,-140);
            gl.glVertex2d(137.5+edificio+n,-40);
            gl.glEnd();
            gl.glBegin(GL.GL_QUADS);
            //ventanas
            gl.glColor3d(0.0,0.38,0.75);
            for(z=0;z<3;z++)
            {
                for(l=0;l<2;l++)
                {
                    gl.glVertex2d(245+edificio+n+vent1x,10+vent1y);
                    gl.glVertex2d(190+edificio+n+vent1x,10+vent1y);
                    gl.glVertex2d(190+edificio+n+vent1x,50+vent1y);
                    gl.glVertex2d(245+edificio+n+vent1x,50+vent1y);
                    vent1y=vent1y+80;
                }
                vent1y=0;
                vent1x=vent1x-80;
            }
            vent1x=0;
            //edificio3
            gl.glColor3d(0.3,0.3,0.3);
            gl.glVertex2d(0+edificio+n,-140);
            gl.glVertex2d(-250+edificio+n,-140);
            gl.glVertex2d(-250+edificio+n,340);
            gl.glVertex2d(0+edificio+n,340);
            //puerta
            gl.glColor3d(0.25,0.20,0.02);
            gl.glVertex2d(-70+edificio+n,-140);
            gl.glVertex2d(-180+edificio+n,-140);
            gl.glVertex2d(-180+edificio+n,-45);
            gl.glVertex2d(-70+edificio+n,-45);
            //ventanas
            gl.glColor3d(0.0,0.4,1.0);
            for(z=0;z<5;z++)
            {
                for(l=0;l<7;l++)
                {
                    gl.glVertex2d(-10+edificio+n+vent1x,-20+vent1y);
                    gl.glVertex2d(-40+edificio+n+vent1x,-20+vent1y);
                    gl.glVertex2d(-40+edificio+n+vent1x,10+vent1y);
                    gl.glVertex2d(-10+edificio+n+vent1x,10+vent1y);
                    vent1y=vent1y+50;
                }
                vent1y=0;
                vent1x=vent1x-50;
            }
            vent1x=0;
            //edificio4
            gl.glColor3d(0.35,0.35,0.35);
            gl.glVertex2d(-250+edificio+n,-140);
            gl.glVertex2d(-500+edificio+n,-140);
            gl.glVertex2d(-500+edificio+n,225);
            gl.glVertex2d(-250+edificio+n,225);
            //puerta
            gl.glColor3d(0.6,0.6,0.6);
            gl.glVertex2d(-450+edificio+n,-140);
            gl.glVertex2d(-300+edificio+n,-140);
            gl.glVertex2d(-300+edificio+n,0);
            gl.glVertex2d(-450+edificio+n,0);
            //ventanas
            gl.glColor3d(0.0,0.4,1.0);
            for(z=0;z<3;z++)
            {
                for(l=0;l<3;l++)
                {
                    gl.glVertex2d(-275+edificio+n+vent1x,15+vent1y);
                    gl.glVertex2d(-325+edificio+n+vent1x,15+vent1y);
                    gl.glVertex2d(-325+edificio+n+vent1x,55+vent1y);
                    gl.glVertex2d(-275+edificio+n+vent1x,55+vent1y);
                    vent1y=vent1y+75;
                }
                vent1y=0;
                vent1x=vent1x-75;
            }
            vent1x=0;
            
            n=1000;
        }//cierre de for
        
        gl.glEnd();
    }
    
    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {}
    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged){}

}