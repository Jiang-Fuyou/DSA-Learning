#include <iostream>
using namespace std;

class Complex
{
private:
    double r, i;

public:
    Complex(){}
    Complex(const Complex &c) // 复制构造函数必须是本类的引用
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
    /* 初始化，调用复制构造函数 */
    Complex c1;
    Complex c2(c1);
    Complex c3 = c1; // 与上条相同，是初始化

    Func(c1); // 实参不一定等于形参，因为复制构造函数不一定实现复制功能
              // 默认复制构造函数会实现复制功能

    return 0;
}