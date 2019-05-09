/*******************input---->single linked list output---> duble circular linked list ,farward printing ,backward printing*******************/
#include<stdio.h>
#include<stdlib.h>
struct stu
{
	struct stu *prev;
        int data;
        struct stu *next;
};
struct stu * create(struct stu *head);
void traversal(struct stu *p);
void circularlist(struct stu *head);
void forward(struct stu *head);
void backward(struct stu *head);
main()
{
struct stu *head=NULL;
head=create(head);
traversal(head);
//circularlist(head);
printf("forward printing\n");
//traversal(head);
forward(head);
printf("backward printing\n");
backward(head);
}
struct stu * create(struct stu *head)
{
        struct stu *ltemp=NULL,*p=NULL;
	char c='y';
       while(c=='y')
        {
                ltemp=(struct stu *)malloc(sizeof(struct stu));
                printf("enter data\n");
                scanf("%d",&(ltemp->data));
                ltemp->next=NULL;ltemp->prev=NULL;
                if(head==NULL)
                {
                        head=ltemp;
                        p=head;
                }
                else
                {
                        p->next=ltemp;
                        p=p->next;
                }
         printf("do you want to continue y/n\n");
	scanf(" %c",&c);
        }
        return head;
}
void traversal(struct stu *p)
{
	if(p==NULL)
        printf("list is empty\n");
        else
        {
                while(p!=NULL)
                {
                        printf("%d\n",p->data);
                        p=p->next;
                }
        }
}
void circularlist(struct stu *head)
{
struct stu *p=head,*c=head;
if(head->next==NULL)
printf("only one node\n");
else
{
while(c->next!=NULL)
{
c=c->next;
c->prev=p;
p=p->next;
}
c->next=head;
head->prev=c;
}
}
void forward(struct stu *head)
{
struct stu *c=head;
while(c->next!=head)
{
printf("%d\n",c->data);
c=c->next;
}
printf("%d\n",c->data);
}
void backward(struct stu *head)
{
struct stu *c=head;
if(head->prev==NULL)
printf("it is not circular double linked list\n");
//return;
else
{ 
while(c->next!=head)
c=c->next;
while(c!=head)
{printf("%d\n",c->data);
c=c->prev;}
printf("%d\n",c->data);
}
}
