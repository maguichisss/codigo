package graficacion;

import com.sun.opengl.util.Animator;
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

public class NuevaVentana implements GLEventListener, MouseListener {

    static int control;
    final static int width=640, height=640;         //tamaño de la ventana
    double right=100, up=100, left=-100, down=-100; //tamaño del plano
    static double xi,xf,yi,yf;
    static GL gl;
    static GLU glu;
    Punto pi, pf;
    int contar, pasos;
    
    public void setup(String n, int c) {
        control = c;
        final Frame frame = new Frame(n);
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new NuevaVentana());
        canvas.addMouseListener(new NuevaVentana());
        frame.add(canvas);
        //al tamaño de la pantalla le agregamos un poco mas por el contorno
        //y la barra de titulo
        frame.setSize(width+3, height+30);  
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {
                    public void run() {
                        animator.stop();
                        frame.dispose();
                    }
                }).start();
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        animator.start();
    
    }

    public void init(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        glu = new GLU();
        //gld = drawable;
        gl.glClearColor(1.0f, 1.0f, 1.0f, 0.0f); //color de fondo?
        gl.glMatrixMode(GL.GL_PROJECTION);
        glu.gluOrtho2D(left, right, down, up);   // tamaño del plano
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
        xi = yi = up /2;
        xf = yf = up /2;
        contar = (contar = 0);
    }

    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT); //limpia la pantalla
        gl.glLoadIdentity();
        dibujaEjes(gl, (float) left, (float)right, (float)down, (float) up);
        dibuja();
        gl.glEnd();
        gl.glFlush();
        
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }

    public void dibujaEjes(GL gl, float xi, float xf, float yi, float yf) {
        gl.glLineWidth(1.0F);
        gl.glColor3f(0.0F, 0.0F, 0.0F);
        gl.glBegin(1);
        gl.glVertex2f(xi, 0.0F);
        gl.glVertex2f(xf, 0.0F);
        gl.glVertex2f(0.0F, yi);
        gl.glVertex2f(0.0F, yf);
        gl.glEnd();
    }

    public void dibuja() {
        switch (control) {
            case 0:
                gl.glPointSize(3.0f);               //tamaño del punto
                gl.glColor3f(1.0f, 0.0f, 0.0f);     //color rojo
                gl.glBegin(GL.GL_POINTS);
        
                pi = new Punto(xi, yi);             //iniciamos puntos
                pf = new Punto(xf, yf);
                DDA linea = new DDA(pi,pf,gl);      //iniciamos linea

                pi.dibuja(gl);                      //dibujamos puntos
                pf.dibuja(gl);
                linea.dibuja();                     //dibuja linea DDA
                
                break;
                
            case 1:
                gl.glPointSize(3.0f);               //tamaño del punto
                gl.glColor3f(0.0f, 0.0f, 1.0f);     //color azul
                gl.glBegin(GL.GL_POINTS);
        
                pi = new Punto(xi, yi);       //iniciamos puntos y lineas
                pf = new Punto(xf, yf);
                Bresenham lineaB = new Bresenham(pi,pf,gl);      

                pi.dibuja(gl);                      //dibujamos puntos
                pf.dibuja(gl);
                lineaB.dibuja();                     //dibuja linea Bresenham
                break;
                
            case 2:
                gl.glPointSize(3.0f);               //tamaño del punto
                gl.glColor3f(0.0f, 1.0f, 0.0f);     //color verde
                gl.glBegin(GL.GL_POINTS);
        
                pi = new Punto(xi, yi);       //iniciamos puntos y lineas
                pf = new Punto(xf, yf);
                PuntoMedio puntoM = new PuntoMedio(pi,pf,gl);      

                pi.dibuja(gl);                      //dibujamos puntos
                pf.dibuja(gl);
                puntoM.dibuja();                     //dibuja circulo
                
                break;
                
            case 3:
                gl.glPointSize(3.0f);               //tamaño del punto
                gl.glColor3f(0.0f, 0.0f, 1.0f);     //color azul
                gl.glBegin(GL.GL_POINTS);
        
                pi = new Punto(xi, yi);       //iniciamos puntos y lineas
                pf = new Punto(xf, yf);
                Alpha puntoA = new Alpha(pi,pf,gl);      

                pi.dibuja(gl);                      //dibujamos puntos
                pf.dibuja(gl);
                puntoA.dibuja();                     //dibuja linea Alpha
                
                break;
                
            case 4:
                gl.glPointSize(10.0f);               //tamaño del punto
                gl.glColor3f(0.0f, 0.0f, 1.0f);     //color azul
                gl.glBegin(GL.GL_POINTS);
        
                pi = new Punto(xi, yi);       //iniciamos puntos y lineas
                pf = new Punto(xf, yf);
                LineaPuntoMedio lpm = new LineaPuntoMedio(gl,pi,pf);      
                Bresenham lineaBPM = new Bresenham(pi,pf,gl);      

                pi.dibuja(gl);                      //dibujamos puntos
                pf.dibuja(gl);
                lineaBPM.dibuja();                     //dibuja linea Bresenham
                
                gl.glColor3f(1f, 0.0f, 0.0f);     //color rojo
                lpm.dibuja(); 
                
                break;
                
        }
        gl.glEnd();
    }

    public void mouseClicked(MouseEvent click) {
        //hacemos el punto final sea ahora el inicial
        xi = xf;        
        yi = yf;
        System.out.println("Click inicial(" + xi + "," + yi + ")");
        //obtenemos los valores del nuevo punto final
        xf =  ( click.getX() / (width/up)        *2) -right;
        yf = -( click.getY() / (height/right)    *2) +up;
        System.out.println("Click final(" + xf + "," + yf + ")");
    
    }

    public void mousePressed(MouseEvent click) {
        
    }

    public void mouseReleased(MouseEvent click) {
        
    }

    public void mouseEntered(MouseEvent click) {
        
    }

    public void mouseExited(MouseEvent click) {
        
    }
}
