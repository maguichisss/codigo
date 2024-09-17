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

public class NuevaGrafica implements GLEventListener {

    static int control;

    public void setup(int c) {
        control = c;
        Frame frame = new Frame("NuevaGrafica.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new NuevaGrafica());
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
        GL gl = drawable.getGL();
        GLU glu = new GLU();

        gl.glMatrixMode(5889);
        gl.glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
        glu.gluOrtho2D(-10.0D, 10.0D, -1.5D, 1.5D);
        gl.glMatrixMode(5888);
    }

    public void display(GLAutoDrawable drawable) {
        GL gl = drawable.getGL();
        gl.glClear(16384);
        gl.glLoadIdentity();
        dibujaEjes(gl, -9.0F, 9.0F, -1.0F, 1.0F);
        dibujaSeno(gl);
        gl.glFlush();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }

    public void dibujaEjes(GL gl, float xi, float xf, float yi, float yf) {
        gl.glLineWidth(8.0F);
        gl.glColor3f(0.0F, 0.0F, 0.0F);
        gl.glBegin(1);
        gl.glVertex2f(xi, 0.0F);
        gl.glVertex2f(xf, 0.0F);
        gl.glVertex2f(0.0F, yi);
        gl.glVertex2f(0.0F, yf);
        gl.glEnd();
    }

    public void dibujaSeno(GL gl) {
        double inc = 0.006283185307179587D;
        gl.glLineWidth(2.0F);
        gl.glBegin(3);
        for (double i = -9.0D; i <= 9.0D; i += inc) {
            gl.glColor3f(0.8627451F, 0.047058824F, 0.43529412F);
            switch (control) {
                case 0:
                    gl.glVertex2d(i, Math.sin(i));
                    break;
                case 1:
                    gl.glVertex2d(i, Math.cos(i));
            }
        }
        gl.glEnd();
    }
}
