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
    // ���Complex c��ֵ
    friend ostream &operator<<(ostream &out, const Complex &c);
    // ����Complexֵ�������ݸ�c
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

    // string���find�������ӵ�0���ַ���ʼ���ң���һ�γ���"+"��λ��
    int pos = s.find("+", 0);
    
    // string���substr��������ȡ�ӵ�0��λ�ÿ�ʼ��pos��Ԫ�ص��Ӵ�
    string sTmp = s.substr(0, pos);
    // string���c_str()��������string��Ķ���ת����const char *����
    c.r = atof(sTmp.c_str());
    
    sTmp = s.substr(pos + 1, s.length() - pos - 2);
    c.i = atof(sTmp.c_str());

    return in;
}