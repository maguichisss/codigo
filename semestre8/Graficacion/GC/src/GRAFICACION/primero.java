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
* @fecha 31/01/2014  
*   
*/ 
public class primero implements GLEventListener{

    public static void main(String[] args) {         
    Frame frame = new Frame("primero.java");         
    GLCanvas canvas = new GLCanvas();         
    canvas.addGLEventListener(new primero());         
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
     final GL gl = drawable.getGL();          
     final GLU glu = new GLU();          
     gl.glMatrixMode (GL.GL_PROJECTION);         
     gl.glClearColor (1.0f, 1.0f, 1.0f, 0.0f);          
     glu.gluOrtho2D (-100.0, 200.0, -100.0, 150.0); 
     }  
     public void display(GLAutoDrawable drawable) {  
     GL gl = drawable.getGL();          
     GLUT glut = new GLUT();          
     gl.glClear (GL.GL_COLOR_BUFFER_BIT);          
     gl.glColor3f (0.0f, 0.0f, 0.0f); //          
     gl.glMatrixMode (GL.GL_MODELVIEW);         
     gl.glLoadIdentity();          
     gl.glRasterPos2i(10, 15);         
     glut.glutBitmapString(GLUT.BITMAP_HELVETICA_18 , "Hola Mundo"); 
     }  
     public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {      }  
     public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {      } 
}
