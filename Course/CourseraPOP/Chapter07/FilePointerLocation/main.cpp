#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string s1 = "- Nice meet you.";
    string s2 = "- Nice to meet you, too.";

    // ofstream fout("nice.out", ios::app);
    ofstream fout("nice.out", ios::out);
    fout << s1 << endl;

    long location = fout.tellp();
    cout << "Tellp(): " << fout.tellp() << endl;
    
    location = 6L;
    fout.seekp(location);
    cout << "Tellp(): " << fout.tellp() << endl;

    // ��ʱ���Ǹ���д��
    fout << "to ";
    cout << "Tellp(): " << fout.tellp() << endl;

    // ��ͷ����location
    fout.seekp(location, ios::beg);
    // �ӵ�ǰλ����location
    fout.seekp(location, ios::cur);
    // ��β����location
    fout.seekp(location, ios::end);

    fout.close();


    ifstream fin("a1.in", ios::in);
    long location2 = fin.tellg();
    location2 = 10L;
    fin.seekg(location);
    fin.seekg(location, ios::beg);
    fin.seekg(location, ios::cur);
    fin.seekg(location, ios::end);
    fin.close();


    return 0;
}