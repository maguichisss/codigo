// Dibujo de polígonos.
import java.awt.*;
import javax.swing.*;

public class DibujarPoligonos extends JFrame {

   // establecer cadena de barra de título y dimensiones de la ventana
   public DibujarPoligonos()
   {
      super( "Dibujo de polígonos" );

      setSize( 500, 500 );
      setVisible( true );
   }

   // dibujar polígonos y polilíneas
   public void paint( Graphics g )
   {
      super.paint( g );  // llamar al método paint de la superclase

      int valoresX[] = { 20, 40, 50, 30, 20, 15, 300 };
      int valoresY[] = { 50, 50, 60, 80, 80, 60, 400 };
      Polygon poligono1 = new Polygon( valoresX, valoresY, 7 );

      g.drawPolygon( poligono1 );

      int valoresX2[] = { 70, 90, 100, 80, 70, 65, 60 };
      int valoresY2[] = { 100, 100, 110, 110, 130, 110, 90 };

      g.drawPolyline( valoresX2, valoresY2, 7 );

      int valoresX3[] = { 120, 140, 150, 190 };
      int valoresY3[] = { 40, 70, 80, 60 };

      g.fillPolygon( valoresX3, valoresY3, 4);

      Polygon poligono2 = new Polygon();
      poligono2.addPoint( 165, 135 );
      poligono2.addPoint( 175, 150 );
      poligono2.addPoint( 270, 200 );
      poligono2.addPoint( 200, 220 );
      poligono2.addPoint( 130, 180 );

      g.fillPolygon( poligono2 );

   } // fin del método paint

   // ejecutar la aplicación
   public static void main( String args[] )
   {
      JFrame.setDefaultLookAndFeelDecorated(true);
      DibujarPoligonos aplicacion = new DibujarPoligonos();
      aplicacion.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
   }

} // fin de la clase DibujarPoligonos