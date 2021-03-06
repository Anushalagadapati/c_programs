/* printing 1,2,3 */
#include<stdio.h>
#include <pthread.h>
#include<signal.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
sigset_t s_set1;
void *thread_result;
pthread_t t1_thread,t2_thread,t3_thread,a;
void *read1(void *arg);
void *read2(void *arg);
void *read3(void *arg);
void handler(void);
int sig1;
int c=0;
int x=10;
main()
{
	int res;
	sigemptyset(&s_set1);
	sigaddset(&s_set1,10);
	signal(SIGINT,handler);
	pthread_sigmask(SIG_BLOCK, &s_set1, NULL);
	res = pthread_create(&t1_thread, NULL, &read1, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}
	res = pthread_create(&t2_thread, NULL, &read2, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}
	res = pthread_create(&t3_thread, NULL, &read3, NULL);
        if (res != 0) {
                perror("Thread creation failed");
                exit(EXIT_FAILURE);}

	printf("Wait for pthread_join\n");
	pthread_kill(t1_thread,10);
	res=pthread_join(t1_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	res=pthread_join(t2_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);}
	 res=pthread_join(t3_thread, &thread_result);
        if (res != 0) {
                perror("Thread join failed");
                exit(EXIT_FAILURE);}

	printf("both threads are joined\n");
}
void *read1(void *arg)
{
int i;
	sigwait(&s_set1,&sig1);
	while(1)
	{
		printf("1\n");
		pthread_kill(t2_thread,10);
		sigwait(&s_set1,&sig1);
		//signal(SIGINT,handler);
		if(c==1){printf("t1\n");
			break;}
	}
	
	printf("t5htead1 exit\n");
	pthread_kill(t2_thread,10);
	pthread_exit(0);
}
void *read2(void *arg)
{
	sigwait(&s_set1,&sig1);
	while(1)
	{
		printf("2\n");
		pthread_kill(t3_thread,10);
		sigwait(&s_set1,&sig1);
		//signal(SIGINT,handler);
		if(c==1){printf("t2\n");
			break;}
	}
	printf("thread2 exit\n");
	 printf("%d\n",x);
	pthread_kill(t3_thread,10);
	pthread_exit(0);
}
void *read3(void *arg)
{
        sigwait(&s_set1,&sig1);
        while(1)
        {
                printf("3\n");
                pthread_kill(t1_thread,10);
                sigwait(&s_set1,&sig1);
                //signal(SIGINT,handler);
                if(c==1){printf("t3\n");
                        break;}
        }
        printf("thread3 exit\n");
	 printf("%d\n",x);
        pthread_exit(0);
}

void handler(void)
{//static int c=1;
	//signal(SIGINT,SIG_DFL);
	printf("inside handler");
	c++;
	pthread_kill(t1_thread,10);
	//pthread_exit(0);
	//pthread_exit(0);
	signal(SIGINT,SIG_DFL);
	
}
