#pragma once

#include <iostream>
using namespace std;

class CCar;

class CDriver
{
public:
    CDriver();
    ~CDriver();
    void ModifyCar(CCar *pCar);

private:
};

CDriver::CDriver()
{}

CDriver::~CDriver()
{}

class CCar
{
public:
    CCar(int price_) : price(price_) {};
    ~CCar();
    void PrintPrice();

private:
    int price;

    friend int MostExpensiveCar(CCar cars[], int total);
    friend void CDriver::ModifyCar(CCar *pCar);
};

CCar::~CCar()
{}

void CCar::PrintPrice()
{
    cout << "Price: " << price << endl;
}

void CDriver::ModifyCar(CCar *pCar)
{
    pCar->price += 1000;
}

int MostExpensiveCar(CCar cars[], int total)
{
    int tmpMax = -1;
    for (size_t i = 0; i < total; i++) {
        if (cars[i].price > tmpMax) {
            tmpMax = cars[i].price;
        }
    }

    return tmpMax;
}