#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include<sys/types.h>
typedef struct node{
	int data;
	struct node *next;
}node;
static int alarm_fired = 0;
void ding(int sig)
{
alarm_fired = 1;
}
int i=0,a;
node *rear=NULL,*front=NULL,*q=NULL;
void enqueue()
{
	//node *rear=NULL,*front=NULL;
	int n,data;
	//int i = 0;
	printf("enter the number of messages you want to enqueue\n");
	scanf("%d",&n);
	if(i+n<20){
		while(n)
		{
			if(front==NULL)
			{
				printf("Enter the data: \n");
				scanf("%d",&data);
				node *newNode = (node *)malloc(sizeof(node));	
				newNode->data = data;		
				newNode->next=NULL;
				rear = newNode;													
				front = rear;	
				n--;
				i++;
			}
			else
			{
				printf("Enter the data: ");		
				scanf("%d",&data);	
				node *newNode = (node *)malloc(sizeof(node));		
				newNode->data = data;		
				//newNode->next=front;	
				rear->next=newNode;
				rear = newNode;
				n--;i++;
			}
		}				        
		//i++;                
	}
	else
		printf("waiting\n");
		pause();
		//(void) signal(SIGALRM, ding);					
		pthread_exit("exit");
}
void dequeue()
{
	//node* q=NULL;
	int c;
	printf("enter the num of elements u want to dequeue\n");
	scanf("%d",&c);
	if(c<=(i+1))
	{
		while(c)
		{
			if(front == NULL)

			{

				printf("queue is empty\n");

				return;

			}

			if(front==rear)

			{

				printf("dequeued data is %d:\n",front->data);

				free(front);

				front=NULL;

				rear=NULL;
				i--;
				c--;
                                //FILE *fopen("abc", const char *mode);


			}

			else

			{

				printf("dequeued data is %d:\n",front->data);

				q=front;

				front=front->next;

				rear->next=front;

				free(q);

				q=NULL;
				i--;
				c--;
				FILE *fopen(const char *path, const char *mode);

			}
		}
	}
	if(c>i+1)
		printf("sorry dequeue \n");
	pthread_exit("exit");
}

main()
{
	int res,c;
	//node* rear=NULL;
	(void) signal(SIGALRM, ding);
	pthread_t a_thread,b_thread;
	void *thread_result;
	while(1)
	{
		printf("Enter the operation 1.enqueue 2.dequeue\n");
		scanf("%d",&c);
		if(c==1)
		{
			//	node* t1;
			//enqueue();
			res = pthread_create(&a_thread, NULL, enqueue, NULL);
			if (res != 0) 
			{
				perror("Thread creation failed");
				exit(EXIT_FAILURE);
			}
			res = pthread_join(a_thread, &thread_result);
			if (res != 0) {
				perror("Thread join failed");
				exit(EXIT_FAILURE);
			}

		}
		if(c==2)
		{
			//dequeue();
			//printf("%d\n",a);
			res = pthread_create(&b_thread, NULL, dequeue, NULL);
			if (res != 0) 
			{
				perror("Thread creation failed");
				exit(EXIT_FAILURE);
			}

			res = pthread_join(b_thread, &thread_result);
			if (res != 0) {
				perror("Thread join failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
