#include <iostream>
using namespace std;

class CMyAverage
{
public:
    CMyAverage();
    ~CMyAverage();
    double operator()(int a1, int a2, int a3)
    {
        return (double)(a1 + a2 + a3) / 3.0;
    }
private:

};

CMyAverage::CMyAverage()
{}

CMyAverage::~CMyAverage()
{}

int main()
{
    CMyAverage average;
    cout << average(1, 2, 3) << endl;
}