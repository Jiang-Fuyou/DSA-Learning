/*******************************************************************************
  > File Name: args.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sat 14 Jul 2018 04:50:51 AM PDT
  > Description:
 ******************************************************************************/

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Them program name is " << argv[0] << endl;

    if (argc > 1) {
        cout << "With" << argc -1 << " args as follows:" << endl;
        for (int i = 1; i < argc; i++) {
            cout << argv[i] << endl;
        }
    } else {
        cout << "With " << argc - 1 << " arguments." << endl;
    }

    return 0;
}
