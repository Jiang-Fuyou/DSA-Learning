#pragma once

class Complex
{
public:
    Complex(double r_, double i_) : r(r_), i(i_) {};
    ~Complex() {};
    Complex operator+(const double r);
    friend Complex operator+(const double r, const Complex &c);
private:
    double r, i;
};

Complex Complex::operator+(const double r)
{
    return Complex(this->r + r, this->i);
}

Complex operator+(const double r, const Complex &c)
{
    return Complex(c.r + r, c.i);
}