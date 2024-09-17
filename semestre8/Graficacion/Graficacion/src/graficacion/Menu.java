package graficacion;

import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Menu extends Frame implements ActionListener {

    Button botonSeno;
    Button botonCoseno;

    public Menu() {
        super("M E N U");
    }

    public void setup() {
        setSize(310, 120);
        setLayout(null);

        this.botonSeno = new Button("Seno");
        this.botonSeno.addActionListener(this);
        this.botonSeno.setSize(90, 20);
        this.botonSeno.setLocation(10, 60);
        add(this.botonSeno);
        this.botonCoseno = new Button("Coseno");
        this.botonCoseno.addActionListener(this);
        this.botonCoseno.setSize(90, 20);
        this.botonCoseno.setLocation(110, 60);
        add(this.botonCoseno);
        //addWindowListener(new Menu.1(this));
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        NuevaGrafica ns = new NuevaGrafica();
        if (e.getSource() == this.botonSeno) {
            ns.setup(0);
        } else if (e.getSource() == this.botonCoseno) {
            ns.setup(1);
        }
    }

    public static void main(String[] args) {
        Menu m = new Menu();
        m.setup();
    }
}
