package graficacion;

import java.applet.Applet;
import java.awt.Button;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class DDA extends Applet implements MouseListener, ActionListener {

    int xini;
    int yini;
    int xfin;
    int yfin;
    int pasos;
    int contar;
    boolean puntos;
    boolean procesos;
    Button proceso;

    void correCirculo(Graphics g) {
        int x = 0;
        int r = Math.abs(this.xini - this.xfin);
        int y = r;
        int p = 1 - r;
        while (x <= y) {
            dibujaPunto(g, x + this.xini, y + this.yini, Color.cyan);
            dibujaPunto(g, y + this.xini, -x + this.yini, Color.blue);
            dibujaPunto(g, x + this.xini, -y + this.yini, Color.red);
            dibujaPunto(g, -x + this.xini, -y + this.yini, Color.yellow);
            dibujaPunto(g, -y + this.xini, -x + this.yini, Color.lightGray);
            dibujaPunto(g, -y + this.xini, x + this.yini, Color.orange);
            dibujaPunto(g, -x + this.xini, y + this.yini, Color.magenta);
            dibujaPunto(g, y + this.xini, x + this.yini, Color.pink);
            if (p < 0) {
                p = p + 2 * x + 1;
                x++;
            } else {
                p = p + 2 * x + 1 - 2 * (2 * y - 2);
                x++;
                y--;
            }
        }
    }

    void cuadro(Graphics g, Color c) {
        g.setColor(c);
        for (int i = 0; i <= 250; i += 10) {
            g.drawLine(i, 0, i, 250);
            g.drawLine(0, i, 250, i);
        }
    }

    void correDDA(Graphics g) {
        int dx = this.xfin - this.xini;
        int dy = this.yfin - this.yini;

        float x = this.xini;
        float y = this.yini;
        this.contar += 1;
        if (Math.abs(dy) > Math.abs(dx)) {
            this.pasos = Math.abs(dy);
        } else {
            this.pasos = Math.abs(dx);
        }
        float xincremento = dx / this.pasos;
        float yincremento = dy / this.pasos;
        g.drawString("Valores Reales", 290, 15);
        g.drawString("Valores puestos", 480, 15);
        for (int i = 0; i <= this.contar; i++) {
            dibujaPunto(g, (int) x, (int) y, Color.green);
            g.setColor(Color.black);
            g.drawString("(" + x + "," + y + ")", 300, i * 10 + 27);
            g.drawString("(" + (int) x + "," + (int) y + ")", 500, i * 10 + 27);
            x += xincremento;
            y += yincremento;
        }
        if (this.contar == this.pasos) {
            this.proceso.setEnabled(false);
            this.procesos = false;
        }
    }

    @Override
    public void init() {
        this.procesos = (this.puntos = false);
        this.xini = (this.xfin = this.yini = this.yfin = this.contar = 0);
        this.pasos = 0;
        setLayout(null);
        addMouseListener(this);
        this.proceso = new Button("<Proceso>");
        this.proceso.addActionListener(this);
        this.proceso.setLocation(280, 220);
        this.proceso.setSize(100, 33);
        add(this.proceso);
    }

    void dibujaPunto(Graphics g, int x, int y, Color c) {
        g.setColor(c);
        g.fillRect(x * 10, y * 10, 10, 10);
    }

    public void mouseClicked(MouseEvent me) {
    }

    public void mousePressed(MouseEvent me) {
        if ((me.getX() < 250) && (me.getY() < 250)) {
            this.xini = (me.getX() / 10);
            this.yini = (me.getY() / 10);
        }
    }

    public void mouseReleased(MouseEvent me) {
        if ((me.getX() < 250) && (me.getY() < 250)) {
            this.xfin = (me.getX() / 10);
            this.yfin = (me.getY() / 10);
            this.puntos = true;
            repaint();
        }
    }

    public void mouseEntered(MouseEvent me) {
    }

    public void mouseExited(MouseEvent me) {
    }

    @Override
    public void paint(Graphics g) {
        if (this.puntos) {
            dibujaPunto(g, this.xini, this.yini, Color.blue);
            dibujaPunto(g, this.xfin, this.yfin, Color.blue);
            g.setColor(Color.black);
            g.drawLine(this.xini * 10 + 5, this.yini * 10 + 5, this.xfin * 10 + 5, this.yfin * 10 + 5);
        }
        if (this.procesos) {
            correCirculo(g);
        }
        cuadro(g, Color.black);
    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    public void actionPerformed(ActionEvent ae) {
        if (ae.getSource() == this.proceso) {
            this.procesos = true;
            repaint();
        }
    }

    void correAlpha(Graphics g) {
        int dx = this.xfin - this.xini;
        int dy = this.yfin - this.yini;

        float x = this.xini;
        float y = this.yini;
        this.contar += 1;
        if (Math.abs(dy) > Math.abs(dx)) {
            this.pasos = Math.abs(dy);
        } else {
            this.pasos = Math.abs(dx);
        }
        float incremento = 1.0F / this.pasos;
        float alpha = incremento;
        g.drawString("Valores Reales", 290, 15);
        g.drawString("Valores puestos", 480, 15);
        for (int i = 0; i <= this.contar; i++) {
            dibujaPunto(g, (int) x, (int) y, Color.green);
            g.setColor(Color.black);
            g.drawString("(" + x + "," + y + ")", 300, i * 10 + 27);
            g.drawString("(" + (int) x + "," + (int) y + ")", 500, i * 10 + 27);
            x = this.xini * (1.0F - alpha) + this.xfin * alpha;
            y = this.yini * (1.0F - alpha) + this.yfin * alpha;
            alpha += incremento;
        }
        if (this.contar == this.pasos) {
            this.proceso.setEnabled(false);
            this.procesos = false;
        }
    }
}
