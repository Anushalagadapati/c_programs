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
void handler1();
void handler2();
sigset_t sw;
int casecmp(char temp[],char str[]);
int main(int argc,char *argv[])
{
	int rt1,rt2;
	fp=fopen(argv[1],"r+");
	strcpy(str,argv[2]);
	if(fp==NULL)
		printf("error in opening file\n");
	rt1=pthread_create(&id1,NULL,thread1,NULL);
	if(rt1!=0)
		printf("error in creating thread1\n");
	rt2=pthread_create(&id2,NULL,thread2,NULL);
	if(rt2!=0)
		printf("error in creating thread2\n");
	rt1=pthread_join(id1,NULL);
		if(rt1!=0)
			printf("thread1 join failed\n");
	rt2=pthread_join(id2,NULL);
		if(rt2!=0)
			printf("thread2 join failed\n");
}
void *thread1(void *arg)
{
	sleep(5);
	signal(SIGUSR1,handler1);
	printf("thread1\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s",temp);
		pthread_kill(id2,SIGALRM);
		pause();
	}
	pthread_exit("exit");

} 
void *thread2(void *arg)
{
	sleep(5);
	signal(SIGALRM,handler2);
	printf("thread2\n");
	char rev;
        int i,j,l,l1;
	printf("%s\t",str);
	while(!feof(fp))
	{
		if(strcasecmp(temp,str)==0)
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
		pause();
	}
	fclose(fp);
        if(fp==NULL)
                printf("error in closing file\n");
	pthread_exit("exit");

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
	}
	return a;
}			
void handler1()
{
	printf("inside handler1\n");

}
void handler2()
{
	printf("inside handler2\n");
}


		
