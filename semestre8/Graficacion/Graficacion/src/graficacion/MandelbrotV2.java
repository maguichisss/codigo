package graficacion;

import com.sun.opengl.util.Animator;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;

public class MandelbrotV2 implements GLEventListener {

    static GL gl;

    public static void main(String[] args) {
        Frame frame = new Frame("MandelbrotV1.java");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new MandelbrotV2());
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
        gl.glClearColor(0.5F, 0.5F, 0.5F, 0.0F);
    }

    public void display(GLAutoDrawable drawable) {
        gl.glClear(16384);
        dibuja();
        gl.glFlush();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        gl.glMatrixMode(5889);
        gl.glLoadIdentity();
        gl.glOrtho(-2.0D, 1.2D, -1.2D, 1.2D, -1.0D, 1.0D);
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }

    int mandel(Complejo c, Complejo z, int n) {
        int r;
        if ((z.abs() < 2.0D) && (n < 1000)) {
            z.mult(z);
            z.suma(c);
            r = mandel(c, z, n + 1);
        } else {
            r = n;
        }
        return r;
    }

    public void dibuja() {
        gl.glBegin(0);
        for (double x = -2.0D; x <= 1.2D; x += 0.0050D) {
            for (double y = -1.2D; y <= 1.2D; y += 0.0050D) {
                Complejo z = new Complejo(0.0D, 0.0D);
                Complejo c = new Complejo(x, y);
                int color = mandel(c, z, 0) % 5;
                switch (color) {
                    case 0:
                        gl.glColor3f(1.0F, 0.0F, 0.0F);
                        break;
                    case 1:
                        gl.glColor3f(0.0F, 1.0F, 0.0F);
                        break;
                    case 2:
                        gl.glColor3f(0.0F, 0.0F, 1.0F);
                        break;
                    case 3:
                        gl.glColor3f(1.0F, 1.0F, 0.0F);
                        break;
                    case 4:
                        gl.glColor3f(1.0F, 0.0F, 1.0F);
                }

                gl.glVertex2d(x, y);
            }
        }
        gl.glEnd();
        gl.glFlush();
    }
}
