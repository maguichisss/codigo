/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package GRAFICACION;

import com.sun.opengl.util.Animator;
import com.sun.opengl.util.GLUT;  
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
* @author Giovanna Eloisa Vazquez Moreno   
*         Pablo Sergio Cabrera Uribe   
*   
* @materia: Graficación por Computadora   
*   
* @grupo: 2803   
*   
* @fecha 14/02/2014  
*   
*/ 
public class Sierpinsky implements GLEventListener{

    public static void main(String[] args) {         
    Frame frame = new Frame("Sierpinsky.java");         
    GLCanvas canvas = new GLCanvas();         
    canvas.addGLEventListener(new Sierpinsky());         
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
public void dibujaTriangulo(GL gl){
    double ax,ay,bx,by,cx,cy,px,py;
    double r;
    int i,rprima;
    i=0;
    ax=1.0;
    ay=1.0;
    bx=5.0;
    by=9.0;
    cx=9.0;
    cy=1.0;
    px=9.0;
    py=9.0;
    gl.glBegin(GL.GL_POINTS);
    gl.glVertex2d(ax,ay);
    gl.glVertex2d(bx,by);
    gl.glVertex2d(cx,cy);
    do
    {
        gl.glVertex2d(px,py);
        r=Math.random()*1000;
        rprima= (int)r%3;
    switch (rprima){
    case 0:
    px=(px+ax)/2;
    py=(py+ay)/2;
    break;
    case 1:
    px=(px+bx)/2;
    py=(py+by)/2;
    break;
    case 2:
    px=(px+cx)/2;
    py=(py+cy)/2;
    break;
}
i++;
}
while
(i<10000);
gl.glEnd();
}
     public void init(GLAutoDrawable drawable) {  
        GL gl = drawable.getGL ();
        GLU glu = new GLU();
        gl.glClearColor(1,1,1,0);
        gl.glMatrixMode(GL.GL_PROJECTION);
        glu.gluOrtho2D (0.0, 10.0, 0.0, 10.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity (); 
     }  
     public void display(GLAutoDrawable drawable) {   
        GL gl = drawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        gl.glLoadIdentity();
        gl.glPointSize(3.0f);
        gl.glColor3d(0/255.0,0/255.0,255/255.0);
        dibujaTriangulo(gl);
        gl.glFlush();
     }  
     public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {  
        GL gl = drawable.getGL ();
        gl.glViewport(0, 0,width,height);
     }  
     public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {      } 
}
