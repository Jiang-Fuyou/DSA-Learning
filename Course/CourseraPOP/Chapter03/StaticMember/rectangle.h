#pragma once

#include <iostream> 
using namespace std;

class Rectangle
{
public:
    // ��Ҫдһ�����ƹ��캯���������ƶ����ʱ���ȱʧ������Ϣ
    Rectangle(Rectangle &r)
    {
        w = r.w;
        h = r.h;
        nTotalNumber++;
        nTotalArea += w*h;
    }
    Rectangle(int w_, int h_)
    {
        w = w_;
        h = h_;
        nTotalNumber++;
        nTotalArea += w*h;
    }
    ~Rectangle() 
    {
        nTotalNumber--;
        nTotalArea -= w*h;
    }
    static void PrintTotal();

private:
    int w, h;
    static int nTotalArea;
    static int nTotalNumber;
};

void Rectangle::PrintTotal()
{
    cout << nTotalNumber << ", " << nTotalArea << endl;
}
