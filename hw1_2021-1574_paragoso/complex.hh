// Eda Grace J. Paragoso
// 2021-1574

/*
CCC102 Laboratory Assignment No. 1
Due: May 23, 2022 (Monday) at 11:55PM

This is the header file containing the declaration of the complex number
abstract data type (ADT). You do not need to do anything in this file.

You must submit the whole homework package with your
modifications/additions in the electronic submission. This homework must
comply with the homework policy as stated in the "Assignments" page.
*/

#ifndef __COMPLEX_HH__ // safeguard against multiple inclusions
#define __COMPLEX_HH__

#include <iostream>

using namespace std;

class Complex
{
public:
	// function members (the methods)

    Complex(); // default constructor
    Complex(float real); // constructor for real numbers
    Complex(float real, float imaginary);
    Complex(const Complex &source); // copy constructor

    // accessor functions
    float getReal() const; // getter for real part
    float getImaginary() const; // getter for imaginary part

    void setReal(float real); // setter for real part
    void setImaginary(float imaginary); // setter for imaginary part

    // assignment operators
    Complex & operator =(const Complex &source);

    // shorthand assignment operators
    Complex & operator +=(const Complex &source);
    Complex & operator -=(const Complex &source);
    Complex & operator *=(const Complex &source);
    Complex & operator /=(const Complex &source);

    // complex conjugate
    Complex conjugate() const;

	// complex multiplicative inverse
    Complex inverse() const;

    // complex magnitude
    float magnitude() const;

private:
    // data members (the fields)
    float _real; // data for the real part
    float _imaginary; // data for the imaginary part
};

// arithmetic operators
Complex operator +(const Complex &left, const Complex &right);
Complex operator -(const Complex &left, const Complex &right);
Complex operator *(const Complex &left, const Complex &right);
Complex operator /(const Complex &left, const Complex &right);

// comparison operators
int operator == (const Complex &left, const Complex &right);
int operator != (const Complex &left, const Complex &right);


// stream input/output (these are already implemented)
ostream & operator << (ostream &out, const Complex &value);
istream & operator >> (istream &in, Complex &destination);

#endif
