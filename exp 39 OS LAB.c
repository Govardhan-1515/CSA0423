#include <stdio.h>
#include <stdlib.h>
int main(){
    int req[]={176,79,34,60,92,11,41,114},n=8,head=50,size=200;
    int seek=0;
    int i,j;
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) if(req[i]>req[j]){int t=req[i];req[i]=req[j];req[j]=t;}
    int idx=0; while(idx<n && req[idx]<head) idx++;
    for(i=idx;i<n;i++){seek+=abs(req[i]-head); head=req[i];}
    seek+=abs(size-1-head); head=0; seek+=size-1;
    for(i=0;i<idx;i++){seek+=abs(req[i]-head); head=req[i];}
    printf("Total seek=%d\n",seek);
    return 0;
}
