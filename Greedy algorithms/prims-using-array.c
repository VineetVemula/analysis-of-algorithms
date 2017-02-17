#include<stdio.h>

#define inf 32766

int extract_min(int d[], int q[], int n)
{
    int i, minnode = 1,minimum = inf+1;
    for(i=1; i <= n; i++)
    {
        if(minimum > d[i] && q[i] == 1)
        {
            minimum = d[i];
            minnode = i;
        }
    }
    q[minnode] = 0;
    return minnode;
}

void display_edges_cost(int weight[][100], int pi[], int r, int v)
{
    int i, cost = 0;
    for(i=1; i <= v; i++){
        if(i != r){
            if(pi[i] == -1)
                pi[i] = r;
            printf("%d->%d\n", pi[i], i);
            cost=cost+weight[pi[i]][i];
        }

    }
    printf("Cost = %d\n", cost);
}

void prims(int w[][100], int v, int r)
{
    int d[100],pi[100],q[100];
    int i,c=v,cost=0,u;
    for(i=1;i<=100;i++)
    {
        d[i]=inf;
        pi[i]=-1;
    }
    d[r]=0;
    for(i=1;i<=v;i++)
    {
        q[i]=1;
    }
    while(c!=0)
    {
        u=extract_min(d,q,v);
        for(i=1;i<=v;i++)
        {
            if(q[i]==1 && w[u][i]!=inf)
            {
                if(w[u][i]<d[i])
                {
                    d[i]=w[u][i];
                    pi[i]=u;
                }
            }
        }
        c--;
    }
    display_edges_cost(w,pi,r,v);
}

void main()
{
    int w[100][100],v,i,j,r,weight;
    printf("Enter number of vertices\n");
    scanf("%d", &v);
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            w[i][j]=inf;
        }
    }
    printf("Enter weight matrix\n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            scanf("%d", &weight);
            if(weight!=0)
                w[i][j]=weight;
        }
    }
    printf("Enter starting vertex\n");
    scanf("%d", &r);
    prims(w,v,r);
}
