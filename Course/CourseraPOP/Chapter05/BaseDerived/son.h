#pragma once

#include "father.h"

class Son : public Father
{
public:
    Son();
    ~Son();
    void AccessFather();
private:
    
};

Son::Son()
{}

Son::~Son()
{}

void Son::AccessFather()
{
    nPublic = 1;
    nProtected = 1;
    // nPrivated = 1; // Error!
    Son f;
    f.nProtected = 1; // ���ǵ�ǰ����Ļ����protected��ԱҲ�����Է���
    // ���Ǵ˴��������ͨ������
}