#pragma once

#include <iostream>
#include <string>
#include <istream>
#include <ostream>
using namespace std;

class Complex
{
public:
    Complex() {};
    Complex(double r_, double i_) : r(r_), i(i_) {};
    ~Complex() {};
    // 输出Complex c的值
    friend ostream &operator<<(ostream &out, const Complex &c);
    // 读入Complex值，并传递给c
    friend istream &operator>>(istream &in, Complex &c);
private:
    double r, i;
};

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.r << " + " << c.i << "i";
    return out;
}

istream &operator>>(istream &in, Complex &c)
{
    string s;
    in >> s;

    // string类的find函数，从第0个字符开始查找，第一次出现"+"的位置
    int pos = s.find("+", 0);
    
    // string类的substr函数，获取从第0个位置开始，pos个元素的子串
    string sTmp = s.substr(0, pos);
    // string类的c_str()函数，将string类的对象转换成const char *类型
    c.r = atof(sTmp.c_str());
    
    sTmp = s.substr(pos + 1, s.length() - pos - 2);
    c.i = atof(sTmp.c_str());

    return in;
}