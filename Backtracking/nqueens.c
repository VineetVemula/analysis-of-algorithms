#include<stdio.h>
#include<math.h>

int x[100]={0},n;

void nextvalue(int k)
{
    int j;
    a: x[k]=(x[k]+1)%(n+1);
    if(x[k]==0)
        return;
    for(j=1;j<=k-1;j++)
        if((x[j]==x[k]) || (abs(x[j]-x[k])==abs(j-k)))
            goto a;
}

void display(int x[])
{
    int i;
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void printBoard(int x[])
{
    char board[100][100],i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            board[i][j]='-';
        }
    }
    for(i=1;i<=n;i++)
        board[i][x[i]]='Q';
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void nqueens(int k)
{
 int i;
 b: nextvalue(k);
 if(x[k]==0)
    return;
 if(k==n)
 {
    display(x);
    printBoard(x);
 }
 else nqueens(k+1);
 goto b;
}


int main()
{
    printf("N Queens Implementation\n");
    printf("\n");
    printf("Enter value of n\n");
    scanf("%d", &n);
    nqueens(1);
    return 0;
}
x------------------------------------------x
Output

N Queens Implementation

Enter value of n
4

2 4 1 3
- Q - -
- - - Q
Q - - -
- - Q -

3 1 4 2
- - Q -
Q - - -
- - - Q
- Q - -
