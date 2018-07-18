#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    vector<int> v(5);
    cout << v.end() - v.begin() << endl;

    for (size_t i = 0; i < v.size(); i++) {
        v[i] = i;
    }

    v.at(4) = 100;

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int> v2(a, a + 5);
    v2.insert(v2.begin() + 2, 13);

    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    vector<vector<int> > v3(3);
    for (size_t i = 0; i < v3.size(); i++) {
        for (size_t j = 0; j < 4; j++) {
            v3[i].push_back(j);
        }
    }

    for (size_t i = 0; i < v3.size(); i++) {
        for (size_t j = 0; j < v3[i].size(); j++) {
            cout << v3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}