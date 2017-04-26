#include<stdio.h>
int a[30][30];
void display(int n){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<n;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }
}
void acyclic(int m,int ub,int k){
    int i,temp;
    temp=a[ub][k-1];
    for(i=ub-1;i>=m;i--)
        a[i+1][k]=a[i][k-1];
    a[m][k]=temp;
}
void cyclic(int lb,int m,int k){
    int i,temp;
    temp=a[lb][k-1];
    for(i=lb;i<m;i++)
        a[i][k]=a[i+1][k-1];
    a[m][k]=temp;
}
void swap(int lb,int ub){
    int c,i,j,k,m=(lb+ub)/2;
    c=(ub-lb)/2+1;
    j=m+1;
    for(i=lb;i<=m;i++)
        a[j++][c]=a[i][0];
    j=lb;
    for(i=m+1;i<=ub;i++)
        a[j++][c]=a[i][0];
    k=(ub-lb)/2;
    for(i=1;i<=k;i++)
    {
    cyclic(lb,m,c+1);
    acyclic(m+1,ub,c+1);
    c++;
}

}
void tennis(int lb, int ub)
{
    int m;
    if(lb==ub-1){
        a[lb][1]=ub;
        a[ub][1]=lb;
        return;
    }
    m=(lb+ub)/2;
    tennis(lb,m);
    tennis(m+1,ub);
    swap(lb,ub);
    return;
}
void main(){
    int n,i;
    printf("Enter the number of teams\n");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        a[i][0]=i;
    for(i=0;i<n;i++)
        a[0][i]=i;
    tennis(1,n);
    display(n);
}
