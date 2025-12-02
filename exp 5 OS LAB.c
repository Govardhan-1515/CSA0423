#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,j; scanf("%d",&n);
    int bt[n],pr[n],id[n];
    for(i=0;i<n;i++){scanf("%d %d",&bt[i],&pr[i]); id[i]=i+1;}
    for(i=0;i<n-1;i++){
        int max=i;
        for(j=i+1;j<n;j++) if(pr[j]>pr[max]) max=j;
        int t=bt[i]; bt[i]=bt[max]; bt[max]=t;
        t=pr[i]; pr[i]=pr[max]; pr[max]=t;
        t=id[i]; id[i]=id[max]; id[max]=t;
    }
    int cur=0; double aw=0,at=0;
    for(i=0;i<n;i++){
        printf("P%d BT=%d PR=%d WT=%d TAT=%d\n",id[i],bt[i],pr[i],cur,cur+bt[i]);
        aw+=cur; at+=cur+bt[i]; cur+=bt[i];
    }
    printf("Average WT=%.2f Average TAT=%.2f\n",aw/n,at/n);
    return 0;
}
