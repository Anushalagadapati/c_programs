#include<stdio.h>
#include<stdlib.h>
struct stu
{
        int a;
	int b;
	int sum;
        struct stu *next;
};
int f=0,c=0;
struct stu * create(int a, int b,int sum);
void traversal(struct stu *p,int s);
void findsum(int *arr,int n);
main()
{
int n,i;
printf("enter array size\n");
scanf("%d",&n);
int *arr=(int *)malloc(sizeof(int)*n);
printf("enter elements in an array\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
findsum(arr,n);
free(arr);
}
void findsum(int *arr,int n)
{
struct stu *head=NULL,*p=NULL,*temp=NULL;
int i,j,arrsum;
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
{
arrsum=arr[i]+arr[j];
traversal(head,arrsum);
if(f==1)
{
printf("%d,%d\n",arr[i],arr[j]);
f=0;
}
else
{
		temp=create(arr[i],arr[j],arrsum);
                if(head==NULL)
                {
                        head=temp;
                        p=head;
                }
                else
                {
                        p->next=temp;
                        p=p->next;
                }

}
}
if(c==0)
printf("No pairs found\n");
}

void traversal(struct stu *p,int s)
{
        while(p!=NULL)
        {
                
		if(s==p->sum)
		{f=1;c=1;
		printf("%d,%d\t",p->a,p->b);}
		p=p->next;
        }
}

struct stu * create(int a, int b,int sum)
{
        struct stu *ltemp=NULL;
        ltemp=(struct stu *)malloc(sizeof(struct stu));
        ltemp->a=a;
	ltemp->b=b;
	ltemp->sum=sum;
        ltemp->next=NULL;
        return ltemp;
}

