#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f=fopen("file.txt","w"); fprintf(f,"Hello File\n"); fclose(f);
    f=fopen("file.txt","r"); char c; while((c=fgetc(f))!=EOF) putchar(c); fclose(f);
    remove("file.txt");
    return 0;
}
