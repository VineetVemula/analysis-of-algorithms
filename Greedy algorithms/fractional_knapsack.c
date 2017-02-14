#include<stdio.h>

void sort( int p[], int w[], int a[], int n)
{
    int i,j,t=0,u=0;
    float pw1,pw2;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            pw1=(float)((p[j]*1.0)/w[j]);
            pw2=(float)((p[j+1]*1.0)/w[j+1]);
            if(pw1<pw2)
            {
                u=a[j];
                a[j]=a[j+1];
                a[j+1]=u;
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
                t=w[j];
                w[j]=w[j+1];
                w[j+1]=t;
            }
        }
    }
}

int main()
{
    int p[100],w[100],i,j,n,k,itemno=0,a[100],s,m;
    float cp=0,cw=0,x[100]={0};
    printf("Enter number of items and sack capacity\n");
    scanf("%d %d", &n,&m);
    for(k=0;k<n;k++)
        a[k]=k;
    printf("Enter the profit and weight of each item\n");
    for(i=0;i<n;i++)
        scanf("%d %d", &p[i], &w[i]);
    printf("\nWeight Array:\n");
    for(i=0;i<n;i++)
        printf("%d ", w[i]);
    sort(p,w,a,n);
    printf("\nAfter Sorting\n");
    printf("P array\n");
    for(i=0;i<n;i++)
        printf("%d\t", p[i]);
    printf("\nW array\n");
    for(i=0;i<n;i++)
        printf("%d\t", w[i]);
    printf("\na array\n");
    for(i=0;i<n;i++)
        printf("%d\t", a[i]);
    for(i=0;i<n;i++)
    {
        if((cw+w[i])<m)
        {
            s=a[itemno];
            x[s]=1.0;
            cp=cp+p[i];
            cw=cw+w[i];
        }
        else
        {
            s=a[itemno];
            x[s]=(float)(((m-cw)*1.0)/w[i]);
            cp=cp+((p[i]*1.0)*x[s]);
            cw=m;
            break;
        }
        itemno++;
    }
    printf("\nProfit = %f, Weight = %f\n", cp,cw);
    for(i=0;i<n;i++)
        printf("%f\t", x[i]);
}
