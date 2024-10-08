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
* @fecha 21/02/2014  
*   
*/ 
public class Mandelbrot1 implements GLEventListener{

    public static void main(String[] args) {         
    Frame frame = new Frame("Mandelbrot1.java");         
    GLCanvas canvas = new GLCanvas();         
    canvas.addGLEventListener(new Mandelbrot1());         
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

     public void init(GLAutoDrawable drawable) {      }  
     public void display(GLAutoDrawable drawable) {      }  
     public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {      }  
     public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {      } 
}
