#include "carray.h"

#include <iostream>
using namespace std;

int main()
{
    CArray a1, a2;
    a1.push_back(1);
    a1.push_back(2);
    for (int i = 0; i < a1.length(); i++) {
        cout << a1[i] << "\t";
    }
    cout << endl;

    return 0;
}