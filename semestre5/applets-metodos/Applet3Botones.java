import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import java.math.*;

public class Applet3Botones extends Applet implements ActionListener
{
 Label etiqueta1, etiqueta2, etiqueta3;
 TextField caja1, caja2, caja3;
 Button boton1, boton2, boton3, boton4;
 int num1, num2, num3, suma, resta, multiplicacion, division;
 
 public void init()
 {
   etiqueta1=new Label("Introduce un numero:");
   etiqueta1.setSize(200,10);
   etiqueta1.setLocation(5,15);
   add(etiqueta1);
   
   caja1=new TextField(20);
   caja1.setSize(80,20);
   caja1.setLocation(220,10);
   add(caja1);

   etiqueta2=new Label("Introduce otro numero:");
   etiqueta2.setSize(200,20);
   etiqueta2.setLocation(5,40);
   add(etiqueta2);
   
   caja2=new TextField(20);
   caja2.setSize(80,20);
   caja2.setLocation(220,40);
   add(caja2);

   etiqueta3=new Label("El resultado de la operacion es:");
   etiqueta3.setSize(220,30);
   etiqueta3.setLocation(5,75);
   add(etiqueta3);
   
   caja3=new TextField(20);
   caja3.setSize(80,20);
   caja3.setLocation(220,65);
   add(caja3);

   boton1=new Button(" Suma " );
   boton1.setSize(50,20);
   boton1.setLocation(510,200);
   boton1.addActionListener(this);
   add(boton1);
   suma=0;
   
   boton2=new Button(" Resta " );
   boton2.setSize(50,20);
   boton2.setLocation(330,20);
   boton2.addActionListener(this);
   add(boton2);
   resta=0;
   
   boton3=new Button(" Multiplicacion " );
   boton3.setSize(50,20);
   boton3.setLocation(310, 50);
   boton3.addActionListener(this);
   add(boton3);
   multiplicacion=0;

   boton4=new Button(" Division " );
   boton4.setSize(50,20);
   boton4.setLocation(310, 50);
   boton4.addActionListener(this);
   add(boton4);
   division=0;
 } 
   
 public void actionPerformed(ActionEvent z)
 {  
   if(z.getSource()==boton1)
      {
        num1=Integer.parseInt(caja1.getText());
        num2=Integer.parseInt(caja2.getText());
        suma=num1+num2;
        caja3.setText(Integer.toString(suma));
      }
   
   if(z.getSource()==boton2)
      {
        num1=Integer.parseInt(caja1.getText());
        num2=Integer.parseInt(caja2.getText());       
        resta=num1-num2;
        caja3.setText(Integer.toString(resta));
      }    
    
    if(z.getSource()==boton3)
      {
        num1=Integer.parseInt(caja1.getText());
        num2=Integer.parseInt(caja2.getText());       
        multiplicacion=num1*num2;
        caja3.setText(Integer.toString(multiplicacion));
      }    
    
    if(z.getSource()==boton4)
      {
        num1=Integer.parseInt(caja1.getText());
        num2=Integer.parseInt(caja2.getText());       
        division=num1/num2;
        caja3.setText(Integer.toString(division));
      }      
  } 
}