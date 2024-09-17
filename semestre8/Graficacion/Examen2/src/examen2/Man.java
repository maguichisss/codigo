package examen2;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */
public class Man {
    
    double pi=3.141592;
    double cabezax,cabezay,cuerpox=0,cuerpoy=0,ang=0,brazo3x,brazo4x,brazo3y,brazo4y;
    double vertice1x=0,vertice2x=0,vertice1y=0,vertice2y=0,brazo1x=0,brazo1y=0,brazo2x=0,brazo2y=0;
    double vertice3x=0,vertice4x=0,vertice3y=0,vertice4y=0;
    GL gl;
    
    public Man(GL gl, double translateX, double translateY){
        this.gl = gl;
        this.cabezax = translateX;
        this.cabezay = translateY;
        
    }
    
    
    void camina(){
        
        double delta;
        int i;
        //brazos
        delta=2*pi/90;
        brazo1x=25*Math.sin(ang);
        brazo2x=brazo1x+(25*Math.sin(ang))+(25-brazo1x);
        brazo2y=10*(1-Math.cos(ang*2));
        brazo3x=-(25*Math.sin(ang));
        brazo4x=brazo3x+(25*Math.sin(ang))+(25-brazo1x);
        brazo4y=10*(1-Math.cos(ang*2));
        ang=ang+delta;
        //piernas
        vertice1x=20*Math.sin(ang);
        vertice2x=vertice1x+(10*Math.sin(ang));
        vertice3x=-(20*Math.sin(ang));
        vertice4x=(vertice3x)-(10*Math.sin(ang));
        //fondo();
        persona();
    }
    
    void persona(){
        int i=0;
        double angulo=0.0f,radio=20;
        double delta,x1 = 0,y1 = 0,x2,y2,x3,y3;
        gl.glLineWidth(5);
        gl.glBegin(GL.GL_POLYGON);
        gl.glColor3d(0.0,0.0,0.0);
        delta=2*pi/360;
        for(i=0;i<=360;i++)
        {
            x1=radio*Math.cos(angulo)+cabezax;
            y1=radio*Math.sin(angulo)+cabezay;
            angulo=angulo+delta;
            gl.glVertex2d(x1,y1);
        }
        gl.glEnd();
        gl.glBegin(GL.GL_LINES);
        //gl.glColor3d(0.0,0.0,0.0);
        x2=x1-radio;
        y2=y1-radio;
        gl.glBegin(GL.GL_LINES);
        gl.glVertex2d(x2,y2);//Cuerpo
        gl.glVertex2d(x2,radio+y2-100-cabezay);//Cuerpo
        gl.glEnd();
        
        y3=y2-75;
        x3=x2;
        
        gl.glBegin(GL.GL_LINES);
        //pierna11
        gl.glVertex2d(x3,y3);
        gl.glVertex2d(x3-vertice1x,y3-40+vertice1y);//pierna11
        gl.glVertex2d(x3-vertice1x,y3-40+vertice1y);//pierna12
        gl.glVertex2d(x3-vertice2x,y3-85+vertice2y);//pierna12
        //pierna21
        gl.glVertex2d(x3,y3);
        gl.glVertex2d(x3-vertice3x,y3-40+vertice3y);//pierna21
        gl.glVertex2d(x3-vertice3x,y3-40+vertice3y);//pierna22
        gl.glVertex2d(x3-vertice4x,y3-85+vertice4y);//pierna22
        //brazo11
        gl.glVertex2d(x2,y2-10);
        gl.glVertex2d(x2+brazo1x,y2-36+brazo1y);//brazo12
        gl.glVertex2d(x2+brazo1x,y2-35+brazo1y);//brazo12
        gl.glVertex2d(x2+brazo2x,y2-70+brazo2y);//brazo13
        //brazo21
        gl.glVertex2d(x2,y2-10);
        gl.glVertex2d(x2+brazo3x,y2-36+brazo3y);//brazo22
        gl.glVertex2d(x2+brazo3x,y2-35+brazo3y);//brazo22
        gl.glVertex2d(x2+brazo4x,y2-70+brazo4y);//brazo23
        
        gl.glEnd();
    }
    
    
}
