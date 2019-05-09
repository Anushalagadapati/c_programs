#include<stdio.h>
#include<stdlib.h>
struct stu
{
        int data;
        struct stu *next;
};
void print_lastnode(struct stu *head);
struct stu * create(struct stu *head);
struct stu * revnode(struct stu *head);
void traversal(struct stu *p);
void print_alternate_node(struct stu *head);
main()
{
struct stu *head=NULL,*p=NULL;
head=create(head);
print_alternate_node(head);
//print_lastnode(head);
//head=revnode(head);
//traversal(head);
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
                printf("do u want to continue y/n\n");
		scanf(" %c",&c);
        }
        return head;
}
void print_lastnode(struct stu *head)
{
       if(head->next==NULL)
	{
	printf("last element=%d\n",head->data);
	return;
	}
	print_lastnode(head->next);
}
struct stu * revnode(struct stu *head)
{
       if(head->next==NULL)
        return head;
	else
	{
	struct stu *newhead=revnode(head->next);
	head->next->next=head;
	head->next=NULL;
	return newhead;
}
}
void traversal(struct stu *p)
{
	if(p==NULL)
    	return;
        else
        {
                        printf("%d\n",p->data);
                        traversal(p->next);
        }
}
void print_alternate_node(struct stu *head)
{
if(head==NULL)
return;
printf("%d\n",head->data);
if(head->next!=NULL)
print_alternate_node(head->next->next);
}

