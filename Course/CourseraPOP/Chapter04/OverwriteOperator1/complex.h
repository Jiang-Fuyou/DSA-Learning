#pragma once

#include <iostream>
using namespace std;

class Complex
{
public:
    // double r, i;
    Complex(double r_ = 0.0, double i_ = 0.0) : r(r_), i(i_) {}
    ~Complex();
    Complex operator+(const Complex &a);
    Complex operator-(const Complex &a);
    void Print();
private:
    double r, i;
};

Complex::~Complex()
{}

//Complex operator+(const Complex &a, const Complex &b)
//{
//    return Complex(a.r + b.r, a.i + b.i);
//}

Complex Complex::operator+(const Complex &a)
{
    return Complex(this->r + a.r, this->i + a.i);
}

Complex Complex::operator-(const Complex &a)
{
    return Complex(this->r - a.r, this->i - a.i);
}

void Complex::Print()
{
    cout << this->r << " + " << this->i << "i" << endl;
}