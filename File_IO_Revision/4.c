#include<stdio.h>
#include<fcntl.h>        // IMP
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int fd = 0;

    fd = open("LB.txt", O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File with fd %d opened successfully\n", fd);
        write(fd, "Jay Ganesh", 10);
        close(fd);
    }

    return 0;
}