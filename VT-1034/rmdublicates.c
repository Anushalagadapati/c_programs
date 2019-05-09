/*remove dublicates in a linked list
example:input 1->1->2->3->3 output:1->2->3*/
#include<stdio.h>
#include<stdlib.h>
struct stu
{
        int data;
        struct stu *next;
};
void rmdublicates(struct stu *head);
struct stu * create(struct stu *head);
void traversal(struct stu *p);
main()
{struct stu *head=NULL;
head=create(head);
//traversal(head);
rmdublicates(head);
printf("after removing of dublicate elements\n");
traversal(head);
}
struct stu * create(struct stu *head)
{
        struct stu *ltemp=NULL,*p=NULL;
	int l;
	printf("enter lenth of linked list\n");
	scanf("%d",&l);
        while(l)
        {
                ltemp=(struct stu *)malloc(sizeof(struct stu));
                printf("enter data\n");
                scanf("%d",&(ltemp->data));
                ltemp->next=NULL;
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
                l--;
        }
        return head;
}
void rmdublicates(struct stu *head)
{
struct stu *h1=head,*temp=head->next,*p=temp;
h1->next=NULL;
while(temp!=NULL)
{
h1=head;
while(h1!=NULL)
{
p=h1;
if(h1->data==temp->data)
	break;
//p=h1;
h1=h1->next;
}
if(p->data==temp->data)
{
temp=temp->next;
}
else
{
p->next=temp;
temp=temp->next;
p->next->next=NULL;
}
}
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

