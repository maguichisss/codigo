package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */
public class Julia {
    
    private static Complejo c = new Complejo(-0.223, 0.745);
    private int [][] valores = null;
    private double minX = -1.5;
    private double maxX = 1.5;
    private double minY = -1.5;
    private double maxY = 1.5;
    private static final int WIDTH = 480;
    private static final int HEIGHT = 480;
    
    GL gl;
    
    Julia(GL gl){
        this.gl = gl;
    }
    
    public void dibuja(){
        int color;
        Valores();
        
        gl.glBegin(0);
        
        for(int i=0;i<WIDTH;i++){
            for(int j=0;j<HEIGHT;j++){
                
                color=valores[i][j]%5;
                
                switch(color){
                    case 0:
                        gl.glColor3f(0.1f, 0.1f, 0.1f);
                    break;
                    case 1:
                        gl.glColor3f(0.9f, 0.0f, 0.0f);
                    break;
                    case 2:
                        gl.glColor3f(0.0f, 0.9f, 0.0f);
                    break;
                    case 3:
                        gl.glColor3f(0.0f, 0.0f, 0.9f);
                    break;
                    case 4:
                        gl.glColor3f(0.9f, 0.9f, 0.0f);
                    break;
                }
                
                gl.glVertex2d(i,j);
                //System.out.println(i+"---"+j);
            }
        }
        
        //gl.glEnd();
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
