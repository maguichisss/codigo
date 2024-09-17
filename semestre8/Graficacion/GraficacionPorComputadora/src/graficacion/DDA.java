package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author maguichisss
 */

public class DDA {
    
    Double xi, xf, yi, yf;
    GL gl;
    
    DDA(Punto inicio, Punto fin, GL gl){    
        this.gl = gl;
        this.xi = inicio.getX();
        this.xf = fin.getX();
        this.yi = inicio.getY();
        this.yf = fin.getY();
    }
    
    public void dibuja(){
        Double dx = xf-xi;
        Double dy = yf-yi;
        
        Double pasos, xinc, yinc, x, y;
        
        if(Math.abs(dx) > Math.abs(dy) )
            pasos = Math.abs(dx);
        else
            pasos = Math.abs(dy);
        
        xinc = dx / pasos;
        yinc = dy / pasos;
        
        x = xi;
        y = yi;
        
        gl.glVertex2d(Math.round(x), Math.round(y));
        for(int i=1; i<=pasos; i++){
            x += xinc;
            y += yinc;
            gl.glVertex2d(Math.round(x), Math.round(y));
        
        }
        
    
    }
}
