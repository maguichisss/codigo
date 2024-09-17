package graficacion;

import com.sun.opengl.util.Animator;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.media.opengl.glu.GLU;

public class SierpinskyV2
        implements GLEventListener {

    public static void main(String[] args) {
        Frame frame = new Frame("SierpinskyV2");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new SierpinskyV2());
        frame.add(canvas);
        frame.setSize(820, 640);
        final Animator animator = new Animator(canvas);
        frame.addWindowListener(new WindowAdapter() {

            @Override
            public void windowClosing(WindowEvent e) {
                // Run this on another thread than the AWT event queue to
                // make sure the call to Animator.stop() completes before
                // exiting
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
        GL gl = drawable.getGL();
        GLU glu = new GLU();
        gl.glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
        gl.glMatrixMode(5889);
        glu.gluOrtho2D(0.0D, 10.0D, 0.0D, 10.0D);
        gl.glMatrixMode(5888);
        gl.glLoadIdentity();
    }

    public void display(GLAutoDrawable drawable) {
        GL gl = drawable.getGL();

        gl.glClear(16384);
        gl.glLoadIdentity();
        gl.glPointSize(3.0F);
        gl.glColor3d(0.09411764705882353D, 0.5019607843137255D, 0.4745098039215686D);
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
        Punto p = new Punto(9.0D, 9.0D);

        int i = 0;
        gl.glColor3d(0.5176470588235295D, 0.996078431372549D, 0.807843137254902D);
        gl.glBegin(0);
        a.dibuja(gl);
        b.dibuja(gl);
        c.dibuja(gl);
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
        gl.glEnd();
    }
}