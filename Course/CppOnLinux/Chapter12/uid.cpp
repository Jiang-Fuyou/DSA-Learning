/*******************************************************************************
  > File Name: uid.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sun 15 Jul 2018 04:11:13 AM PDT
  > Description:
 ******************************************************************************/

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    uid_t uid = getuid();
    uid_t euid = geteuid();

    printf("uid: %d; euid: %d\n", uid, euid);

    return 0;
}
