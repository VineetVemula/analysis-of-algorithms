#include<stdio.h>

int a[100][100],c[100][100],d[100][100];
int b[100];
void findingpath(int i,int v1,int v2,int v)
{
  b[i]=v2;
  while(i<v)
{
   i++;
  b[i]=d[v1-1][b[i-1]-1];
  if(a[b[i]-1][b[i-1]-1]!=1)
  findingpath(i-1,b[i],b[i-1],v);
   if(b[i]==v1)
    return ;
}
}
void main()
{
 int k,v,e,i,j,v1,v2,length,n,z,p;
 printf("Enter no. of vertices and edges \n");
 scanf("%d %d",&v,&e);

 for(i=0;i<v;i++)
  {
   for(j=0;j<v;j++)
   {
    c[i][j] = 999;
    c[i][i] = 0;
    a[i][j] = 999;
    a[i][i] = 0;
    d[i][i] = -1;

   }
  } /*initialize the arrays*/
 for(i=0;i<e;i++)
 {
  printf("enter edges and their length \n");
  scanf("%d %d %d",&v1,&v2,&length);
  c[v1-1][v2-1] = length;
  a[v1-1][v2-1] = 1;
  d[v1-1][v2-1] = v1;
 } /*adjacency matrix and length matrix done*/

for(k=0;k<v;k++)
  {
   for(i=0;i<v;i++)
   {
    for(j=0;j<v;j++)
    {
        if(c[i][j]>(c[i][k]+c[k][j]))
        {
         c[i][j] = c[i][k]+c[k][j];
         if(c[i][j] == 999 || c[i][j] == 0)
         d[i][j] = -1;
         else
         d[i][j]=k+1;

        }

    }
   }
  }
printf("Matrix A\n");
 for(i=0;i<v;i++)
  {
   for(j=0;j<v;j++)
   {
    printf("%d ",c[i][j]);
   }
   printf("\n");
  }
 printf("Matrix D\n");
 for(i=0;i<v;i++)
  {
   for(j=0;j<v;j++)
   {
    printf("%d ",d[i][j]);
   }
   printf("\n");
  }
  printf("enter edge whose path is to be found out\n");
  scanf("%d%d",&v1,&v2);
 i=0;
 findingpath(i,v1,v2,v);
 for(i=0;i<v;i++)
    if(b[i]==v1)
      break;
for(j=i;j>=0;j--)
{
    printf("%d ",b[j]);

}
}
