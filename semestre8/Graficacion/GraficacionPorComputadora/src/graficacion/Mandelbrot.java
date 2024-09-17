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
public class Mandelbrot {
    
    GL gl;
    
    Mandelbrot(GL gl){
        this.gl = gl;
    }
    
    int mandel(Complejo c, Complejo z, int n) {
        int r;
        if ((z.abs() < 2.0D) && (n < 1000)) {
            z.mult(z);
            z.suma(c);
            r = mandel(c, z, n + 1);
        } else {
            r = n;
        }
        return r;
    }

    public void dibuja() {
        gl.glBegin(0);
        for (double x = -2.0D; x <= 1.2D; x += 0.0050D) {
            for (double y = -1.2D; y <= 1.2D; y += 0.0050D) {
                Complejo z = new Complejo(0.0D, 0.0D);
                Complejo c = new Complejo(x, y);
                int color = mandel(c, z, 0) % 5;
                switch (color) {
                    case 0:
                        gl.glColor3f(1.0F, 0.0F, 0.0F);
                        break;
                    case 1:
                        gl.glColor3f(0.0F, 1.0F, 0.0F);
                        break;
                    case 2:
                        gl.glColor3f(0.0F, 0.0F, 1.0F);
                        break;
                    case 3:
                        gl.glColor3f(1.0F, 1.0F, 0.0F);
                        break;
                    case 4:
                        gl.glColor3f(1.0F, 0.0F, 1.0F);
                }

                gl.glVertex2d(x, y);
                //System.out.println(x+"---"+y);
            }
        }
        
    }
    
}
