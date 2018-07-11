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
    //value = 0; // �����⣬������Ա�����������޸ĳ�Ա����
    //func(); // ������Ա���������Ե��÷ǳ�������
}