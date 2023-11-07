#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>
using namespace std;

class Complex {
public:
    // Constructors
    Complex() {}; // Default constructor

    Complex(double real); // Constructor for real part

    Complex(double real, double im); // Constructor for both real and imaginary parts

    // Methods
    double get_real() const; 

    double get_im() const; 

    Complex operator+(const Complex& rhs) const; 

    Complex operator*(const Complex& rhs) const; // Multiplication operator for complex numbers

    Complex operator*(const double rhs) const; // Scalar multiplication operator

    bool operator<(const Complex& rhs) const; // Less than operator for complex numbers

private:
    double real_; // Real part of the complex number

    double im_; // Imaginary part of the complex number
};

// Helper method for scalar multiplication
Complex operator*(const double lhs, const Complex& rhs);

// Output operator for Complex numbers
ostream& operator<<(ostream& ro, Complex c);
#endif
