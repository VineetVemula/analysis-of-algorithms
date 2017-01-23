#include<stdio.h>

void main()
{
 int x, y,i,j,a[100],temp,n=0,m=0;
 FILE *fp;
 fp=fopen("/home/user/Desktop/files/numbers.txt", "r");
 while(feof(fp)==0)
 {
  fscanf(fp, "%d", &a[n++]);
 }
 fclose(fp);
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
 fp=fopen("/home/user/Desktop/files/numbers.txt", "w");
 for(i=0;i<n;i++)
 {
  fprintf(fp, "%d ", a[i]);
 }
}
