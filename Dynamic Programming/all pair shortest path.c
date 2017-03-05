#include<stdio.h>

int min(int x, int y)
{
 if(x<y)
  return x;
  else return y;
}
void push (int s[],int *tos,int ele)
{
	(*tos)++;
	s[*tos]=ele;
}

void path(int u,int v,int d[][100],int c[][100],int f[][100]int s[],int *tos)
{
	int a,z;
	a=v;
	if(f[i][j]>998)
	{
		printf("no path present\n");
		return;
	}
	while(a!=-1)
	{
		z=a;
		a=d[u][a];
		if(c[a][z]==999)
		{
			path(a,z,d,c,s,tos);
		}
		if(a!=-1&&c[a][z]!=999)
		{
			push(s,tos,z);
		}		
	}
}


int main()
{ 
 int a[100][100], c[100][100],d[100][100],i,j,k,n,u,r,w,p,s[100],tos=-1;
 printf("Enter number of vertices\n");
 scanf("%d", &n); 
 printf("Enter A0\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d", &c[i][j]);
   a[i][j]=c[i][j];
  }
 }
 printf("Enter D0\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d", &d[i][j]);
  }
 }
 for(k=1;k<=n;k++)
 {
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    u=a[i][j];
    a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
    if(a[i][j]<u)
    {
    	d[i][j]=k;
	}    
   }
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d\t", a[i][j]);
  }
  printf("\n");
 }
 printf("\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d\t", d[i][j]);
  }
  printf("\n");
 }
 do
 {
 tos=-1;
 printf("Enter vertices to find path length\n");
 scanf("%d %d", &r, &w);
 path(r,w,d,c,a,s,&tos);
 push(s,&tos,r);
 for(i=tos;i>=0;i--)
 {
 	printf("%d ",s[i]);
 }
 printf("Enter 1 to continue\n");
 scanf("%d",&p);
 }while(p==1);
}
