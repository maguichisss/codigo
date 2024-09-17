package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */
public class Piramide {
    
    GL gl;
    float size;
    
    Piramide(GL gl, float size){
        this.gl = gl;
        this.size = size;
    }
    
    public void dibuja(){
        gl.glPushMatrix();
         //-----base de la piramide--varios colores
        //se usa GL.GL_QUADS para crear un cuadrilátero
        gl.glBegin(GL.GL_QUADS);
        //vértices en 3d
        gl.glColor3f(1,0,0);//rojo
        gl.glVertex3d(-size,0,-size);//1
        gl.glColor3f(1,1,0);//amarillo
        gl.glVertex3d(-size,0,size);//3
        gl.glColor3f(0,0,1);//azul
        gl.glVertex3d(size,0,size);//2
        gl.glColor3f(0,1,0);//verde
        gl.glVertex3d(size,0,-size);//1
        gl.glEnd();
        //------------------caras de la pirámide
        //para las caras triangulares
        //se usará GL.GL_TRIANGLES
        //--------Cara 1  amarillo con blanco
        gl.glBegin(GL.GL_TRIANGLES);
        //vértices en 3d
        gl.glColor3f(1,1,1);//blanco
        gl.glVertex3d(0,size,0);
        gl.glColor3f(1,1,0);
        gl.glVertex3d(-size,0,-size);//1
        gl.glVertex3d(size,0,-size);//1
        gl.glEnd();

        //--------Cara 1 rojo con blanco
        gl.glBegin(GL.GL_TRIANGLES);
        //vértices en 3d
        gl.glColor3f(1,1,1);//blanco
        gl.glVertex3d(0,size,0);
        gl.glColor3f(1,0,0);//rojo
        gl.glVertex3d(size,0,-size);
        gl.glVertex3d(size,0,size);
        gl.glEnd();
        //--------Cara 3 verde con blanco
        gl.glBegin(GL.GL_TRIANGLES);
        //vértices en 3d
        gl.glColor3f(1,1,1);//blanco
        gl.glVertex3d(0,size,0);
        gl.glColor3f(0,1,0);//verde
        gl.glVertex3d(-size,0,size);
        gl.glVertex3d(-size,0,-size);
        gl.glEnd();
        //-------Cara 2 azul con blanco
        gl.glBegin(GL.GL_TRIANGLES);
        //vértices en 3d
        gl.glColor3f(1,1,1);//blanco
        gl.glVertex3d(0,size,0);
        gl.glColor3f(0,0,1);//azul
        gl.glVertex3d(size,0,size);
        gl.glVertex3d(-size,0,size);
        gl.glEnd();
        gl.glPopMatrix();
        
    }
    
}
