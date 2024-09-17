package examen2;

class Complejo {

    double re;
    double im;

    Complejo(double r, double i) {
        this.re = r;
        this.im = i;
    }
    
    // Method for squaring a ComplexNumber
    public Complejo square(){
        return new Complejo(re*re - im*im, 2*re*im);
    }
    
    // Method for adding 2 complex numbers
    public Complejo add(Complejo cn){
        return new Complejo(re+cn.re, im+cn.im);
    }
    // Method for calculating magnitude^2 (how close the number is to infinity)
    public double magnitude(){
        return Math.sqrt(re*re+im*im);
        //return a*a+b*b;
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
