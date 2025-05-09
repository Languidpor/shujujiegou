/*
** Name: complex.h
** Author: Leo Liberti
** Purpose: header file for a complex numbers class
** Source: GNU C++
** History: 061019 work started
** 可以在此基础上进行改进.
*/
#ifndef _COMPLEX_H
#define _COMPLEX_H
#include<string>
#include<iostream>

class Complex 
{
public:
    Complex();
    Complex(double re, double im);
    ~Complex();
    double getReal(void);
    double getImaginary(void);
    void setReal(double re);
    void setImaginary(double im);
    void fromString(const std::string& complexString);
    Complex operator+(Complex& theComplex);
    Complex operator-(Complex& theComplex);
    Complex operator*(Complex& theComplex);
    Complex operator/(Complex& theComplex);
private:
    double real;
    double imag;
};

std::ostream& operator<<(std::ostream& out, Complex& theComplex);
#endif // COMPLEX_H
