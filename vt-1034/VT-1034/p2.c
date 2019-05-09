#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c,z,i,j,x=0,a,k;
	static m,n;
	printf("enter rows and coloumns\n");
	scanf("%d%d",&r,&c);
	int **ptr=(int **)malloc(sizeof(int *)*r);
	printf("enter elements of array\n");
	for(i=0;i<r;i++)
	{
		 ptr[i]=(int *)malloc(sizeof(int)*c);
		for(j=0;j<c;j++)
		{
			
			scanf("%d",&ptr[i][j]);
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",ptr[i][j]);
			printf("\n");
	}
			/*for(i=0;i<r;i++)
			{
				free(ptr[i]);
				ptr[i]=NULL;
			}
			free(ptr);
			ptr=NULL;*/
z=((r%3)||(c%3));
if(z)
{
printf("adding 1\n");
}
else
{
a=((r*c)/9);
while(a)
{
//x=0;
for(m=0;m<r;m++)
{
if(m%3==0&&m!=0)
break;
for(n=0;n<c;n++)
{
if(n%3==0&&n!=0)
break;
x+=ptr[m][n];
}
//if(i%3==0&&i!=0)
//break;
}
a--;
printf("%d\n",x);
x=0;
}
}
}


