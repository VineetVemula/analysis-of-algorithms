Selection Sort

#include<stdio.h>
#include<time.h>

void selectionsort(int x[], int n)
{
    int i,j,min,pos;
    for(i=0;i<n-1;i++)
    {
        min=x[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(x[j]<min)
            {
                min=x[j];
                pos=j;
            }
        }
        x[pos]=x[i];
        x[i]=min;
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
    selectionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Unsorted Execution time is = %f\n", exectime);
    start=clock();
    selectionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Best Case is = %f\n", exectime);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/best.txt", "w");
    for(i=0;i<m;i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
    revbubble(a,m);
    start=clock();
    selectionsort(a,m);
    end=clock();
    exectime=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Worst Case is = %f\n", exectime);
    fp=fopen("/home/pi/Desktop/Programs/AOA1/worst.txt", "w");
    for(i=0;i<m;i++)
        fprintf(fp, "%d\n", a[i]);
    fclose(fp);
}


Selection Sort Output

Enter number of integers
10000
Unsorted Execution time is = 0.257900
Best Case is = 0.256241
Worst Case is = 0.331472

Enter number of integers
20000
Unsorted Execution time is = 1.025501
Best Case is = 1.021868
Worst Case is = 1.321472

Enter number of integers
30000
Unsorted Execution time is = 2.304120
Best Case is = 2.303512
Worst Case is = 2.962133

Enter number of integers
40000
Unsorted Execution time is = 4.096357
Best Case is = 4.091735
Worst Case is = 5.280000

Enter number of integers
50000
Unsorted Execution time is = 6.396057
Best Case is = 6.382537
Worst Case is = 8.246575
