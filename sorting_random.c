#include<stdio.h>

void main()
{
 int x, y,i,j,r,a[100],temp=0,n,m=0;
 FILE *fp;
 printf("Enter number of integers in file");
 scanf("%d",&n);
 fp=fopen("/home/user/Desktop/files/numbers2.txt", "w");
 for(i=0;i<n;i++)
 {
  r=rand()%100;
  x=r*i;
  fprintf(fp, "%d\n", x);
 }
 fclose(fp);
 fp=fopen("/home/user/Desktop/files/numbers2.txt","r");
 while(feof(fp)==0)
 {
  fscanf(fp, "%d", &a[m++]);
 }
 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 fclose(fp);
 fp=fopen("/home/user/Desktop/files/numbers2.txt", "w");
 for(i=0;i<n;i++)
 {
  fprintf(fp, "%d ", a[i]);
 }
}
