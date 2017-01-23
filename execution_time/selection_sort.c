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
 fp=fopen("/home/user/Desktop/aoa-exp1/nos2.txt", "w");
 for(i=0;i<m;i++)
 {
  r=rand()%1000;
  x=r*i;
  fprintf(fp, "%d\n", x);
 }
 fclose(fp);
 fp=fopen("/home/user/Desktop/aoa-exp1/bestworst.txt", "r");
 while(feof(fp)==0)
  fscanf(fp, "%d", &a[n++]);
 start=clock();
 selectionsort(a,m);
 end=clock();
 fclose(fp);
 fp=fopen("/home/user/Desktop/aoa-exp1/bestworst.txt", "w");
 for(i=0;i<m;i++)
  fprintf(fp, "%d\n", a[i]);
 fclose(fp);
 exectime=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Execution time is = %f ", exectime);
}
