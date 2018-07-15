/*******************************************************************************
  > File Name: stdout_stderr.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sun 15 Jul 2018 04:18:29 AM PDT
  > Description:
 ******************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int n;

    n = 0;
    while (1) {
        fprintf(stderr, ".\n");
        sleep(1);
        n++;
        if (n == 20) {
            break;
        }
    }

    printf("\n");

    n = 0;
    while (1) {
        fprintf(stdout, ".\n");
        sleep(1);
        n++;
        if (n == 20) {
            break;
        }
    }

    return 0;
}
