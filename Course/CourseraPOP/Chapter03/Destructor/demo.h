#pragma once

#include <iostream>
using namespace std;

class Demo
{
public:
    Demo(int id_);
    ~Demo();

private:
    int id;
};

Demo::Demo(int id_)
{
    id = id_;
    cout << "ID = " << id << ". Constructor called." << endl;
}

Demo::~Demo()
{
    cout << "ID = " << id << ". Destructor called." << endl;
}