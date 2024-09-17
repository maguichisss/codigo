package graficacion;

class Complejo {

    double re;
    double im;

    Complejo(double r, double i) {
        this.re = r;
        this.im = i;
    }

    public void suma(Complejo z) {
        this.re += z.re;
        this.im += z.im;
    }

    public void mult(Complejo z) {
        double r = this.re * z.re - this.im * z.im;
        double i = this.re * z.im + this.im * z.re;
        this.re = r;
        this.im = i;
    }

    public double abs() {
        return Math.sqrt(this.re * this.re + this.im * this.im);
    }
}
