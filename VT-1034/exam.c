#include<stdio.h>
#include <pthread.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<signal.h>
void *t1(void *f1);
void *t2(void *arg);
char * strrev(const char *s);
pthread_t t1_thread,t2_thread;
sigset_t s_set1;
void *thread_result;
char *buf=NULL;
FILE *fp=NULL;
char s[100];
char *s1=NULL;
//int sig1;
struct sigaction act1,act2;
//int res,res1;
int main(int argc, char *argv[])
{
	int res;
	buf=argv[2];
	sigemptyset(&s_set1);
	sigaddset(&s_set1,10);
	sigaddset(&s_set1,12);
	if(argc!=3)
	printf("Enter file name and word properly\n");
	//fp=fopen(argv[1],"r+");
	pthread_sigmask(SIG_BLOCK, &s_set1, NULL);
	if(fp==0)
	{printf("file open fail");
		exit(EXIT_FAILURE);}
	res = pthread_create(&t1_thread, NULL, t1, argv[1]);
	/*if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}*/
	 pthread_create(&t2_thread, NULL, t2, NULL);
	/*if (res1 != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);}*/
	printf("Wait for pthread_join\n");
	//pthread_sigmask(SIG_UNBLOCK, &s_set1, NULL);
	//if(fp==0)
	 pthread_kill(t1_thread,10);
	pthread_join(t1_thread, &thread_result);
/*	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}*/
	    pthread_kill(t2_thread,12);

	pthread_join(t2_thread, &thread_result);
	/*if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);}*/
	pthread_sigmask(SIG_UNBLOCK, &s_set1, NULL);
	
fclose(fp);
exit(0);
}
void *t1(void *f1)
{	int n,i,sig1,result;
	printf("this is t1\n");
	char* f =(char *)f1;
        fp=fopen(f,"r+");

//	sigwait(&s_set1,&sig1);
	//fp=fopen(argv[1],"r+");
		//while((!feof(fp))&&t2_thread)
	/*	while(((fscanf(fp,"%s", s1))!=EOF)&&(t2_thread))
		{
			n=fscanf(fp,"%s",s);
			//if(t2_thread)
			pthread_kill(t2_thread,12);
			sigwait(&s_set1,&sig1);
			printf("%d",sig1);
		}*/
		while(((fscanf(fp,"%s", s1))!=EOF)&&(t2_thread))
        {
                printf("\nthread 1 :%s \n",s1);

                pthread_kill(t2_thread, 12);

                result = sigwait(&s_set1, &sig1);

                if(result == 0)

                        printf("sigwait got signal: %d\n", sig1);

        }

		pthread_exit(0);


}
void *t2(void *arg)
{	int sig1;
	printf("this is t2\n");
 	sigwait(&s_set1,&sig1);
		while(!feof(fp))
		{
			if(!strcasecmp(buf,s))
			{
				s1=strrev(s);
				fseek(fp,-strlen(s),SEEK_CUR);
				fprintf(fp,"%s",s1);
			}
			//strcat(s1,'\0');
			pthread_kill(t1_thread,10);	
			sigwait(&s_set1,&sig1);
		}	
		pthread_exit(0);		
	
}
char * strrev(const char *s)
{
	int i,j;
	char t;
	char *b=(char *)malloc(strlen(s)*sizeof(char));
	memcpy(b,s,strlen(s)*sizeof(char));
	for(i=0,j=strlen(b)-1;i<j;i++,j--)
	{
		t=b[i];
		b[i]=b[j];
		b[j]=t;
	}
	return b;
}

int stricmp(const char *s1,const char *s2)
{
	int i;
	for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
	{
		if(s1[i]!=s2[i]&&s1[i]!=s2[i]+32&&s1[i]!=s2[i]-32)
			break;
	}
	if(s1[i]=='\0'&&s2[i]=='\0')
		return 0;
	return s1[i]-s2[i];
}
int strcmp(const char *s1,const char *s2)
{
	int i;
	for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++)
		if(s1[i]!=s2[i])
			break;
	return s1[i]-s2[i];
}

