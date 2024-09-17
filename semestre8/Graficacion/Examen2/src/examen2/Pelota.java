package examen2;

import java.applet.*;
import java.awt.*;

/**
 *
 * @author
 * Garces Brito Mauricio I.
 * Tavares Vázquez Carolina
 *
 * @materia Graficación por Computadora
 *
 * @grupo 2803
 *
 * @fecha 25/05/2014.
 *
 */

public class Pelota extends Applet implements Runnable{
    int PosX=20,PosY=50;    //Posición de la pelota
    int DirX=PosX % 2 +1;  //Dirección de la pelota
    int DirY=PosY % 2 +1;  //Dirección de la pelota
    int radioPelota=10;     //Radio de la pelota
    Thread hilo;
    
    @Override
    public void start(){
        if(hilo== null)
        {
            hilo= new Thread(this);
            hilo.start();
        }
    }
    
    public void run(){
        while(true)
        {
            mover(); //Función que mueve la pelota
            repaint();
            
            try {
                Thread.sleep(2);
            } catch (InterruptedException ex) {
                //Logger.getLogger(Flecha.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    
    
    public void mover() {
        PosX+=DirX;
        PosY+=DirY;
        
        //Controlo que cuando toca el borde, cambie de direccion
        if ((PosX-radioPelota) <= 0)
            DirX*= -1;
        else if ((PosX+radioPelota) >= getWidth())
            DirX*= -1;
        
        if ((PosY-radioPelota) <= 0)
            DirY*= -1;
        else if ((PosY+radioPelota) >= getHeight())
            DirY*= -1;
    }
    
    @Override
    public void paint(Graphics g){
        g.setColor(Color.RED);
        g.fillOval(PosX-radioPelota, PosY-radioPelota, radioPelota*2, radioPelota*2);
    }
    
}