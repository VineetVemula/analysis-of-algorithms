Insertion Sort


#include<stdio.h>
#include<time.h>

void insertionsort(int x[], int n)
{
 int i,j,val;
 for(i=0;i<n-1;i++)
 {
  val=x[i+1];
  for(j=i;j>=0;j--)
  {
   if(x[j]>val)
    x[j+1]=x[j];
   else break;
  }
  x[j+1]=val;
 }
}

void revbubble(int x[], int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(x[j]<x[j+1])
            {
                temp=x[j];
                x[j]=x[j+1];
                x[j+1]=temp;
            }
        }
    }
}

void main()
{
    int x,i,a[50000],n=0,m;
    long int r;
    FILE *fp;
    clock_t start,end;
    double exectime;
    printf("Enter number of integers\n");
    scanf("%d", &m);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/nos5.txt", "w");
    for(i=0;i<m;i++)
    {
        r = rand()%1000;
        x=r*i;
        fprintf(fp, "%d\n", x);
    }
    fclose(fp);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/nos5.txt", "r");
    while(feof(fp)==0)
        fscanf(fp, "%d", &a[n++]);
    fclose(fp);
    start=clock();
    insertionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Unsorted Execution time is = %f\n", exectime);
    start=clock();
    insertionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Best Case is = %f\n", exectime);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/best.txt", "w");
    for(i=0;i<m;i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
    revbubble(a,m);
    start=clock();
    insertionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Worst Case is = %f\n", exectime);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/worst.txt", "w");
    for(i=0;i<m;i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
}

Insertion Sort Output

Enter number of integers
10000
Unsorted Execution time is = 0.33087
Best Case is = 0.0002975
Worst Case is = 0.431945

Enter number of integers
20000
Unsorted Execution time is = 1.21642
Best Case is = 0.0005864
Worst Case is = 1.689617

Enter number of integers
30000
Unsorted Execution time is = 3.10043
Best Case is = 0.0008765
Worst Case is = 3.787734

Enter number of integers
40000
Unsorted Execution time is = 6.09041
Best Case is = 0.001165
Worst Case is = 6.717046

Enter number of integers
50000
Unsorted Execution time is = 10.00180
Best Case is = 0.001440
Worst Case is = 10.557037
