#pragma once

#include "tyre.h"
#include "engine.h"

class CCar
{
public:
    CCar(int p, int tr, int tw);
    ~CCar();

private:
    int price;
    CTyre tyre;
    CEngine engine;
};

CCar::CCar(int p, int tr, int tw) :
    price(p),
    tyre(tr, tw)
{}

CCar::~CCar()
{}