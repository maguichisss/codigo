package graficacion;

import com.sun.opengl.util.Animator;
import java.awt.Frame;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.PrintStream;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

public class SierpinskyV3 implements GLEventListener, MouseListener {

    static boolean dibuja;
    static GL gl;
    static GLAutoDrawable gld;
    static GLU glu;
    static double xp;
    static double yp;

    public static void main(String[] args) {
        Frame frame = new Frame("SierpinskyV3.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new SierpinskyV3());
        canvas.addMouseListener(new SierpinskyV3());
        frame.add(canvas);
        frame.setSize(820, 640);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                new Thread(new Runnable() {
                    public void run() {
                        animator.stop();
                        System.exit(0);
                    }
                }).start();
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        animator.start();
    }

    public void init(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gld = drawable;
        glu = new GLU();
        dibuja = false;
        xp = SierpinskyV3.yp = 0.0D;
        gl.glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
        gl.glMatrixMode(5889);
        glu.gluOrtho2D(0.0D, 10.0D, 0.0D, 10.0D);
        gl.glMatrixMode(5888);
        gl.glLoadIdentity();
    }

    public void display(GLAutoDrawable drawable) {
        gl = drawable.getGL();
        gl.glClear(16384);
        gl.glLoadIdentity();
        gl.glPointSize(3.0F);
        gl.glColor3d(0.09411764705882353D, 0.5019607843137255D, 0.08235294117647059D);
        dibujaTriangulo(gl);
        gl.glFlush();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }

    public void dibujaTriangulo(GL gl) {
        Punto a = new Punto(1.0D, 1.0D);
        Punto b = new Punto(5.0D, 9.0D);
        Punto c = new Punto(9.0D, 1.0D);
        Punto p = new Punto(xp, yp);

        int i = 0;
        gl.glColor3d(0.00784313725490196D, 0.21176470588235294D, 0.023529411764705882D);

        gl.glBegin(0);
        a.dibuja(gl);
        b.dibuja(gl);
        c.dibuja(gl);
        if (dibuja) {
            do {
                p.dibuja(gl);
                double r = Math.random() * 1000.0D;
                int rprima = (int) r % 3;
                switch (rprima) {
                    case 0:
                        p.medio(a);
                        break;
                    case 1:
                        p.medio(b);
                        break;
                    case 2:
                        p.medio(c);
                }

                i++;
            } while (i < 10000);
        }
        gl.glEnd();
    }

    public void mouseClicked(MouseEvent me) {
        xp = me.getX() / 80.4D;
        yp = 10.0D - me.getY() / 60.0D;
        gld.display();
        System.out.println("Click (" + xp + "," + yp + ")");
    }

    public void mousePressed(MouseEvent me) {
        System.out.println("Oprimido (" + me.getX() + "," + me.getY() + ")");
    }

    public void mouseReleased(MouseEvent me) {
        System.out.println("Soltado (" + me.getX() + "," + me.getY() + ")");
    }

    public void mouseEntered(MouseEvent me) {
        dibuja = true;
        System.out.println("Entra (" + me.getX() + "," + me.getY() + ")");
    }

    public void mouseExited(MouseEvent me) {
        dibuja = false;
        System.out.println("Sale (" + me.getX() + "," + me.getY() + ")");
    }
}
