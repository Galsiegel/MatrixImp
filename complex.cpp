#ifndef _COMPLEX_CPP_
#define _COMPLEX_CPP_
#include "complex.h"
#include <math.h>

// Constructor with only real part
Complex::Complex(double real) : real_(real), im_(0) {}

// Constructor with real and imaginary parts
Complex::Complex(double real, double im) : real_(real), im_(im) {}

// Get the real part of the complex number
double Complex::get_real() const {
    return this->real_;
}

// Get the imaginary part of the complex number
double Complex::get_im() const {
    return this->im_;
}

// Addition of two complex numbers
Complex Complex::operator+(const Complex& rhs) const {
    double real = this->get_real() + rhs.get_real();
    double im = this->get_im() + rhs.get_im();
    Complex sum(real, im);
    return sum;
}

// Multiplication of two complex numbers
Complex Complex::operator*(const Complex& rhs) const {
    double real = this->get_real() * rhs.get_real() - this->get_im() * rhs.get_im();
    double im = this->get_real() * rhs.get_im() + rhs.get_real() * this->get_im();
    Complex mul(real, im);
    return mul;
}

// Multiplication of a complex number by a scalar
Complex Complex::operator*(const double rhs) const {
    double real = this->get_real() * rhs;
    double im = this->get_im() * rhs;
    Complex mul(real, im);
    return mul;
}

// Comparison operator to check if one complex number is less than another
bool Complex::operator<(const Complex& rhs) const {
    return this->get_real() < rhs.get_real();
}

// Multiplication of a scalar by a complex number
Complex operator*(const double lhs, const Complex& rhs) {
    double real = rhs.get_real() * lhs;
    double im = rhs.get_im() * lhs;
    Complex mul(real, im);
    return mul;
}

// Printing operator to display the complex number
ostream& operator<<(ostream& ro, Complex c) {
    cout << c.get_real() << " + " << c.get_im() << "i";
    return cout;
}

#endif
