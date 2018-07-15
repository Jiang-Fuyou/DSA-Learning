/*******************************************************************************
  > File Name: env.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sat 14 Jul 2018 11:19:23 PM PDT
  > Description: getenv函数用以获取环境变量中的相关设置
 ******************************************************************************/

#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    char *server_name = getenv("SERVER_NAME");
    char *name = getenv("USER");

    if (!server_name) {
        // SERVER_NAME 环境变量未设置
        server_name = "server.yours.com";
    }

    cout << "Accessing server: " << server_name << endl;
    cout << "User name: " << name << endl;

    return 0;
}
