/*******************************************************************************
  > File Name: mktmp.cpp
  > Author: Jiang Yong
  > Mail: chiangyung@aliyun.com
  > Created Time: Sun 15 Jul 2018 04:39:54 AM PDT
  > Description:
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int WriteToTempFile(char *buffer, size_t length);
char *ReadFromTempFile(int fd, size_t *length);

int main(int argc, char *argv[])
{
    char s[] = "Temp: closed.";
    size_t length = sizeof(s) / sizeof(s[0]);

    int fd = WriteToTempFile(s, length);

    sleep(10);

    ReadFromTempFile(fd, &length);

    return 0;
}


// fd是文件描述符
int WriteToTempFile(char *buffer, size_t length)
{
    char temp_filename[] = "temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);

    sleep(10);

    // unlink之后，tmp文件就找不到了
    unlink(temp_filename);
    write(fd, &length, sizeof(length));
    write(fd, buffer, length);

    return fd;
}

char *ReadFromTempFile(int fd, size_t *length)
{
    lseek(fd, 0, SEEK_SET);
    read(fd, length, sizeof(*length));
    char *buffer = new char[*length];
    read(fd, buffer, *length);

    fprintf(stdout, "length: %d\n", *length);
    fprintf(stdout, "buffer: %s\n", buffer);

    close(fd);

    return buffer;
}
