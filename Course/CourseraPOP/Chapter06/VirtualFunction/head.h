#pragma once

#include <iostream>
using namespace std;

class Base
{
public:
    Base();
    ~Base();
    virtual void SomeVirtualFunction();
private:

};

Base::Base()
{}

Base::~Base()
{}

void Base::SomeVirtualFunction()
{
    cout << "Virtual function in Base class." << endl;
}


class Derived : public Base
{
public:
    Derived();
    ~Derived();
    virtual void SomeVirtualFunction();
private:

};

Derived::Derived()
{}

Derived::~Derived()
{}

void Derived::SomeVirtualFunction()
{
    cout << "Virtual function in Derived class." << endl;
}