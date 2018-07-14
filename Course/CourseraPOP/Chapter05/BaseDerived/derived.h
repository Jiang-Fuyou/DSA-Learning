#pragma once

#include "base.h"

class Derived : public Base
{
public:
    Derived();
    ~Derived();
    int i;
    void access();
    void func() {};
private:
};

Derived::Derived()
{}

Derived::~Derived()
{}

void Derived::access()
{
    // j = 5; // error!
    i = 5;
    Base::i = 5;
    func();
    Base::func();
}