import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class Circulo extends Applet implements ActionListener
{
 Label etiqueta1, etiqueta2,etiqueta3,etiqueta4;
 TextField caja1, caja2,caja3;
 Button boton1,boton2;
 float radio;
 double area,perimetro;
 
 public void init()
 {
   
   etiqueta4=new Label("Programa para Círculo");
   etiqueta4.setSize(200,10);
   etiqueta4.setLocation(5,15);
   add(etiqueta4); 
  
   etiqueta1=new Label("Radio");
   etiqueta1.setSize(200,10);
   etiqueta1.setLocation(10,15);
   add(etiqueta1);
   
   caja1=new TextField(20);
   caja1.setSize(80,20);
   caja1.setLocation(220,10);
   add(caja1);

   etiqueta2=new Label("Area:");
   etiqueta2.setSize(200,20);
   etiqueta2.setLocation(10,40);
   add(etiqueta2);
   
   caja2=new TextField(20);
   caja2.setSize(80,20);
   caja2.setLocation(220,40);
   add(caja2);

   etiqueta3=new Label("Perimetro:");
   etiqueta3.setSize(220,30);
   etiqueta3.setLocation(10,75);
   add(etiqueta3);
   
   caja3=new TextField(20);
   caja3.setSize(80,20);
   caja3.setLocation(220,65);
   add(caja3);
   
   
   boton1=new Button("Calcular Area" );
   boton1.setSize(220,20);
   boton1.setLocation(20,100);
   boton1.addActionListener(this);
   add(boton1);
   area=0;
      
   boton2=new Button("Calcular Perimetro" );
   boton2.setSize(220,20);
   boton2.setLocation(40,100);
   boton2.addActionListener(this);
   add(boton2);
   perimetro=0;
 } 
   
 public void actionPerformed(ActionEvent z)
 {  
   if(z.getSource()==boton1)
      {
        radio=Float.parseFloat(caja1.getText());
        area=(3.1416*radio)*radio;
        caja2.setText(Double.toString(area));
      }
   if(z.getSource()==boton2)
      {
        radio=Float.parseFloat(caja1.getText());
        perimetro=(6.2832*radio);
        caja3.setText(Double.toString(perimetro));
      }
  
  } 
}