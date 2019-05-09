#include<stdio.h>
main()
{
int n,c=0;
printf("enter num\n");
scanf("%d",&n);
while(n)
{
if(n%2)
c++;
n=n/2;
}
printf("%d\n",c);
}
