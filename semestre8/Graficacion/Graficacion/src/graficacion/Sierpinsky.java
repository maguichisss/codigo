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

public class Sierpinsky
        implements GLEventListener {

    public static void main(String[] args) {
        Frame frame = new Frame("SierpinskyV1");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Sierpinsky());
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
        int i = 0;
        double ax = 1.0D;
        double ay = 1.0D;
        double bx = 5.0D;
        double by = 9.0D;
        double cx = 9.0D;
        double cy = 1.0D;
        double px = 9.0D;
        double py = 9.0D;
        gl.glBegin(0);
        gl.glVertex2d(ax, ay);
        gl.glVertex2d(bx, by);
        gl.glVertex2d(cx, cy);
        do {
            gl.glVertex2d(px, py);
            double r = Math.random() * 1000.0D;
            int rprima = (int) r % 3;
            switch (rprima) {
                case 0:
                    px = (px + ax) / 2.0D;
                    py = (py + ay) / 2.0D;
                    break;
                case 1:
                    px = (px + bx) / 2.0D;
                    py = (py + by) / 2.0D;
                    break;
                case 2:
                    px = (px + cx) / 2.0D;
                    py = (py + cy) / 2.0D;
            }
            i++;
        } while (i < 10000);
        gl.glEnd();
    }
}