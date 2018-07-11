#pragma once

class Sample
{
public:
    Sample();
    ~Sample();
    int value;
    int GetValue() const;
    int GetValue();
    void func() {};

private:
    int n;
};

Sample::Sample()
{
    n = 1;
}

Sample::~Sample()
{}

int Sample::GetValue()
{
    return n;
}

int Sample::GetValue() const
{
    return 2 * n;
    //value = 0; // 有问题，常量成员函数不可以修改成员变量
    //func(); // 常亮成员函数不可以调用非常量函数
}