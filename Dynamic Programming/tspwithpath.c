#include<stdio.h>
#include<stdlib.h>
int c[20][20]={0},d[20],n;
typedef struct nodeq
{
	int da[20];
}nodeq;
typedef struct node
{
	struct node * left;
	struct node * right;
	struct nodeq* leftq;
	struct nodeq* rightq;
}node;


node* root=NULL;
nodeq* rootq=NULL;

void cbtree(node* r,int l,int n1)
{
	node* p,*q;
	nodeq* z,*s;
	if(n1!=l+1)
	{
		p=(node*)malloc(sizeof(node));
		q=(node*)malloc(sizeof(node));
		r->left=p;
		r->right=q;
		p=NULL;
		q=NULL;
		free(p);
		free(q);
		cbtree(r->left,l+1,n1);
		cbtree(r->right,l+1,n1);
	}
	if(n1==l+1)
	{
		z=(nodeq*)malloc(sizeof(nodeq));
		s=(nodeq*)malloc(sizeof(nodeq));
		r->leftq=z;
		r->rightq=s;
		z=NULL;
		s=NULL;
	}
}
int search(int x[],int n2,int n3)
{
	int w;
	for(w=1;w<=n3;w++)
	{
		if(x[w]==n2)
			return 1;
	}
	return 0;
}
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

int g(int nodeo, int s[], int terms)
{
 int min=32000,i,next,temp,x[50],m;
 node* root1;
 printf("\n S = ");
 for (i=1; i<=terms; i++)
    printf("%d ",s[i]);
 if(terms == 0)
    return (c[nodeo][1]);
 for (i=1; i<=terms; i++)
 {
  next=s[i];
  remove1(s,x,terms,next);
  temp=c[nodeo][next]+g(next,x,terms-1);
  if(temp<min)
  {
   min=temp;
   root1=root;
   for(m=1;m<n;m++)
   {
   	if(search(s,m,n)==1)
   	{
   		root1=root1->right;
   	}
   	else
   	{
   		root1=root1->left;
   	}
   }
   if(search(s,n,n)==1)
   {
   		rootq=root1->rightq;
   }
   else
   {
   		rootq=root1->leftq;
   }
   rootq->da[nodeo]=next;
  }
 }
 return min;
}

void path(int nodee,int s[],int n)
{
	int i,nxt,j=1,u;
	node * root2;
	nodeq * root3;
	root2=root;
	for(i=1;i<=n;i++)
    {
        if(s[i]!=0)
            goto a;
        else j++;
    }
    if(j>=n)
        return;
	a:for(i=1;i<n;i++)
	{
		if(s[i]==i)
		{
			root2=root2->right;
		}
		else root2=root2->left;
	}
	if(s[n]==n)
	{
		root3=root2->rightq;
	}
	else root3= root2->leftq;
	nxt=root3->da[nodee];
	s[nxt]=0;
	printf("%d-",nxt);
	path(nxt,s,n);
}
int main()
{
 FILE *fp;
 int i,j,e,v1,v2,wt,s[20],cost,v[20];

 printf("Enter no of nodes\n");
 scanf("%d",&n);
 printf("Enter no of edges\n");
 scanf("%d",&e);
 fp=fopen("graph.txt","r");
 printf("Enter %d edges\n",e);
 for (i=1; i<=e; i++)
 {
  fscanf(fp,"%d %d %d",&v1,&v2,&wt);
  //scanf("%d %d %d",&v1,&v2,&wt);
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
 root=(node*)malloc(sizeof(node));
 rootq=(nodeq*)malloc(sizeof(nodeq));
 cbtree(root,1,n+1);
 cost=g(1,s,n-1);
 printf("Cost = %d\n",cost);
 for(i=2;i<=n;i++)
 {
 	v[i]=i;
 }
 v[1]=0;
 printf("1-");
 path(1,v,n);
 printf("1");
}

OUTPUT

Enter no of nodes
4
Enter no of edges
12
Enter 12 edges

 Original S = 2 3 4 Matrix is 
0 10 15 20 
10 0 35 25 
15 35 0 30 
20 25 30 0 

 S = 2 3 4 
 X = 3 4 

 S = 3 4 
 X = 4 

 S = 4 
 X = 

 S = 
 X = 3 

 S = 3 
 X = 

 S = 
 X = 2 4 

 S = 2 4 
 X = 4 

 S = 4 
 X = 

 S = 
 X = 2 

 S = 2 
 X = 

 S = 
 X = 2 3 

 S = 2 3 
 X = 3 

 S = 3 
 X = 

 S = 
 X = 2 

 S = 2 
 X = 

 S = Cost = 80
1-2-4-3-1

GRAPH
1 2 10
1 3 15
1 4 20
2 1 10
2 3 35
2 4 25
3 1 15
3 2 35
3 4 30
4 1 20
4 2 25
4 3 30
