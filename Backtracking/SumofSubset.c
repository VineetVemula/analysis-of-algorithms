#include<stdio.h>

int w[100],r=0,n,x[100],M;

void display(int x[])
{
 int i;
 for(i=1;i<=n;i++)
  printf("%d ", x[i]);
 printf("\n");
}


void sumofsub(int s, int k, int r)
{
 x[k]=1;
 if(s+w[k]==M)
  display(x);
 else if(s+w[k]+w[k+1]<=M)
  sumofsub(s+w[k],k+1,r-w[k]);
 if(s+r-w[k]>=M && s+w[k+1]<=M)
 {
  x[k]=0;
  sumofsub(s,k+1,r-w[k]);
 }
}

void main()
{
 int i;
 printf("Enter number of items\n");
 scanf("%d", &n);
 printf("Enter required sum\n");
 scanf("%d", &M);
 printf("Enter weights\n");
 for(i=1;i<=n;i++)
  scanf("%d", &w[i]);
 for(i=1;i<=n;i++)
  r=r+w[i];
 sumofsub(0,1,r);
}
