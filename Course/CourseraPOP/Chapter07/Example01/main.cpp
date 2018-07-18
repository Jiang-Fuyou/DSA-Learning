#include "student.h"

#include <string.h>

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Student s;

    /**************************************************************************/

    ofstream OutFile("student.dat", ios::out | ios::binary);

    while (cin >> s.szName >> s.nScore) {
        if (strcmp(s.szName, "exit") == 0) {
            break;
        }
        OutFile.write((char *)&s, sizeof(s));
    }

    OutFile.close();

    /**************************************************************************/

    ifstream inFile("student.dat", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error to open student.dat" << endl;
        return -1;
    }

    while (inFile.read((char *)&s, sizeof(s))) {
        int nReadBytes = inFile.gcount();
        cout << s.szName << " " << s.nScore << endl;
    }

    inFile.close();

    /**************************************************************************/

    fstream iofile("student.dat", ios::in | ios::out | ios::binary);

    if (!iofile) {
        cerr << "Error!" << endl;
        return -1;
    }
    
    iofile.seekp(2 * sizeof(s), ios::beg);
    iofile.write("Mike", strlen("MiKE") + 1);
    iofile.seekg(0, ios::beg);

    while (iofile.read((char *)&s, sizeof(s))) {
        cout << s.szName << " " << s.nScore << endl;
    }

    iofile.close();

    return 0;
}