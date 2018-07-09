#pragma once

#include <iostream>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(double r_, double i_ = 0);
    ~Complex();
    void Set(double r_, double i_);
private:
    double r, i;
};

Complex::Complex()
{
    cout << "Constructor 1 called." << endl;
}

Complex::Complex(double r_, double i_)
{
    r = r_;
    i = i_;
    cout << "Constructor 2 called." << endl;
}

Complex::~Complex()
{
    cout << "Destructor called." << endl;
}

void Complex::Set(double r_, double i_)
{
    r = r_;
    i = i_;
}