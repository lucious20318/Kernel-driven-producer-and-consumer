#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char ch_[8];
    long cho;
    
    cho = syscall(450,ch_);
    printf("Random 8 bytes character :%s",ch_);
    return 0;
}