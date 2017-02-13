#include<stdio.h>
#include<stdlib.h>

int getlot(int s[][2],int dl)
{
	int i;
	for (i=dl;i>=0;i--)
	{
		if(s[i][1]==0)
		{
			return i;
		}
	}
	return -1;
}

void js(int x[][3],int s[][2],int n,int k)
{
	int profit=0,i,j,t=0,o=0,l=0,avail;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if (x[j][1]<x[j+1][1])
			{
				t=x[j][1];
				x[j][1]=x[j+1][1];
				x[j+1][1]=t;
				o=x[j][2];
				x[j][2]=x[j+1][2];
				x[j+1][2]=o;
				l=x[j][0];
				x[j][0]=x[j+1][0];
				x[j+1][0]=l;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		avail=getlot(s,x[i][2]);
		if(avail==-1)
		{
			printf("the job %d can't be scheduled\n",x[i][0]);
		}
		else 
		{
			s[avail][0]=x[i][0];
			s[avail][1]=1;
			profit = profit + x[i][1];
		}
	}
	for(i=0;i<=k;i++)
	{
		if(s[i][0]==-1)
		{
			printf("no job scheduled at %d\n",i+1);
		}
		else
		{
			printf("Job %d at %d\n",s[i][0],i+1);
		}
	}
	printf("total profit is %d\n",profit);
}

int main()
{
	int n,i,max,s[100][2],x[100][3];
	
	printf("Enter the no of jobs\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s[i][0]=-1;
		s[i][1]=0;
	}
	printf("enter the job no profit and deadline one by one\n");

	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x[i][0],&x[i][1],&x[i][2]);
		x[i][2]=x[i][2]-1;
	}
	max=x[0][2];
	for(i=1;i<n;i++)
	{
		if(max<x[i][2])
		{
			max=x[i][2];
		}
	}
	js(x,s,n,max);
	
}
