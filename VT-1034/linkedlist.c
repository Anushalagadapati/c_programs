/*functions for creating and displaying linkedlists are available*/

#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int data;
	struct stu *next;
};

void traversal(struct stu *p);
struct stu * create(struct stu *head);
/*declare prototype for your function*/

main()
{
	struct stu *head=NULL;
	head=create(head);
	printf("linked list elements are\n");
	traversal(head);
	/*call your function*/
}

/*******write your function definition************/

struct stu * create(struct stu *head)
{
	struct stu *ltemp=NULL,*p=NULL;
	int lenth;
	printf("enter the lenth of a linked list\n");
	scanf("%d",&lenth);
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
		lenth--;
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
