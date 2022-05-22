#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char ch[8];
    long cho;
    int id = open("/dev/urandom",O_RDONLY);
    
    ssize_t check=read(id ,ch, sizeof(ch));
    cho = syscall(449,ch);
    printf("Random 8 bytes character :%s",ch);
    return 0;
}