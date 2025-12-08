#include <stdio.h>
#include <stdlib.h>
int main(){
    int req[]={98,183,37,122,14,124,65,67},n=8,head=53;
    int seek=0;
    int i;
    for(i=0;i<n;i++){seek+=abs(req[i]-head); head=req[i];}
    printf("Total seek=%d\n",seek);
    return 0;
}
