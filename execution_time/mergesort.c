Merge Sort

#include<stdio.h>
#include<time.h>

void merge(int x[], int lb, int m, int ub)
{
 int temp[50000],i=lb,j=m+1,k=0;
 while(i<=m&&j<=ub)
  if(x[i]<x[j])
   temp[k++]=x[i++];
  else temp[k++]=x[j++];
  while(i<=m)
   temp[k++]=x[i++];
  while(j<=ub)
   temp[k++]=x[j++];
  k=0;
  for(i=lb;i<=ub;i++)
   x[i]=temp[k++];
}

void mergesort(int x[], int lb, int ub)
{
 int m;
 if(lb<ub)
 {
  m=(lb+ub)/2;
  mergesort(x,lb,m);
  mergesort(x,m+1,ub);
  merge(x,lb,m,ub);
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
 int m=0,i,n,a[50000],x,r;
 FILE *fp;
 clock_t start,end;
 double exectime;
 printf("Enter number of integers\n");
 scanf("%d", &n);
 fp=fopen("/home/user/Desktop/aoa-exp2/nos.txt", "w");
 for(i=0;i<n;i++)
 {
  r=rand()%1000;
  x=r*i;
  fprintf(fp, "%d\n", x);
 }
 fclose(fp);
 fp=fopen("/home/user/Desktop/aoa-exp2/nos.txt", "r");
 while(feof(fp)==0)
  fscanf(fp, "%d\n", &a[m++]);
 fclose(fp);
 start=clock();
 mergesort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Unsorted execution time = %f\n", exectime);
 start=clock();
 mergesort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Already sorted execution time = %f\n", exectime);
 revbubble(a,n-1);
 start=clock();
 mergesort(a,0,n-1);
 end=clock();
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Reverse sorted execution time = %f\n", exectime);
}

Merge Sort Output

Enter number of integers
10000
Unsorted execution time = 0.003730
Already sorted execution time = 0.002305
Reverse sorted execution time = 0.002398

Enter number of integers
20000
Unsorted execution time = 0.007475
Already sorted execution time = 0.005186
Reverse sorted execution time = 0.005017

Enter number of integers
30000
Unsorted execution time = 0.011733
Already sorted execution time = 0.007698
Reverse sorted execution time = 0.007790

Enter number of integers
40000
Unsorted execution time = 0.016068
Already sorted execution time = 0.10088
Reverse sorted execution time = 0.10125

Enter number of integers
50000
Unsorted execution time = 0.019450
Already sorted execution time = 0.013004
Reverse sorted execution time = 0.012817
