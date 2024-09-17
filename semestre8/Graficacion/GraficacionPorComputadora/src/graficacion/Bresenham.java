package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */
public class Bresenham {
    
    int xi, xf, yi, yf;
    GL gl;
    
    Bresenham(Punto inicio, Punto fin, GL gl){
        this.gl = gl;
        this.xi = (int) inicio.getX();
        this.xf = (int) fin.getX();
        this.yi = (int) inicio.getY();
        this.yf = (int) fin.getY();
    }
    
    public void dibuja(){ 
        int x, y, dx, dy, p, incE, incNE, stepx, stepy;
        dx = (xf - xi);
        dy = (yf - yi);

        /* determinar que punto usar para empezar, cual para terminar */
        if (dy < 0) { 
            dy = -dy; 
            stepy = -1; 
            
        }else
            stepy = 1;

        if (dx < 0) {  
            dx = -dx;  
            stepx = -1; 
            
        }else
            stepx = 1;

        x = (int) xi;
        y = (int) yi;
        gl.glVertex2d( xi, yi);

        /* se cicla hasta llegar al extremo de la línea */
        System.out.println("dx:"+dx+"\ndy: "+dy);
        if(dx>dy){
            p = 2*dy - dx;
            incE = 2*dy;
            incNE = 2*(dy-dx);
            System.out.println("p = 2*dy - dx\n"+p+" = 2*"+dy+"-"+dx);
            System.out.println("incE = 2*dy\n"+incE+" = 2*"+dy);
            System.out.println("incNE = 2*(dy-dx)\n"+incNE+" = 2*("+dy+"-"+dx+")");
            while (x != xf){
                x = x + stepx;
                if (p < 0)
                    p = p + incE;
                else{
                    y = y + stepy;
                    p = p + incNE;
                }
                gl.glVertex2d( x, y);
            }
        }else{ 
            p = 2*dx - dy;
            incE = 2*dx;
            incNE = 2*(dx-dy);
            while (y != yf){
                y = y + stepy;
                if (p < 0)
                    p = p + incE;
                else{
                    x = x + stepx;
                    p = p + incNE;
                }
                gl.glVertex2d( x, y);
            }
        }
    }
    
}
