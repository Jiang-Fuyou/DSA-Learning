#include "pair.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    Pair<string, int> student("Tom", 19);
    cout << student.key << " " << student.value << endl;

    return 0;
}