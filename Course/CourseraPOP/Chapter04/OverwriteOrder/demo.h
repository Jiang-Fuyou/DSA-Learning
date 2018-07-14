#pragma once

class CDemo
{
public:
    CDemo();
    CDemo(int i = 0);
    ~CDemo();
    // Demo s; (int)s; // Ïàµ±ÓÚs.int()
    operator int() { return n; }
    CDemo operator++();
    CDemo operator++(int n);
    friend CDemo operator--(CDemo &d);
    friend CDemo operator--(CDemo &d, int n);
private:
    int n;
};

CDemo::CDemo()
{}

CDemo::CDemo(int i)
{
    n = i;
}

CDemo::~CDemo()
{}

CDemo CDemo::operator++()
{
    n++;
    return *this;
}

CDemo CDemo::operator++(int n)
{
    CDemo tmp(*this);
    n++;
    return tmp;
}

CDemo operator--(CDemo &d)
{
    d.n--;
    return d;
}

CDemo operator--(CDemo &d, int n)
{
    CDemo tmp(d);
    d.n--;
    return tmp;
}