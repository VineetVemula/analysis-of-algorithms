#include<stdio.h>

void main()
{
 int x, y,i,j,r,a[100],temp=0,n,m=0;
 FILE *fp;
 printf("Enter number of integers in file");
 scanf("%d",&n);
 fp=fopen("/home/user/Desktop/files/numbers3.txt", "w");
 for(i=0;i<n;i++)
 {
  r=rand()%100;
  x=r*i;
  fprintf(fp, "%d\n", x);
 }
}
