package graficacion;

import javax.media.opengl.GL;

/**
 *
 * @author mau
 */

public class Cubo{
     
    GL gl;
    float size;
    
    Cubo(GL gl, float size){
        this.gl = gl;
        this.size = size;
    }
  
    public void dibuja(){
        // Six faces of cube
        // Top face
        gl.glPushMatrix();
        gl.glRotatef(-90, 1, 0, 0);
        cuadrado(size, 0.2f, 0.2f, 0.8f);//azul
        gl.glPopMatrix();
        // Front face
        cuadrado(size, 0.8f, 0.2f, 0.2f);//rojo
        // Right face
        gl.glPushMatrix();
        gl.glRotatef(90, 0, 1, 0);
        cuadrado(size, 0.2f, 0.8f, 0.2f);//verde
        // Back face    
        gl.glRotatef(90, 0, 1, 0);
        cuadrado(size, 0.8f, 0.2f, 0.8f);
        // Left face    
        gl.glRotatef(90, 0, 1, 0);
        cuadrado(size, 0.2f, 0.8f, 0.8f);
        gl.glPopMatrix();
        // Bottom face
        gl.glPushMatrix();
        gl.glRotatef(90, 1, 0, 0);
        cuadrado(size, 0.8f, 0.8f, 0.2f);//amarillo
        gl.glPopMatrix();
        
    }

    public void cuadrado(float size, float r, float g, float b){
        float halfsize = size ;
        gl.glColor3f(r, g, b);
        gl.glBegin(GL.GL_QUADS);
        gl.glVertex3f(-halfsize, -halfsize, halfsize);
        gl.glVertex3f( halfsize, -halfsize, halfsize);
        gl.glVertex3f( halfsize,  halfsize, halfsize);
        gl.glVertex3f(-halfsize,  halfsize, halfsize);
        gl.glEnd();

    }
  
}
