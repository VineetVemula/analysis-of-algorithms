#include<stdio.h>
#include<math.h>

int adj[100][100], x[100],m,n;

void nextvalue(int k)
{
 int j;
 a: x[k]=(x[k]+1)%(m+1);
 if(x[k]==0)
  return;
 for(j=1;j<=k-1;j++)
 {
  if(adj[j][k]==1 && x[j]==x[k])
   goto a;
 }
}

void display(int x[])
{
 int i,j;
 for(i=1;i<=n;i++)
 {
  printf("%d ", x[i]);
 }
 printf("\n");
}

void color_graph(int k)
{
 b: nextvalue(k);
 if(x[k]==0)
  return;
 if(k==n)
  display(x);
 else color_graph(k+1);
 goto b;
}

void main()
{
 int i,j;
 printf("Enter number of nodes\n");
 scanf("%d", &n);
 printf("Enter number of colors\n");
 scanf("%d", &m);
 printf("Enter adjacency matrix\n");
 for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
      scanf("%d", &adj[i][j]);
     printf("\n");
     printf("Solutions are: \n");
 color_graph(1);
}
