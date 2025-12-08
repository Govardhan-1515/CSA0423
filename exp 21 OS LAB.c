#include <stdio.h>
int main(){
    int block[]={100,500,200,300,600};
    int process[]={212,417,112,426};
    int m=5,n=4,alloc[n];
	int i,j; 
    for(i=0;i<n;i++) alloc[i]=-1;
    for(i=0;i<n;i++){
        int worst=-1;
        for(j=0;j<m;j++) if(block[j]>=process[i]) if(worst==-1||block[j]>block[worst]) worst=j;
        if(worst!=-1){alloc[i]=worst; block[worst]-=process[i];}
    }
    for(i=0;i<n;i++){
        if(alloc[i]!=-1) printf("Process %d allocated to block %d\n",i,alloc[i]);
        else printf("Process %d not allocated\n",i);
    }
    return 0;
}
