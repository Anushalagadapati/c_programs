/*create and find a loop in a linked list*/
#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int data;
	struct stu *next;
};

void traversal(struct stu *p);
struct stu * create_loop(struct stu *head);
struct stu *finda_loop(struct stu*head);

main()
{
	struct stu *head=NULL;
	struct stu *p=NULL;
	head=create_loop(head);
//	printf("linked list elements are\n");
//	traversal(head);
//	printf("new list is\n");
	p=finda_loop(head);
	if(p==NULL)
	printf("no loop");
	else
	printf("loop is at=%d\n",p->data);
}


struct stu * create_loop(struct stu *head)
{
	struct stu *ltemp=NULL,*p=NULL,*temp=NULL;
	int lenth,l,c=1;
	printf("enter the lenth of a linked list\n");
	scanf("%d",&lenth);
	printf("enter node num to create loop\n");
	scanf("%d",&l);
	if(lenth<l)
	{
	printf("not possible to create loop\n");
	return NULL;
	}
else{
	while(lenth)
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
		if(c==l)
		temp=p;
		c++;
		lenth--;
	}
}
	p->next=temp;
	return head;
}
struct stu *finda_loop(struct stu*head)
{
struct stu*p=head;
struct stu*q=head;
//while(((p!=q)&&(p!=NULL))||((p==head)&&(q==head)))
do
{

if (q == NULL || p == NULL || p->next == NULL)
return NULL;
p=p->next->next;
q=q->next;
}while(p!=q);
q=head;
while (q != p)
{
p = p->next;
q = q->next;
}
return q;
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
