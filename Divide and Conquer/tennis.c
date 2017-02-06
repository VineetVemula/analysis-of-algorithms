#include<stdio.h>

void copy(int x[], int n, int c)
{
 int i;
 for(i=0;i<=n;i++)
 { 
  x[i]=c++;
 }
}

void cyclic(int x[], int n)
{
 int temp,i;
 temp=x[0];
 for(i=0;i<n;i++)
 {
  x[i]=x[i+1];
 }
 x[n-1]=temp;
}

void acyclic(int x[], int n)
{
 int temp,i;
 temp=x[n-1];
 for(i=n-1;i>0;i--)
 {
  x[i]=x[i-1];
 }
 x[0]=temp;
}

void tennis(int x[][100], int lb, int ub)
{
 int i,j,k,m,a[100]={0},u=lb;
 if(lb==ub-1)
 {
  x[lb][0]=ub;
  x[ub][0]=lb;
  return;
 }
 m=(lb+ub)/2;
 k=m-lb;
 tennis(x,lb,m);
 tennis(x,m+1,ub);
 copy(a,m-lb,m+1);
 for(j=0;j<=(m-lb);j++)
 {
  for(i=0;i<=(m-lb);i++)
  {
   x[u++][k]=a[i];
  }
  cyclic(a,m+1-lb);
  u=lb;
  k++;
 }
 copy(a,m-lb,lb);
 k=m-lb;
 u=m+1;
 for(j=0;j<=(m-lb);j++)
 {
  for(i=0;i<=(m-lb);i++)
  {
   x[u++][k]=a[i];
  }
  acyclic(a,m+1-lb);
  u=m+1;
  k++;
 }
}

void main()
{
 int n,x[100][100]={0},i,j;
 printf("Enter number of players\n");
 scanf("%d", &n);
 tennis(x,0,n-1);
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-1;j++)
  {
   printf("%d ", x[i][j]+1);
  }
  printf("\n");
 }
}
