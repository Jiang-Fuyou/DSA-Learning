#pragma once

#include <iostream> 
using namespace std;

class Rectangle
{
public:
    // 需要写一个复制构造函数，否则复制对象的时候会缺失总体信息
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
