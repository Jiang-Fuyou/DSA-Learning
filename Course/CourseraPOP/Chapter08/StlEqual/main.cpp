#include <iostream>
#include <algorithm>
using namespace std;

class A
{
public:
    A();
    ~A();
    A(int n) : v(n) {};
    bool operator<(const A &a2) const
    {
        cout << v << " < " << a2.v << " ? " << endl;
        return false;
    }
    bool operator==(const A &a2) const
    {
        cout << v << " == " << a2.v << " ? " << endl;
        return v == a2.v;
    }
private:
    int v;
};

A::A()
{}

A::~A()
{}

int main()
{
    A a[] = { A(1), A(2), A(3), A(4), A(5) };
    cout << binary_search(a, a + 4, A(9)) << endl;
    return 0;
}