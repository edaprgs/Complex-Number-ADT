// Eda Grace J. Paragoso
// 2021-1574

/*
CCC102 Laboratory Assignment No. 1
Due: May 23, 2022 (Monday) at 11:55PM

Provide the missing implementations of the complex number abstract data
type (ADT) in this file.

You must submit the whole homework package with your
modifications/additions in the electronic submission. This homework must
comply with the homework policy as stated in the "Assignments" page.
*/

#include <iostream>
#include <math.h>

#include "complex.hh"

using namespace std;

// constructors
Complex::Complex() {
    _real = 0; // initializing data for the real part
    _imaginary = 0; // initializing data for the imaginary part
}
Complex::Complex(float real) {
    _real = real; // constructor for real numbers
}
Complex::Complex(float real, float imaginary) {
    _real = real; // constructor for real numbers
    _imaginary = imaginary; // constructor for imaginary numbers
}
Complex::Complex(const Complex &source) {
    _real = source._real;
    _imaginary = source._imaginary;
} // Copy constructor is called to initialize a new object for complex numbers as a copy of the existing object

// accessor functions
float Complex::getReal() const {
    return _real; // getter for real part
}
float Complex::getImaginary() const {
    return _imaginary; // getter for imaginary part
}
void Complex::setReal(float real) {
    _real = real; // setter for real part
}
void Complex::setImaginary(float imaginary) {
    _imaginary = imaginary; // setter for imaginary part
}

// assignment operators
Complex & Complex::operator =(const Complex &source) {
    _real = source._real;
    _imaginary = source._imaginary;
    return *this;
}
Complex & Complex::operator +=(const Complex &source) {
    float real = _real + source.getReal(); // to add real numbers
    float imaginary = _imaginary + source.getImaginary(); // to add imaginary numbers
    _real = real;
    _imaginary = imaginary;
    return *this;
}
Complex & Complex::operator -=(const Complex &source) {
    float real = _real - source.getReal(); // to subtract real numbers
    float imaginary = _imaginary - source.getImaginary(); // to subtract imaginary numbers
    _real = real;
    _imaginary = imaginary;
    return *this;
}
Complex & Complex::operator *=(const Complex &source) {
    float real = _real * source.getReal() - _imaginary * source.getImaginary();
    float imaginary = _real * source.getImaginary() + _imaginary * source.getReal();
    _real = real;
    _imaginary = imaginary;
    return *this; // to solve for the product of two complex numbers
}
    Complex & Complex::operator /=(const Complex &source) {
    float real = ((_real * source.getReal() + _imaginary * source.getImaginary()) / (source.getReal() * source.getReal() + source.getImaginary() * source.getImaginary()));
    float imaginary = ((_imaginary * source.getReal() - _real * source.getImaginary()) / (source.getReal() * source.getReal() + source.getImaginary() * source.getImaginary()));
    _real = real;
    _imaginary = imaginary;
    return *this; // to solve for the quotient of two complex numbers
}

// complex conjugate
Complex Complex::conjugate() const {
    return Complex(_real,-_imaginary); // the get the conjugate of the complex numbers
}

// complex multiplicative inverse
Complex Complex::inverse() const {
    return Complex(_real / (_real * _real + _imaginary * _imaginary), -_imaginary / (_real * _real + _imaginary * _imaginary));
} // to solve for the multiplicative inverse of the complex numbers

float Complex::magnitude() const {
    return sqrt(_real * _real + _imaginary * _imaginary);
} // to calculate the magnitude of a complex number

// arithmetic operators
Complex operator +(const Complex &left, const Complex &right) {
    float _real = left.getReal() + right.getReal(); // to add real numbers
    float _imaginary = left.getImaginary() + right.getImaginary(); // to add imaginary numbers
    return Complex(_real,_imaginary);
}
Complex operator -(const Complex &left, const Complex &right) {
    float _real = left.getReal() - right.getReal(); // to subtract real numbers
    float _imaginary = left.getImaginary() - right.getImaginary(); // to subtract imaginary numbers
    return Complex(_real,_imaginary);
}
Complex operator *(const Complex &left, const Complex &right) {
    float _real = left.getReal() * right.getReal() - left.getImaginary() * right.getImaginary();
    float _imaginary = left.getReal() * right.getImaginary() + left.getImaginary() * right.getReal();
    return Complex(_real,_imaginary); // to solve for the product of two complex numbers
}
Complex operator /(const Complex &left, const Complex &right) {
    float _real = ((left.getReal() * right.getReal() + left.getImaginary() * right.getImaginary()) / (right.getReal() * right.getReal() + right.getImaginary() * right.getImaginary()));
    float _imaginary = ((left.getImaginary() * right.getReal() - left.getReal() * right.getImaginary()) / (right.getReal() * right.getReal() + right.getImaginary() * right.getImaginary()));
    return Complex(_real,_imaginary); // to solve for the quotient of two complex numbers
}

//comparing the equality of the two complex numbers
int operator == (const Complex &left, const Complex &right) {
    return (left.getReal() == right.getReal() && left.getImaginary() == right.getImaginary()); //to check if the two complex numbers are equal
}
int operator != (const Complex &left, const Complex &right) {
    return (left.getReal() != right.getReal() || left.getImaginary() != right.getImaginary()); //to check if the two complex numbers are not equal
}

// stream inserter implementation
ostream & operator << (ostream &out, const Complex &value)
{
    // stream output of a complex number in the format
	// (real, imaginary)
    out << "(" << value.getReal() << ", " << value.getImaginary() <<
		")";

    return out;
}

// stream extractor implementation
istream & operator >> (istream &in, Complex &destination)
{
    // stream input of complex number
    float real = 0, imaginary = 0;

    char c;

    // read '('
    in >> c;
    if (c == '(')
    {
        // read real part
        in >> real;

        // read ','
        in >> c;
        if (c == ',')
        {
            // read imaginary part
            in >> imaginary;
        }
        else   // no imaginary part
        {
            in.putback(c);
        }

        // read ')'
        in >> c;
        if (c != ')')
        {
            in.putback(c);
        }
    }
    else // no imaginary part
    {
        in.putback(c);
        in >> real;
    }

    // do the assignment
    Complex result(real, imaginary);
    destination = result;

    // return the stream
    return in;
}
