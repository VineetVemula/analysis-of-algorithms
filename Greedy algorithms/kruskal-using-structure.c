#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct vertex
{
	int v1;
	int v2;
	int wt;
}vertex;
typedef struct edge
{
	struct vertex prop;
	struct edge* next;
}edge;

void sort(edge* s)
{
	edge *i,*j;
	vertex t;
	for(i=s;i->next!=NULL;i=i->next)
	{
		for(j=s;j->next!=NULL;j=j->next)
		{
			if(j->prop.wt>j->next->prop.wt)
			{
				t=j->prop;
				j->prop=j->next->prop;
				j->next->prop=t;
				
			}
		}
	}
}
int search(node* h,int r,int n)
{
	node*p;
	int y;
	p=h;
	for(y=0;y<=n;y++)
	{
		if(p->data==r)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void kruskal(int n,int g)
{
	int i,j,u,v,w,cost=0,f;
	edge* e,*fe,*se,*k;
	node *a[100],*p,*q,*s;
	for(i=0;i<n;i++)
	{
		p = (node*)malloc(sizeof(node));
		p->data=i;
		p->next=p;
		a[i]=p;
		p=NULL;
	}
	printf("Enter vertex 1, vertex 2 and weight\n");
	for(j=0;j<g;j++)
	{
		e=(edge*)malloc(sizeof(edge));
		scanf("%d %d %d",&(e->prop.v1),&(e->prop.v2),&(e->prop.wt));
		if(j==0)
		{
			fe=e;
			se=fe;
		}
		if(j>0)
		{
			fe->next=e;
			fe=fe->next;
		}
		e=NULL;
	}
	fe->next=NULL;
	sort(se);
	for(k=se;k!=NULL;k=k->next)
	{
		u=k->prop.v1;
		v=k->prop.v2;
		w=k->prop.wt;
		f=search(a[u],v,n);
		if(f==0)
		{
			q=a[v];
			s=q;
			while(q->next!=s)
			{
				q=q->next;
			}
			q->next=a[u]->next;
			a[u]->next=s;
			q=NULL;
			s=NULL;
			cost =cost +w;
			printf("%d %d %d\n",u,v,w);
		}
	}
printf("the total cost is %d\n",cost);
}
int main()
{
   int o,b;
   printf("Enter no of vertices and edges\n");
   scanf("%d %d",&o,&b);
   kruskal(o,b);
}
