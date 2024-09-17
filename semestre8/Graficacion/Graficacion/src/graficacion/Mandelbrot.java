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

public class Mandelbrot implements GLEventListener {

    static GL gl;
    int maxite;
    int maxren;
    int maxcol;
    int maxton;
    int maxmag;
    double xmax;
    double ymax;
    double xmin;
    double ymin;
    double[] Q;

    public static void main(String[] args) {
        Frame frame = new Frame("Mandelbrot");
        GLCanvas canvas = new GLCanvas();
        canvas.addGLEventListener(new Mandelbrot());
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
        this.Q = new double[480];
        this.maxcol = 640;
        this.maxren = 480;
        this.maxton = 512;
        this.maxite = 512;
        this.maxmag = 4;
        this.xmin = -2.0D;
        this.xmax = 1.2D;
        this.ymin = -1.2D;
        this.ymax = 1.2D;
        gl = drawable.getGL();
        gl.glClearColor(0.5F, 0.5F, 0.5F, 0.0F);
    }

    public void display(GLAutoDrawable drawable) {
        gl.glClear(GL.GL_COLOR_BUFFER_BIT);
        dibuja();
        gl.glFlush();
    }

    public void reshape(GLAutoDrawable drawable, int x, int y, int width, int height) {
        GLU glu = new GLU();
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluOrtho2D(0.0D, 640.0D, 0.0D, 480.0D);
    }

    public void displayChanged(GLAutoDrawable drawable, boolean modeChanged, boolean deviceChanged) {
    }

    public void dibuja() {
        gl.glBegin(0);
        double deltaP = (this.xmax - this.xmin) / this.maxcol;
        double deltaQ = (this.ymax - this.ymin) / this.maxren;
        this.Q[0] = this.ymax;
        double p = this.xmin;
        for (int ren = 1; ren < this.maxren; ren++) {
            this.Q[ren] = (this.Q[(ren - 1)] - deltaQ);
        }
        for (int col = 0; col <= this.maxcol; col++) {
            for (int ren = 0; ren < this.maxren; ren++) {
                double x = 0.0D;
                double y = 0.0D;
                double x2 = 0.0D;
                double y2 = 0.0D;
                int color = 1;
                while ((color < this.maxite) && (x2 + y2 < this.maxmag)) {
                    x2 = x * x;
                    y2 = y * y;
                    y *= x;
                    y = y + y + this.Q[ren];
                    x = x2 - y2 + p;
                    color++;
                }
                color %= 5;
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

                gl.glVertex2i(col, ren);
            }
            p += deltaP;
        }
        gl.glEnd();
        gl.glFlush();
    }
}
