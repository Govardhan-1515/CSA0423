#include <stdio.h>
struct emp{int id; char name[20]; float sal;};
int main(){
    FILE *f=fopen("emp.dat","wb+");
    struct emp e1={1,"Ram",5000},e2={2,"Sam",6000};
    fwrite(&e1,sizeof(e1),1,f);
    fwrite(&e2,sizeof(e2),1,f);
    fseek(f,sizeof(e1),SEEK_SET);
    struct emp e; fread(&e,sizeof(e),1,f);
    printf("%d %s %.2f\n",e.id,e.name,e.sal);
    fclose(f);
    return 0;
}
