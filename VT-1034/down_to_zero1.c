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
#include<stdio.h>
#include<math.h>
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
}


		


