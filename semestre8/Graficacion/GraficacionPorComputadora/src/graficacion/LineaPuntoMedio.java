package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */

public class LineaPuntoMedio {
    
    GL gl;
    Double x, y, p1x, p1y, p2x, p2y;
    
    LineaPuntoMedio(GL gl, Punto p1, Punto p2){
        this.gl = gl;
        p1x = p1.getX();
        p1y = p1.getY();
        p2x = p2.getX();
        p2y = p2.getY();
        x = ((p1x + p2x) / 2.0D);
        y = ((p1y + p2y) / 2.0D);
        
    }
    
    public void dibuja(){
        x = ((p1x + p2x) / 2.0D);
        y = ((p1y + p2y) / 2.0D);
        
        gl.glVertex2d(x, y);
    
    }
    
}
