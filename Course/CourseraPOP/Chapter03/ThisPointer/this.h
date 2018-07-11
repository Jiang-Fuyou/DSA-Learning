#pragma once

#include <iostream>
using namespace std;

class Complex
{
public:
    Complex() {}
    Complex(double r_, double i_) : r(r_), i(i_) {}
    ~Complex() {}
    void Print() { cout << r << ", " << i << endl; }
    Complex AddOne() {
        this->r += 1;
        this->i += 1;
        this->Print();
        return *this;
    }
private:
    double r, i;
};

class A
{
public:
    A();
    ~A();
    void Hello();

private:
    int i;
};

A::A()
{}

A::~A()
{}

// 有默认参数*this，类似于python的self参数
void A::Hello()
{
    cout << "Hello" << endl;
    // cout << i << "Hello" << endl; // 如果是这样则有问题
}