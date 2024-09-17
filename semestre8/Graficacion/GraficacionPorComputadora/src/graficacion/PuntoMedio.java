/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */
public class PuntoMedio {
    
    int xc, yc, xf, yf, radio;
    int catX, catY;
    GL gl;
    
    PuntoMedio(Punto inicio, Punto fin, GL gl){
        xc = (int) inicio.getX();
        yc = (int) inicio.getY();
        xf = (int) fin.getX();
        yf = (int) fin.getY();
        catX = Math.abs(xc-xf);
        catY = Math.abs(yc-yf);
        radio = (int) Math.sqrt((catX*catX)+(catY*catY));
        this.gl = gl;
        System.out.println("radio: "+radio);
        
    }
    
    public void dibuja(){
        int x=0,y, p;
        /*
        System.out.println("P1: "+xc+","+(yc+radio));
        System.out.println("P2: "+xc+","+(yc-radio));
        System.out.println("P3: "+(xc+radio)+","+yc);
        System.out.println("P4: "+(xc-radio)+","+yc);
        */
        y = radio;
        p = 1-radio;
        while (x <= y){
            x = x + 1;
            if (p < 0)
                p = p + 2*x + 1;
            else {
                y = y - 1;
                p = p + 2*(x - y) + 1;
            }
            gl.glVertex2d(x+xc,y+yc);
            gl.glVertex2d(-x+xc,y+yc);
            gl.glVertex2d(x+xc,-y+yc);
            gl.glVertex2d(-x+xc,-y+yc);
            
            gl.glVertex2d(y+xc,x+yc);
            gl.glVertex2d(-y+xc,x+yc);
            gl.glVertex2d(y+xc,-x+yc);
            gl.glVertex2d(-y+xc,-x+yc);

        }
    }
    
    
}
