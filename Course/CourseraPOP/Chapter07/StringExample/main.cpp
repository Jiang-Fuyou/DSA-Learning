#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1("Hello");
    string s2(8, 'x');
    string s3 = "World.";
    string s4;
    s4 = 's';
    // string s4 = 's' // error!

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    string s5;
    s5.assign(s1);
    string s6;
    s6.assign(s1, 1, 3);
    cout << s5 << endl;
    cout << s6 << endl;
    s6[1] = '0';
    cout << s6 << endl;

    s6 += s1;
    cout << s6 << endl;

    s6.append(s2);
    cout << s6 << endl;
    
    s6.append(s3, 1, 3);
    cout << s6 << endl;

    string s7 = s6.substr(4, 5);
    cout << s7 << endl;
    
    int pos = s7.find("x");
    int rpos = s7.rfind("x");
    cout << pos << endl;
    cout << rpos << endl;

    return 0;
}