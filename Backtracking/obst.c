#include<stdio.h>

#define MAX 99999

int w[10][10], c[10][10], r[10][10];

void obst(int p[], int q[], int n)
{
    int kpos = 1,mini, i=0, j = 1, ct = 1,k;
    for(i=0; i <= n; i++){
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }
    for(i=0;i<=n ;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i < j){
                w[i][j]=p[j]+q[j]+w[i][j-1];
            }
        }
    }
    while(ct <= n){
        int ctx = 1;
        i=0;
        j=i+ct ;
        while(ctx <= n){
            mini = MAX;

            for(k=i+1; k <= j; k++){
                int t =  c[i][k-1] + c[k][j];
                if(t < mini){
                    kpos = k;
                    mini = t;

                }
            }

            if(j <= n){
                c[i][j] = w[i][j] + mini;
                r[i][j] = kpos;
            }
            i++;
            j = i +  ct;
            ctx++;

        }
        ct++;
    }
}

int main()
{
    int n,p[10],q[10];
    int i, j, k;
    printf("Enter n\n");
    scanf("%d",&n);

    p[0]=-1;

    printf("Enter p array\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter q array\n");
    for(i=0;i<=n;i++)
        scanf("%d",&q[i]);
    obst(p,q,n);
   for(i=0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if(w[j][j+i])
                printf("(%d %d %d) ", w[j][j+i], c[j][j+i],r[j][j+i]);
        }
        printf("\n");
    }
}

x--------------------------------------------------------------------------------------------------------------x
Output

Enter n
4
Enter p array
3 3 1 1
Enter q array
2 3 1 1 1
(2 0 0) (3 0 0) (1 0 0) (1 0 0) (1 0 0)
(8 8 1) (7 7 2) (3 3 3) (3 3 4)
(12 19 1) (9 12 2) (5 8 3)
(14 25 2) (11 19 2)
(16 32 2)
