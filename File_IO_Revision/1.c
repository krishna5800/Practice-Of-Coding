#include<stdio.h>
#include<fcntl.h>        // IMP
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int fd = 0;

    fd = creat("LB.txt", 0777);

    printf("%d id fd of file\n", fd);

    return 0;
}