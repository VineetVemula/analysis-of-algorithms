Quick Sort

#include<stdio.h>
#include<time.h>

void quicksort(int x[], int lb, int ub)
{
 int p;
 if(lb<ub)
 {
  p=partition(x,lb,ub);
  quicksort(x,lb,p-1);
  quicksort(x,p+1,ub);
 }
}

int partition(int x[], int lb,int ub)
{
 int val=x[lb], down=lb+1, up=ub,t;
 while(down<=up)
 {
  while(down<=up&&x[down]<=val)
   down++;
  while(x[up]>val)
   up--;
  if(down<up)
  {
   t=x[down],
   x[down]=x[up];
   x[up]=t;
  }
 }
 x[lb]=x[up];
 x[up]=val;
 return up;
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
 int m=0,i,n,a[50000],x,r;
 FILE *fp;
 clock_t start,end;
 double exectime;
 printf("Enter number of integers\n");
 scanf("%d", &n);
 fp=fopen("/home/user/Desktop/aoa-exp2/nos2.txt", "w");
 for(i=0;i<n;i++)
 {
  r=rand()%1000;
  x=r*i;
  fprintf(fp, "%d\n", x);
 }
 fclose(fp);
 fp=fopen("/home/user/Desktop/aoa-exp2/nos2.txt", "r");
 while(feof(fp)==0)
  fscanf(fp, "%d\n", &a[m++]);
 fclose(fp);
 start=clock();
 quicksort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Unsorted execution time = %f\n", exectime);
 start=clock();
 quicksort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Already sorted execution time = %f\n", exectime);
 revbubble(a,n-1);
 start=clock();
 quicksort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Reverse sorted execution time = %f\n", exectime);
}

Quick Sort Output

Enter number of integers
10000
Unsorted execution time = 0.002829
Already sorted execution time = 0.189032
Reverse sorted execution time = 0.219896

Enter number of integers
20000
Unsorted execution time = 0.005928
Already sorted execution time = 0.751972
Reverse sorted execution time = 0.880309

Enter number of integers
30000
Unsorted execution time = 0.009380
Already sorted execution time = 1.688647
Reverse sorted execution time = 1.977397

Enter number of integers
40000
Unsorted execution time = 0.012789
Already sorted execution time = 3.005904
Reverse sorted execution time = 3.517773
Enter number of integers
50000
Unsorted execution time = 0.016330
Already sorted execution time = 4.701007
Reverse sorted execution time = 5.494759
