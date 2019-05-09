/*create linked list find the middle element and reverse the list
example:(for even num of elements)1,2,3,4,5,6----->3,2,1,6,5,4
example:(for odd num of elements)1,2,3,4,5-------->2,1,3,5,4*/
#include<stdio.h>
#include<stdlib.h>
struct stu
{
	int data;
	struct stu *next;
};
void traversal(struct stu *head);
struct stu* create();
//struct stu* rv(struct stu *head);
struct stu* reverse(struct stu* head);
void reveven(struct stu *head,int l);
struct stu * middle(struct stu *head);
main()
{
	int n,i;
	struct stu *temp=NULL,*temp1=NULL,*head=NULL,*p=NULL;
	printf("enter the number\n");
	scanf("%d",&n);
	i=n;
	while(i)
	{
		temp=create();
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
		i--;
	}
	//temp=middle(head);
	temp=reverse(head);
	traversal(temp);
}
struct stu * create()
{
	struct stu *ltemp=NULL;
	ltemp=(struct stu *)malloc(sizeof(struct stu));
	printf("enter data\n");
	scanf("%d",&(ltemp->data));
	ltemp->next=NULL;
	return ltemp;
}
void traversal(struct stu *p)
{
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

/*struct stu* reverse(struct stu* head)
{
	struct stu* n=head,*p=head,*c=head;
	if(head->next==NULL)
	{
		printf("only one element\n");
		return head;
	}
	else
	{
	c=c->next;
	if(c->next!=NULL)
	{
		n=c->next;
		while(c!=NULL)
		{
			c->next=p;
			p=c;
			c=n;
			if(n!=NULL)
				n=n->next;
		}
		head->next=NULL;
		head=p;
	}
	else
	{
		c->next=p;
		head=c;
		p->next=NULL;
	}
	return head;
	}
}*/
struct stu* reverse(struct stu* head)
{
struct stu* n=NULL,*p=NULL,*c=head;
while(c!=NULL)
{
n=c->next;
c->next=p;
p=c;
c=n;
}
head=p;
return head;
}

/*void reveven(struct stu *head,int l)
{
	struct stu *temp=head,*temp1=NULL;
	int i;
	for(i=1;i<l/2;i++)
		temp=temp->next;
	temp1=temp->next;
	temp->next=NULL;
	temp=reverse(head);
	head=temp;
	temp1=reverse(temp1);
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=temp1;
	traversal(head);
}
void revodd(struct stu *head,int l);
{
struct stu *temp=head,*temp1=NULL;
 for(i=1;i<l/2;i++)
                temp=temp->next;

}*/
struct stu * middle(struct stu *head)
{
struct stu *f=head,*s=head,*temp=NULL,*p=head;
while((f->next!=NULL)&&(f!=NULL))
{//s=s->next;
if(f->next->next==NULL)
break;
f=f->next->next;
p=s;
s=s->next;
}
if(f->next!=NULL)
{
printf("even\n");
temp=s->next;
s->next=NULL;
head=reverse(head);
temp=reverse(temp);
s=head;
while((s->next)!=NULL)s=s->next;
s->next=temp;
return head;
}
else
{
printf("odd\n");
p->next=NULL;
head=reverse(head);
p=head;
while(p->next!=NULL)p=p->next;
p->next=s;
temp=s->next;
temp=reverse(temp);
s->next=temp;
return head;
}
}
