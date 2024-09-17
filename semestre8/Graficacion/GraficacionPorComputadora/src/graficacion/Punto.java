package graficacion;

import javax.media.opengl.GL;

class Punto {

    double x;
    double y;

    Punto(double xr, double yr) {
        this.x = xr;
        this.y = yr;
    }
    
    Punto() {
        this.x = (this.y = 0.0D);
    }

    void medio(Punto p) {
        this.x = ((this.x + p.x) / 2.0D);
        this.y = ((this.y + p.y) / 2.0D);
        
    }

    void dibuja(GL g) {
        g.glVertex2d(this.x, this.y);
    }
      
    public void setX(double x){
        this.x = x;
    }
    public void setY(double y){
        this.y = y;
    }
    public double getX(){
        return x;
    }
    public double getY(){
        return y;
    }

    
    
}
