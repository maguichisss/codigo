package graficacion;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

public class JuliaMain implements GLEventListener{
    
    private static Complejo c = new Complejo(-0.223, 0.745);
    private int [][] valores = null;
    private double minX = -1.5;
    private double maxX = 1.5;
    private double minY = -1.5;
    private double maxY = 1.5;
    private static final int WIDTH = 640;
    private static final int HEIGHT = 480;
    
    static GL gl;
    
    public static void main(String[] args){
        Frame frame = new Frame("Julia.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new JuliaMain());
        frame.add(canvas);
        frame.setSize(WIDTH, HEIGHT);
        frame.addWindowListener(new WindowAdapter() {
            
            @Override
            public void windowClosing(WindowEvent e) 
            {
                new Thread(new Runnable() {
                    public void run() {
                        System.exit(0);
                    }
                }).start();
            }
        });

        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    } //Fin del main

    public void init(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClearColor(0.5f,0.5f,0.5f,0);
    }
    
    public void display(GLAutoDrawable drawable) {
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        dibuja();
        gl.glFlush();

    }
 
    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        GLU glu = new GLU(); 
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluOrtho2D(0.0,WIDTH,0.0,HEIGHT);
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {}

    public void dibuja(){
        int color;
        
        Valores();
        
        gl.glBegin(GL.GL_POINTS);
        
        for(int i=0;i<WIDTH;i++){
            for(int j=0;j<HEIGHT;j++){
                
                color=valores[i][j]%5;
                
                switch(color){
                    case 0:gl.glColor3f(0.1f, 0.1f, 0.1f);
                    break;
                    case 1:gl.glColor3f(0.9f, 0.0f, 0.0f);
                    break;
                    case 2:gl.glColor3f(0.0f, 0.9f, 0.0f);
                    break;
                    case 3:gl.glColor3f(0.0f, 0.0f, 0.9f);
                    break;
                    case 4:gl.glColor3f(0.9f, 0.9f, 0.0f);
                    break;
                }
                
                gl.glVertex2d(i,j);
            }
        }
        
        gl.glEnd();
    }
    
    private void Valores(){
        valores = new int [WIDTH][HEIGHT];
        
        for(int i=0;i<WIDTH;i++){
            for(int j=0;j<HEIGHT;j++){
                
		double a = (double)i*(maxX-minX)/(double)WIDTH + minX;
		double b = (double)j*(maxY-minY)/(double)HEIGHT + minY;
               
                valores[i][j] = isInSet(new Complejo(a,b));
            }
        }
    }
    
    private int isInSet(Complejo cn){
        int color=0;
        for(int i=0;i<100;i++){
            cn = cn.square().add(c);
            if(cn.magnitude() > 2) break;
            color++;
        }

        return color;
    }
}