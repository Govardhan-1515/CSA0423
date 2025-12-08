#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int fd=open("test.txt",O_CREAT|O_RDWR,0644);
    write(fd,"Hello\n",6);
    lseek(fd,0,SEEK_SET);
    char buf[20]; int n=read(fd,buf,20); buf[n]='\0';
    printf("%s",buf);
    close(fd);
    return 0;
}
