package graficacion;

import java.awt.Button;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Menu extends Frame implements ActionListener {

    Button botonDDA;
    Button botonBresenham;
    Button botonPuntoMedio;
    Button botonAlpha;
    Button botonLineaPuntoMedio;
    Button cerrar;
    int espacio = 30;

    public Menu() {
        super("M E N U");
    }

    public void setup() {
        setSize(210, 260);
        setLayout(null);
        botones();
        
    }

    public void actionPerformed(ActionEvent e) {
        NuevaVentana ventana = new NuevaVentana();
        
        if          (e.getSource() == this.botonDDA)        {
            ventana.setup(botonDDA.getLabel(), 0);
            
        }else if    (e.getSource() == this.botonBresenham)  {
            ventana.setup(botonBresenham.getLabel(), 1);
            
        }else if    (e.getSource() == this.botonPuntoMedio)  {
            ventana.setup(botonPuntoMedio.getLabel(), 2);
            
        }else if    (e.getSource() == this.botonAlpha)  {
            ventana.setup(botonAlpha.getLabel(), 3);
            
        }else if    (e.getSource() == this.botonLineaPuntoMedio)  {
            ventana.setup(botonLineaPuntoMedio.getLabel(), 4);
            
        }else if    (e.getSource() == this.cerrar)          {
            System.out.println("salir");
            System.exit( 0 );
        }
    }
    
    public void botones(){
        
        botonDDA = new Button("DDA");
        ponerBoton(botonDDA, 0);
        
        botonBresenham = new Button("Bresenham");
        ponerBoton(botonBresenham, 1);
        
        botonPuntoMedio = new Button("Circulo Punto Medio");
        ponerBoton(botonPuntoMedio, 2);
        
        botonAlpha = new Button("Alpha");
        ponerBoton(botonAlpha, 3);
        
        botonLineaPuntoMedio = new Button("Linea Punto Medio");
        ponerBoton(botonLineaPuntoMedio, 4);
        
        cerrar = new Button("Cerrar");
        ponerBoton(cerrar, 5);
        
        setVisible(true);
        
    }
    
    public void ponerBoton(Button boton, int n){
        boton.addActionListener(this);
        boton.setSize(150, 20);
        boton.setLocation(30, 60+n*espacio);
        add(boton);
        
    }

    public static void main(String[] args) {
        Menu m = new Menu();
        m.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {
                    public void run() {
                        System.exit(0);
                    }
                }).start();
            }
        });
        m.setup();
    }
}
