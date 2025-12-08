#include <stdio.h>
#include <string.h>
struct file{char fname[20];}files[5][10];
int count[5];
char dname[5][20];
int main(){
    int nd,i,j; scanf("%d",&nd);
    for(i=0;i<nd;i++){scanf("%s",dname[i]); count[i]=0;}
    int ch; char dn[20],fn[20];
    while(1){
        scanf("%d",&ch);
        if(ch==1){scanf("%s %s",dn,fn); for(i=0;i<nd;i++) if(strcmp(dn,dname[i])==0) strcpy(files[i][count[i]++].fname,fn);}
        else if(ch==2){scanf("%s",dn); for(i=0;i<nd;i++) if(strcmp(dn,dname[i])==0) for(j=0;j<count[i];j++) printf("%s/%s\n",dname[i],files[i][j].fname);}
        else break;
    }
    return 0;
}
