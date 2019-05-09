#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>
#include<unistd.h>
FILE *fp;
pthread_t id1,id2;
char temp[100],str[100];
void *thread1(void *arg);
void *thread2(void *arg);
void handler1(int sig);
void handler2(int sig);
int casecmp(char temp[],char str[]);
int main(int argc,char *argv[])
{
	int rt1,rt2;
	signal(SIGUSR1,handler1);
	signal(SIGUSR2,handler2);
	fp=fopen(argv[1],"r+");
	if(fp==NULL)
		printf("filename dosen't exist\n");
	else
	{

	strcpy(str,argv[2]);

	rt1=pthread_create(&id1,NULL,thread1,NULL);
	if(rt1!=0)
		printf("error in creating thread1\n");
	rt2=pthread_create(&id2,NULL,thread2,NULL);
	if(rt2!=0)
		printf("error in creating thread2\n");
	rt1=pthread_join(id1,NULL);
		if(rt1!=0)
			printf("thread1 join failed\n");
		printf("thread1 joined\n");
	rt2=pthread_join(id2,NULL);
		if(rt2!=0)
			printf("thread2 join failed\n");
		printf("thread2 joined\n");
		fclose(fp);
		if(fp==NULL)
		       	printf("error in closing file\n");
	}
}
void *thread1(void *arg)
{
	sleep(1);
	int sig;
	sigset_t set2;
	sigemptyset(&set2);
        sigaddset(&set2,SIGUSR1);
	while(fscanf(fp,"%s",temp)!=EOF)
	{
		pthread_kill(id2,SIGUSR2);
	 	sigwait(&set2,&sig);
	}
	printf("thread1 ready to exit\n");	  
	pthread_kill(id2,SIGINT);
	pthread_exit(NULL);

} 
void *thread2(void *arg)
{
	sleep(1);
	sigset_t set1;
	sigemptyset(&set1);
        sigaddset(&set1, SIGUSR2);
	char rev;
        int i,j,l,l1,a,sig;
	while(!feof(fp))
	{
		a=strcasecmp(temp,str);
		if(!a)
		{
			printf("word found %s %s\n",temp,str);
			l=strlen(temp)-1;
			for(i=0;i<strlen(temp)/2;i++)
			{
				rev=temp[i];
				temp[i]=temp[l];
				temp[l--]=rev;
			}
			printf(" after reversing %s\n",temp);
			l1=strlen(temp);
			if(fseek(fp,-l1,SEEK_CUR)==-1)
				printf("failed in setting position\n");
			if(fprintf(fp,"%s",temp)<0)
				printf("error in writing into file\n");
		}
		pthread_kill(id1,SIGUSR1);
		sigwait(&set1,&sig);
	}
	printf("thread2 ready for exit\n");
	pthread_exit(NULL);
}
int casecmp(char temp[],char str[])
{
	int i=0,j=0,a;
	while(str[j]!='\0' && temp[i]!='\0')
	{
		if(temp[i]==str[i] || temp[i]+32==str[j] || str[j]+32==temp[i])
			a=0;
		else
			a=1;
		i++;
		j++;
	}
	return a;
}			
void handler1(int sig)
{
	printf("inside handler1\n");
	usleep(10);

}
void handler2(int sig)
{
	printf("inside handler2\n");
	usleep(10);
}


		
