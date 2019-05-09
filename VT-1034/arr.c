/*create an arry with lenth argv[1],rotate that array with argv[2] times
example:array elements: 1,2,3,4 and argv[2]=1 output:2,3,4,1
example:array elements:1,2,3,4 and argv[2]=2 output:3,4,1,2*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
int i,j,temp;
if(argc!=3)
        printf("Enter arguments properly\n");
int *p=(int *)malloc((atoi(argv[1]))*sizeof(int));
printf("enter the elements\n");
for(i=0;i<(atoi(argv[1]));i++)
scanf("%d",&p[i]);
for(i=0;i<(atoi(argv[1]));i++)
printf("%d\n",p[i]);
//rotate(int *ptr);
for(i=0;i<(atoi(argv[2]));i++ )
{temp=p[0];
for(j=0;j<=((atoi(argv[1]))-2);j++)
p[j]=p[j+1];
p[j]=temp;}
printf("after rotate\n");
for(i=0;i<(atoi(argv[1]));i++)
printf("%d\n",p[i]);
}



