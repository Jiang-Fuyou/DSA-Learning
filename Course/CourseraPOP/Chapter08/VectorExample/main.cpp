#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v(20);

    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    // 常量迭代器不可以修改指向的值
    vector<int>::const_iterator ii;
    for (ii = v.begin(); ii != v.end(); ii++) {
        cout << *ii << " ";
    }
    cout << endl;

    // 随机迭代器可以做+=2等跳跃操作
    for (ii = v.begin(); ii != v.end(); ii += 2) {
        cout << *ii << " ";
    }
    cout << endl;

    list<int> l;
    for (size_t i = 0; i < 10; i++) {
        l.push_back(i);
        l.push_front(i);
    }

    list<int>::const_iterator li;
    for (li = l.begin(); li != l.end(); li++) {
        cout << *li << " ";
    }
    cout << endl;

    int array[10] = { 10, 20, 30, 40 };
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    vector<int>::iterator p;
    p = find(vi.begin(), vi.end(), 3);
    if (p != vi.end()) {
        cout << *p << endl;
    }

    p = find(vi.begin(), vi.end(), 9);
    if (p == vi.end()) {
        cout << "Not found." << endl;
    }
    
    p = find(vi.begin() + 1, vi.end() - 2, 9);
    if (p != vi.end()) {
        cout << *p << endl;
    }

    int *pp = find(array, array + 4, 20);
    cout << *pp << endl;

    return 0;
}