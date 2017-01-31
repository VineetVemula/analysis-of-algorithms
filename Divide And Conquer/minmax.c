#include<stdio.h>

int max(int x, int y)
{
 if(x>y)
  return x;
 else
  return y;
}

int min(int x, int y)
{
 if(x<y)
  return x;
 else
  return y;
}

void minmax(int x[], int i, int j, int *fmin, int *fmax)
{
 int m,gmin,gmax,hmin,hmax;
 if(i==j){
  *fmin=x[i];
  *fmax=x[i];
  return;
 }
 if(i==(j-1))
 {
  *fmax=max(x[i],x[i+1]);
  *fmin=min(x[i],x[i+1]);
  return;
  
 }
 m=(i+j)/2;
 minmax(x,i,m,&gmin,&gmax);
 minmax(x,m+1,j,&hmin,&hmax);
 *fmax=max(gmax,hmax);
 *fmin=min(gmin,hmin);
 return;
}

void main()
{
 int fmin,fmax,a[100],n,i;
 printf("Enter number of elements\n");
 scanf("%d", &n);
 printf("Enter elements\n");
 for(i=0;i<n;i++)
  scanf("%d", &a[i]);
 minmax(a,0,n-1,&fmin,&fmax);
 printf("Max = %d\nMin = %d\n", fmax,fmin);
}
