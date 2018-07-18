#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

/******************************************************************************/

class CShape
{
public:
    CShape();
    ~CShape();
    virtual double Area() = 0;
    virtual void PrintInfo() = 0;
};

CShape::CShape()
{}

CShape::~CShape()
{}

/******************************************************************************/

class CRectangle : public CShape
{
public:
    CRectangle();
    ~CRectangle();
    virtual double Area();
    virtual void PrintInfo();
    int w, h;
};

CRectangle::CRectangle()
{}

CRectangle::~CRectangle()
{}

double CRectangle::Area()
{
    return w * h;
}

void CRectangle::PrintInfo()
{
    cout << "Rectangle: " << Area() << endl;
}

/******************************************************************************/

class CCircle : public CShape
{
public:
    CCircle();
    ~CCircle();
    virtual double Area();
    virtual void PrintInfo();
    int r;
};

CCircle::CCircle()
{}

CCircle::~CCircle()
{}

double CCircle::Area()
{
    return 3.14 * r * r;
}

void CCircle::PrintInfo()
{
    cout << "Circle: " << Area() << endl;
}

/******************************************************************************/

class CTriangle : public CShape
{
public:
    CTriangle();
    ~CTriangle();
    virtual double Area();
    virtual void PrintInfo();
    int a, b, c;
};

CTriangle::CTriangle()
{}

CTriangle::~CTriangle()
{}

double CTriangle::Area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void CTriangle::PrintInfo()
{
    cout << "Triangle:" << Area() << endl;
}

/******************************************************************************/