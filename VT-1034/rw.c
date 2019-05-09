/*Thread1---->read 1st word,thread2---->read 2nd word,main()---->write 1st and 2nd words in argv[2] using signals*/
#include<stdio.h>
#include <pthread.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<signal.h>
sigset_t s_set1;
FILE *fp1,*fp2;
char s[100],s1[100];
void *thread_result;
pthread_t t1_thread,t2_thread, a;
void *read1(void *arg);
void *read2(void *arg);
int res2=2;
int main(int argc, char *argv[])
{
	int sig1,res;
	a=pthread_self();
	
	sigemptyset(&s_set1);
	sigaddset(&s_set1,10);
	if(argc!=3)
		printf("Enter file name and word properly\n");
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	pthread_sigmask(SIG_BLOCK, &s_set1, NULL);
	res = pthread_create(&t1_thread, NULL, &read1, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}
	res2 = pthread_create(&t2_thread, NULL, &read2, NULL);
	if (res2 != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}
	pthread_kill(t1_thread,10);
	while(!feof(fp1)&&(t1_thread))
	{
		sigwait(&s_set1,&sig1);
		fprintf(fp2,"%s",s);
		fprintf(fp2,"%s"," ");
		fprintf(fp2,"%s",s1);
		fprintf(fp2,"%s"," ");
		pthread_kill(t1_thread,10);
	}
	printf("Wait for pthread_join\n");
	res=pthread_join(t1_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	res=pthread_join(t2_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);}
	//pthread_sigmask(SIG_UNBLOCK, &s_set1, NULL);
	fclose(fp1);
	fclose(fp2);
exit(0);

}
void *read1(void *arg)
{
	int sig1;
	sigwait(&s_set1,&sig1);
	while(t2_thread && (!feof(fp1)))
	{	printf("\nthread1\n");	
		fscanf(fp1,"%s",s);
		pthread_kill(t2_thread,10);
		sigwait(&s_set1,&sig1);
		memset(s,'\0',sizeof(s));
	}	
	pthread_kill(t2_thread,10);
	pthread_exit(0);		
}
void *read2(void *arg)
{
	int sig1;
	sigwait(&s_set1,&sig1);
	while(a &&(!feof(fp1)))
	{
		printf("\nthread2\n");
		fscanf(fp1,"%s",s1);
		pthread_kill(a,10);
		sigwait(&s_set1,&sig1);
		memset(s1,'\0',sizeof(s1));
	}
	pthread_kill(a,10);
	pthread_exit(0);
}
