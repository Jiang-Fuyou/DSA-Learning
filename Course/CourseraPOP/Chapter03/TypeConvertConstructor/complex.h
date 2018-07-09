#pragma once

#include <iostream>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(int i);
    Complex(double r_, double i_);
    ~Complex();
private:
    double r, i;
};

Complex::Complex()
{
    cout << "Default constructor called." << endl;
}

Complex::Complex(int i)
{
    cout << "Type convertion constructor called." << endl;
    r = i;
    i = 0;
}

Complex::Complex(double r_, double i_)
{
    cout << "Normal constructor called." << endl;
    r = r_;
    i = i_;
}

Complex::~Complex()
{
    cout << "Destructor called." << endl;
}