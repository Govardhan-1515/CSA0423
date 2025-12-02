#include <stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int bt[n],id[n];
    for(i=0;i<n;i++){scanf("%d",&bt[i]); id[i]=i+1;}
    for(i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++) if(bt[j]<bt[min]) min=j;
        int t=bt[i]; bt[i]=bt[min]; bt[min]=t;
        t=id[i]; id[i]=id[min]; id[min]=t;
    }
    int wt=0,cur=0;
    double aw=0,at=0;
    for(i=0;i<n;i++){
        printf("P%d BT=%d WT=%d TAT=%d\n",id[i],bt[i],cur,cur+bt[i]);
        aw+=cur; at+=cur+bt[i];
        cur+=bt[i];
    }
    printf("Average WT=%.2f Average TAT=%.2f\n",aw/n,at/n);
    return 0;
}
