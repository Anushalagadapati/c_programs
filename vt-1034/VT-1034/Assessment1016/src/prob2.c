#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m,n,i,j,a,x=0,y=0,k,l,sum=0,dsum=0;
	printf("Enter the value of m & n:");
	scanf("%d%d",&m,&n);
	int **p=(int **)malloc(m*sizeof(int *));		//Allocate memory to array dynamically
	for(i=0;i<m;i++)
		p[i]=(int *)malloc(n*sizeof(int));

	printf("Enter the Array elements:\n");		
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			p[i][j]=a;
		}
	}
	/* For calculating sum of diagonals of original matrix */
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{	
			if(i==j)
			dsum+=p[i][j]+p[m-i-1][n-j-1];
		}	
	printf("Sum of diagonals:%d\n",dsum);
	
	/* Convert to 3*3 matrix if it is not */
	if(m %3 != 0 ){
		x=3-(m%3);
		x=m+x;
	}	
	else
		x=m;
	if(n%3 !=0 ){
		y=3-(n%3);
		y=n+y;
	}
	else
		y=n;
	if(m%3 !=0 || n%3 != 0){
	p= (int **)realloc(p,(x+1)*sizeof(int *));
	if(p==NULL){
		printf("Reallocation failed\n");
		exit(0);
	}
	for(i=0;i<=x;i++)
	{
		p[i]=(int *)realloc(p[i],y*sizeof(int));	
	}
	}
	printf("x=%d y=%d\n",x,y);

	for(i=m;i<x;i++)
		for(j=0;j<y;j++)
			p[i][j]=1;

	for(i=0;i<x;i++)
		for(j=n;j<y;j++)
			p[i][j]=1;

	printf("Array is:\n");
	for(i=0;i<x;i++){
		for(j=0;j<y;j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}

	/* Addition of 3*3 micro block */
	for(k=0;k<x;k+=3)
	{
		for(l=0;l<y;l+=3)
	{
		for(i=k;i<k+3 && i<x;i++)
			for(j=l;j<l+3 && j<y;j++)
			{
				sum+=p[i][j];
			}

		printf("Sum of 3*3 block:%d\n",sum);
		sum=0;
	}

	}
	free(p);
}
