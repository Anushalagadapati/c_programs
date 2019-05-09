#include<stdio.h>
#include<stdlib.h>
struct stu
{
        int data;
        struct stu *next;
};
struct stu * push();
struct stu * pop();
void traversal(struct stu *p);
int count =0;
struct stu *top=NULL,*prev=NULL,*p=NULL;
main()
{
char c, a='y';
struct stu *p=NULL;
while(a=='y')
{
printf("enter ur choice\n");
scanf(" %c",&c);
switch(c)
{
case '1':p=push();
	break;
//case '2':pop();
	//break;
case '2':p=pop();
	break;
}
printf("do u want to continue\n");
scanf(" %c",&a);
}
}
struct stu * push()
{
        struct stu *ltemp=NULL;
        ltemp=(struct stu *)malloc(sizeof(struct stu));
        printf("enter data\n");
        scanf("%d",&(ltemp->data));
        ltemp->next=NULL;
                if(top==NULL)
                {
                        top=ltemp;
                }
                else
                {
                        ltemp->next=top;
			//prev=top->next;
                        top=ltemp;
                }
              count++;
return top;
}

struct stu * pop()
{
struct stu *q=NULL;
if(count!=0)
{
printf("%d poping\n",top->data);
count--;
q=top;
top=top->next;
free(q);
}
else
printf("stack is empty\n");
return top;
}
