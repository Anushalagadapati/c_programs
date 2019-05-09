#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int zero(int n);
main()
{
int n,c;
printf("enter num\n");
scanf("%d",&n);
c=zero(n);
printf("count=%d\n",c);
}
int zero(int n)
{
int i,j=1,k,z=0,a,f=0;
int *p1=NULL,*p2=NULL;
if(n==0)
return 0;
p1=(int*)malloc(sizeof(int));
p2=(int*)malloc(sizeof(int));
p1[0]=n;
a=1;
while(1)
{
k=0;
for(k=0;k<a;k++)
{
if(p1[k]==0)
return z;
for(i=1; i <=sqrt(p1[k]); i++)
    {
	
        if (p1[k]%i == 0)
        {
	if(i==1)
	{
	p2=(int*)realloc(p2,j*sizeof(int));
	p2[j-1]=p1[k]-1;
	j++;
	}
	else
	{
	p2=(int*)realloc(p2,j* sizeof(int));
	p2[j-1]=p1[k]/i;
	j++;
	}
	}
	}
/*if(p1[k]==n)
a=1;*/
}
	a=j-1;
	p1=(int*)realloc(p1,(j-1)*sizeof(int));
	memcpy(p1,p2,(j-1)*sizeof(int));
 	memset(p2,'\0',sizeof(p2));
	p2=(int*)malloc(sizeof(int));
	j=1;
	z++;
}
}
