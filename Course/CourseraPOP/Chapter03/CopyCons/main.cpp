#include <iostream>
using namespace std;

class Complex
{
private:
    double r, i;

public:
    Complex(){}
    Complex(const Complex &c) // ���ƹ��캯�������Ǳ��������
    {
        this->r = c.r;
        this->i = c.i;
        cout << "Copy Constructor called." << endl;
    }
};

void Func(Complex c) {}

Complex Func()
{
    Complex b;
    return b;
}

int main()
{
    /* ��ʼ�������ø��ƹ��캯�� */
    Complex c1;
    Complex c2(c1);
    Complex c3 = c1; // ��������ͬ���ǳ�ʼ��

    Func(c1); // ʵ�β�һ�������βΣ���Ϊ���ƹ��캯����һ��ʵ�ָ��ƹ���
              // Ĭ�ϸ��ƹ��캯����ʵ�ָ��ƹ���

    return 0;
}