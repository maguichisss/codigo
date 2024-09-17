package graficacion;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;
import java.awt.BorderLayout;
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
* @author mau
*/

public class Teclado implements GLEventListener, KeyListener{

    GL gl;
    static GLAutoDrawable gld;
    private GLU glu = new GLU();
    static GLUT glut;
    static char tecla;
    static double xi,xf,yi,yf;
    Punto pi, pf;
    private float angulo;
    static float velocidad = 0.01f;
    static boolean solido, wire;
    static double [][]puntos;
    
    public static void main(String[] args) { 
        Frame frame = new Frame("Otro Menu Teclado"); 
        frame.setLayout(new BorderLayout());
        
        GLCanvas canvas = new GLCanvas();
        final Teclado teclado = new Teclado();
        
        canvas.addGLEventListener(teclado); 
        frame.add(canvas, BorderLayout.CENTER); 
        
        frame.setSize(480, 480); 
        final Animator animator = new Animator(canvas);
        canvas.addKeyListener(teclado);
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
        gld = drawable;
        glut = new GLUT(); 
        gl.glEnable(GL.GL_DEPTH_TEST);
        gl.glMatrixMode(GL.GL_PROJECTION);
        glu.gluOrtho2D (-10.0, 170.0, -10.0, 180.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
        solido = wire = false;
        tecla = 'm';
        gl.glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //color de fondo?
        
        int i;
        double inc;
        puntos = new double[20][2];
        puntos[0][0]=1;
        puntos[0][1]=0;
        for(i=1,inc=2*Math.PI/20;i<20;i++,inc += 2*Math.PI/20){
            puntos[i][0]=Math.cos(inc);
            puntos[i][1]=Math.sin(inc);
        }
        
    }

    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glColor3d(.8, 0.0, 0.0);
        dibuja();
        gl.glFlush();
    } 

    public void dibuja(){
        
        switch(tecla){
            case 'm':
                Mandelbrot mandel = new Mandelbrot(gl);
                mandel.dibuja();
                
                break;

            case 'c': 
                Cubo cube = new Cubo(gl, 0.5f);
                Piramide piramid = new Piramide(gl, 0.5f);
                
                gl.glTranslatef(0f, .3f, -0.0f);
                gl.glRotatef(angulo, 0, 1, 0);
                piramid.dibuja();
                
                //Base rotation of cube
                gl.glTranslatef(0f, -.5f, 0.0f);
                gl.glRotatef(0, 0, 1, 0);
                cube.dibuja();

                //fps.draw();

                angulo += 100 * velocidad;
                
                
                break;
                
            case 'd': 
                gl.glPushMatrix();
                gl.glRotatef(angulo, 1, 1, 0);
                gl.glColor3f(1, 0, 0);
                diamante();
                gl.glPopMatrix();
                
                gl.glPushMatrix();
                gl.glRotatef(angulo+60, 1, 1, 0);
                gl.glColor3f(0, 1, 0);
                diamante();
                gl.glPopMatrix();
                
                gl.glPushMatrix();
                gl.glRotatef(angulo+120, 1, 1, 0);
                gl.glColor3f(0, 0, 1);
                diamante();
                gl.glPopMatrix();
                
                angulo += 100 * velocidad;
                
                
                break;
                           
            case '1':
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(45, 1, 1, 1);
                if(solido)
                    glut.glutSolidSphere(.5, 50, 50); 
                else
                     glut.glutWireSphere(.5, 50, 50);
                
                break;  
                
            case '2':
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(45, 1, 1, 1);
                if (solido)
                    glut.glutSolidCube(.5f);
                
                else 
                    glut.glutWireCube(.5f);
                
                break;
                
            case'3': 
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(45, 1, 1, 1);
                if (solido)
                    glut.glutSolidTorus(.1, 0.3, 50, 20); 
                
                else 
                    glut.glutWireTorus(.1, 0.3, 50, 20); 
                
                break;
                
            case'4':    
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(25, 1, 1, 1);
                if (solido)
                    glut.glutSolidIcosahedron(); 
                
                else
                    glut.glutWireIcosahedron(); 
                
                break;
                
            case'5':     
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(35, 1, 1, 1);
                 if (solido)
                    glut.glutSolidOctahedron(); 
                
                else
                    glut.glutWireOctahedron(); 
                
                break;
                
            case'6':    
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(25, 1, 1, 1);
                if (solido)
                    glut.glutSolidTetrahedron(); 
                
                else
                    glut.glutWireTetrahedron();
                
                break;
                
            case'7': 
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(25, 1, 1, 1);
                if (solido)
                    glut.glutSolidCylinder(.4, 1.5, 50, 50);
                
                else
                    glut.glutWireCylinder(.4, 1.5, 50, 50);
                
                break;
                
            case'8': 
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(45, 1, 1, 1);
                if (solido)
                    glut.glutSolidCone(.5, .5, 50, 3); 
                
                else
                    glut.glutWireCone(.5, .5, 50, 3); 
                
                break;
                
            case'9':  
                gl.glTranslatef(0f, 0f, 0.0f);
                gl.glRotatef(25, 1, 1, 1);
                if (solido)
                    glut.glutSolidTeapot(.5); 
                
                else
                    glut.glutWireTeapot(.5);
                
                break;
            default:
                tecla = '1';
                
                break;
            

        }
        gl.glEnd();

    }
    
    public void diamante(){
        int i, j;
        gl.glBegin(GL.GL_LINES);
        for(i=0;i<19;i++){
            for(j=i+1;j<20;j++){
                gl.glVertex2dv(puntos[i],0);
                gl.glVertex2dv(puntos[j],0);
            }
        }
        gl.glEnd();
        
    }

    public void keyPressed(KeyEvent event) {
        tecla = event.getKeyChar();
        switch(tecla){
            case 's': 
                solido = true;
                break;
            case 'w': 
                solido = false;
                break;
        }
        gld.display();
        System.out.println("Letra: "+tecla);
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        gl = drawable.getGL();
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluPerspective(15, (float) width / (float) height, 5, 15);
        
    } 

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {}

    public void keyTyped(KeyEvent ke) {}

    public void keyReleased(KeyEvent ke) {}
}
