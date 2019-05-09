/*You are given queries. Each query consists of a single number . You can perform any of the operations on in each move:

1: If we take 2 integers and where , , then we can change

2: Decrease the value of by .

Determine the minimum number of moves required to reduce the value of to .

Input Format

The first line contains the integer .
The next lines each contain an integer, .

Constraints


Output Format

Output lines. Each line containing the minimum number of moves required to reduce the value of to .

Sample Input

2
3
4

Sample Output

3
3

Explanation

For test case 1, We only have one option that gives the minimum number of moves.
Follow -> -> -> . Hence, moves.

For the case 2, we can either go -> -> -> -> or -> -> -> . The 2nd option is more optimal. Hence, moves.*/


/*logic 1:	1*1=1: 2*1=2,2*2=4; 3*1=3,3*2=6,3*3=9; cal count upto the given num and store these in an array*/

/*#include<stdio.h>

void main()
    {
      int m,i,j;
      printf("enter n value\n");
      scanf("%d",&m);
      int n[m];
      n[0]=0;
      for(i=1;i<m+1;i++)
        n[i]=-1;
      for(i=1;i<=m;i++){
          if(n[i]==-1||n[i]>n[i-1]+1)
            n[i]=n[i-1]+1;
          for(j=1;j<=i&&i*j<=m;j++)
          {
              if(n[i*j]==-1||n[i*j]>n[i]+1)
                n[i*j]=n[i]+1;
          }
      }
      i--;
      printf("count=%d\n",n[i]);
    }*/


#include<stdio.h>
#include<math.h>
int zero(int n);
int min(int n,int i);
int midfact(int n);
main()
{
int n,c;
printf("enter num\n");
scanf("%d",&n);
c=down_to_zero_level(n);
printf("count=%d\n",c);
}


/*logic 2:using middile factors*/

/*int down_to_zero_midfact(int n)
{
int i;
if(n==0)
return 0;
i=midfact(n);
if(i!=1)
return min(zero(n/i),zero(n-1))+1;
return zero(n-1)+1;
}
int min(int n,int i)
{
if(n>i)
n=i;
return n;
}
int midfact(int n)
{
int i,j=0,a;
for(i=1; i <=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            a=i;
		
        }
    }

return a;
}*/


/*logic 3: cal min count by considering all factors*/

/*int down_to_zero_all(int n)
{
int i,a,c,m=0;
if(n==0)
return 0;
for(i=1; i <=sqrt(n); i++)
    {
        if (n%i == 0)
        {
	if(i!=1)
	c=zero(n/i)+1;
	else
	c=zero(n-1)+1;
	}
	if((m==0)||(m>c))
	m=c;
}
return m;
}*/


/*logic 4: cal min count by considering all factors(break the loop when ever u find 0 and print the level*/ 

int down_to_zero_level(int n)
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


