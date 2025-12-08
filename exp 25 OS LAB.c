#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main(){
    int fd=open("test.txt",O_RDWR|O_CREAT,0644);
    write(fd,"ABCDEF",6);
    lseek(fd,0,SEEK_SET);
    char buf[10]; int n=read(fd,buf,6); buf[n]='\0'; printf("File data: %s\n",buf);
    struct stat st; stat("test.txt",&st); printf("Size=%ld\n",st.st_size);
    DIR *d=opendir("."); struct dirent *de;
    while((de=readdir(d))) printf("%s\n",de->d_name);
    closedir(d); close(fd);
    return 0;
}

