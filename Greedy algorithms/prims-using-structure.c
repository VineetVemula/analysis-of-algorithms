#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int ver;
    int wt;
    struct node* next;
    
}node;

typedef struct vertex
{
    int data;
    struct node* head;
    struct vertex* next;
}vertex;

vertex *n=NULL;

vertex* search(vertex* h,int u)
{
    vertex *f;
    f=h;
    while(f!=NULL)
    {
        if(f->data==u)
        {
            return f;
        }
        f=f->next;
    }
    return NULL;
}
void makegraph(int v,int e)
{
    int i,v1,v2,w;
    node *p,*s;
    vertex *l,*m,*z;
    m=NULL;
    for(i=0;i<v;i++)
    {
        l=(vertex *)malloc(sizeof(vertex));
        p=NULL;
        if(i==0)
        {
            m=l;
            n=l;
        }
        l->data=i;
        l->head=p;
        if(i>0)
        {
            m->next=l;
            m=m->next;
        }
        l=NULL;
    }
    m->next=NULL;
    printf("Enter vertex 1,vertex 2 and weght\n");
    for(i=0;i<e;i++)
    {
        scanf("%d %d %d",&v1,&v2,&w);
        z=search(n,v1);
        s=(node*)malloc(sizeof(node));
        s->ver=v2;
        s->wt=w;
        s->next=z->head;
        z->head=s;
        s=NULL;
        z=search(n,v2);
        s=(node*)malloc(sizeof(node));
        s->ver=v1;
        s->wt=w;
        s->next=z->head;
        z->head=s;
        s=NULL;
    }
}
int min(int a[],int n,int Q[])
{
    int min,pos,i,j;
    for(j=0;j<n;j++)
    {
        if(Q[j]==1)
        {
            goto a;
        }
    }
a:;
    min=a[j];
    pos=j;
    for(i=j;i<n;i++)
    {
        if(min>a[i]&&Q[i]==1)
        { 
            min=a[i];
            pos=i;
        }
    }
    return pos;
}
void prims(int N,int R)
{
    int d[100],p[100],q=N,Q[100],u,cost=0,cv,i;
    vertex* z;
    node* k,*e;
    for(i=0;i<100;i++)
    {
    	d[i]=999;
    	Q[i]=1;
    	p[i]=-1;
    }
    d[R]=0;
    e=NULL;
    while(q!=0)
    {
        u=min(d,N,Q);
        q--;
        z=search(n,u);
        if(z==NULL)
        {
        		goto b;		
        }
        Q[u]=-1;
        if(p[u]!=-1)
        {
            cv=p[u];
            e=(z->head);
            while(e!=NULL)
            {
                if(e->ver==cv)
                {
                    cost = cost + e->wt;
                    goto a;
                }
                e=e->next;
            }
        }
    a:;
        for(k=z->head;k!=NULL;k=k->next)
        {
            if(Q[k->ver]==1)
            {
                if(k->wt<d[k->ver])
                {
                    d[k->ver]=k->wt;
                    p[k->ver]=u;
                }
            }
        }
    }
    b:;
    for(i=0;i<N;i++)
    {
    	if(p[i]!=-1)
    	{
        printf("%d %d\n",i,p[i]);
    	}
    }
    printf("%d",cost);
    
}

int main()
{
    int V,E,r;
    printf("Enter no of vertices and edges and source\n");
    scanf("%d %d %d",&V,&E,&r);
    makegraph(V,E);
    prims(V,r);
}
