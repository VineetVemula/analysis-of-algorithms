#include<stdio.h>

int c[20][20]={0},d[20],n;


void remove1(int s[],int x[],int terms,int ele)
{
 int i,j=1;
 for (i=1; i<=terms; i++)
   if (s[i]!=ele)
	 x[j++]=s[i];
 printf("\n X = ");
 for (i=1; i<terms; i++)
   printf("%d ",x[i]);
 printf("\n");
}

int g(int node, int s[], int terms)
{
 int min=32000,i,next,temp,x[50];
 printf("\n S = ");
 for (i=1; i<=terms; i++)
    printf("%d ",s[i]);
 if(terms == 0)
    return (c[node][1]);
 for (i=1; i<=terms; i++)
 {
  next=s[i];
  remove1(s,x,terms,next);
  temp=c[node][next]+g(next,x,terms-1);
  if(temp<min)
  {
   min=temp;
   d[node]=next;
  }
 }
 return min;
}

void display(int p[],int c,int node)
{
	int i;
	printf("%d-",node);
	for(i=1;i<c;i++)
	{
		printf("%d-",p[i]);
	}
	printf("%d",node);
}
int main()
{
 FILE *fp;
 int i,j,e,v1,v2,wt,s[20],cost;

 printf("Enter no of nodes\n");
 scanf("%d",&n);
 printf("Enter no of edges\n");
 scanf("%d",&e);
 fp=fopen("graph.txt","r");
 printf("Enter %d edges\n",e);
 for (i=1; i<=e; i++)
 {
  fscanf(fp,"%d %d %d",&v1,&v2,&wt);
  c[v1][v2]=wt;
 }
 fclose(fp);
 for (i=1; i<=n-1; i++)
   s[i]=i+1;
 printf("\n Original S = ");
 for (i=1; i<=n-1; i++)
    printf("%d ",s[i]);
 printf("Matrix is \n");
 for (i=1; i<=n; i++)
 {
   for (j=1; j<=n; j++)
      printf("%d ",c[i][j]);
   printf("\n");
 }
 cost=g(1,s,n-1);
 display(d,n,1);
 printf("Cost = %d\n",cost);
}
