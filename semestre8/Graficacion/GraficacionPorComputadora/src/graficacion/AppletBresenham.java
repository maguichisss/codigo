
package graficacion;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class AppletBresenham extends Applet implements MouseListener,
ActionListener{


    int xini=0;
    int yini=0;
    int xfin=0;
    int yfin=0;
    int x0,y0,x1,y1;
    int pasos=0;
    boolean puntos, procesos, fin;
    Button proceso;
    int x, y, p, incE, incNE, stepx, stepy,dx,dy;



    void cuadro(Graphics g, Color c){
        int i;
        g.setColor(c);
        for(i=0;i<=250;i+=10){
        g.drawLine(i, 0, i, 250);
        g.drawLine(0, i, 250, i);
    }
}

    public void Bresenham(Graphics g,int x0, int y0, int x1, int y1){


      /* determinar que punto usar para empezar, cual para terminar */
        if(pasos==0){
            if (dy < 0) {
              dy = -dy; stepy = -1;
            }
            else {
                stepy = 1;
            }
            if (dx < 0) {
              dx = -dx; stepx = -1;
            }
            else {
                stepx = 1;
            }
            x = x0;
            y = y0;
            dibujaPunto(g, x, y, Color.red);
          /* se cicla hasta llegar al extremo de la lnea */
            if(dx>dy){
              p = 2*dy - dx;
              incE = 2*dy;
              incNE = 2*(dy-dx);
            }
            else{
              p = 2*dx - dy;
              incE = 2*dx;
              incNE = 2*(dx-dy);
            }
        }
        if(dx>dy && x!=x1){
                x = x + stepx;
                if (p < 0){
                  p = p + incE;
                }
                else {
                  y = y + stepy;
                  p = p + incNE;
                }
                dibujaPunto(g, x, y, Color.red);
             // }
        }else if(y != y1){
                y = y + stepy;
                if (p < 0){
                  p = p + incE;
                }
                else {
                  x = x + stepx;
                  p = p + incNE;
                }
                dibujaPunto(g, x, y, Color.red);
             // }
        }
        else fin = true;
    }

    @Override
    public void init() {
        procesos = puntos = false;

        setSize(270, 320);

        addMouseListener(this);
        this.setLayout(null);

        proceso = new Button("Dibujar");
        proceso.setSize(90, 20);
        proceso.setLocation(30, 270);
        proceso.addActionListener(this);
        add(proceso);

    }

    void dibujaPunto(Graphics g,int x, int y, Color c){
        g.setColor(c);
        g.fillRect(x*10, y*10, 10, 10);
    }

    @Override
    public void mousePressed(MouseEvent me) {

    }

    @Override
    public void mouseReleased(MouseEvent me) {

    }

    @Override
    public void paint(Graphics g){
        cuadro(g,Color.black);
    }

    @Override
    public void update(Graphics g){
        if (puntos){
            dibujaPunto(g, xini, yini, Color.blue);
            if(xfin!=0){
                dibujaPunto(g, xfin, yfin, Color.blue);
                g.drawLine(xini*10+5, yini*10+5, xfin*10+5, yfin*10+5);
            }
            puntos = false;
        }
        if (procesos && !fin){

            if(pasos==0){
                x0=xini;
                y0=yini;
                x1=xfin;
                y1=yfin;
                dx = (x1 - x0);
                dy = (y1 - y0);
            }
            Bresenham(g,x0,y0,x1,y1);
            pasos++;
            System.out.println(pasos);

        }
        paint(g);
    }
    @Override
    public void actionPerformed(ActionEvent ae) {
        if(ae.getSource()==proceso && xfin!=0){
            procesos = true;
            repaint();
        }
    }

    public void mouseClicked(MouseEvent me) {


        if (me.getX()<250 && me.getY()<250){

            if(xini==0){
                xini = me.getX()/10;
                yini = me.getY()/10;
                puntos = true;
                repaint();
            }else if(xfin==0 ){
                xfin = me.getX()/10;
                yfin = me.getY()/10;
                puntos = true;
                repaint();
            }
        }
    }

    public void mouseEntered(MouseEvent me) {}

    public void mouseExited(MouseEvent me) {}

}
