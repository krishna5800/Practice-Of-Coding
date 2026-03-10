#include<iostream>
#include<fcntl.h>

using namespace std;

int main()
{
    int fd = 0;

    fd = creat("Demo.txt", 0777);

    cout << "File Descriptor is : " << fd << "\n";

    return 0;
}