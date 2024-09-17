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
public class Alpha {
    
    int xi, xf, yi, yf, pasos, radio;
    GL gl;
    
    Alpha(Punto inicio, Punto fin, GL gl){    
        this.gl = gl;
        this.xi = (int) inicio.getX();
        this.xf = (int) fin.getX();
        this.yi = (int) inicio.getY();
        this.yf = (int) fin.getY();
        int catX = Math.abs(xi-xf);
        int catY = Math.abs(yi-yf);
        radio = (int) Math.sqrt((catX*catX)+(catY*catY));
        
    }
    
    public void dibuja(){
        
        int dx = xf - xi;
        int dy = yf - yi;
        
        float x = xi;
        float y = yi;
        
        if (Math.abs(dy) > Math.abs(dx)) {
            pasos = Math.abs(dy);
        } else {
            pasos = Math.abs(dx);
        }
        float incremento = 1.0F / pasos;
        float alpha = incremento;
        for (int i = 0; i <= radio; i++) {
            gl.glVertex2d(x,y);
            x = xi * (1.0F - alpha) + xf * alpha;
            y = yi * (1.0F - alpha) + yf * alpha;
            alpha += incremento;
        }
        
    }
    
}
