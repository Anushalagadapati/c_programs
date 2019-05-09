#include<stdio.h>

#include<stdlib.h>

#include <pthread.h>

#include <unistd.h>

#include <sys/types.h>

#include <stdio.h>

#include <signal.h>

#include<string.h>

FILE *fp;

char s1[100]={0};

pthread_t  t1, t2;

sigset_t set;

/*void  fun( int signum)
  {

  printf("in handler\n");

  }*/
int mycasecompare(char *buff, char *str)
{
	int i=0,cnt=0,flg=0;

	if(strlen(buff)==strlen(str))
	{
		while(buff[i])
		{
			if( (str[i]==buff[i])||(str[i]==buff[i]+32) || (buff[i]==str[i]+32))
			{
				flg=1;
			}
			else
				return 1;
			i++;
		}

		if(flg)
		{

			return 0;
		}
	}
	else
		return 1;

}


void * readfromfile(void  * f1)
{     

	int sig; int result;	

	 result = sigwait(&set, &sig);

         if(result == 0)

        printf("sigwait got signal: %d\n", sig);

	printf("\nstarting thread 1 (readfile)\n");

	int rvalue,cnt=0;

	int status;

	char * f =(char *)f1;

	fp=fopen(f,"r+");

	if(fp==NULL)
	{
		printf("error: in opening the file:file doesnt exists\n");
		exit(0);
	}
		
	
	while(((fscanf(fp,"%s", s1))!=EOF)&&(t2))
	{
		printf("\nthread 1 :%s \n",s1);

		pthread_kill(t2, SIGUSR1);

		result = sigwait(&set, &sig);

		if(result == 0)

			printf("sigwait got signal: %d\n", sig);

	}


	pthread_exit(0);
}


void * compare(void * userstr)
{

	int sig;

	int result;

	int status;

	result=sigwait(&set, &sig);

	if(result == 0)

		printf("\nstarting thread 2 (compare)\n");

	int i,j,k=0,cnt=0;

	char s2[50]; 

	char * userstr2;

	char temp;

	userstr2=(char *)userstr;

	while(!feof(fp))
	{   
		printf("thread 2\n");

		if(mycasecompare(s1,userstr2)==0)
		{
			for(i=0,j=strlen(s1)-1;i<j;i++,j--)
			{
				temp=s1[i];
				s1[i]=s1[j];
				s1[j]=temp;
			}


			printf("t2:%s\n",s1);		

			fseek(fp,-strlen(s1),SEEK_CUR);

			fprintf(fp,"%s",s1);

		}
		memset(s1,'\0',100);


		status = pthread_kill( t1, SIGUSR2);                                     

		if ( status <  0)                                                              

			perror("pthread_kill failed");

		result = sigwait(&set, &sig);

		if(result == 0)

			printf("sigwait got signal %d\n ",sig);
	}

	pthread_exit(0);
}




int main( int argc ,char **argv)
{
	int ret;

	sigemptyset(&set);

	sigaddset(&set, SIGUSR2);

	sigaddset(&set, SIGUSR1);

	pthread_sigmask(SIG_BLOCK, &set, NULL);

	if(argc != 3)
	{
		printf("error : input exe/filename/string\n");
		exit(0);
	}


	ret=pthread_create(&t1, NULL, readfromfile, argv[1]); 
	if(ret)
	{	
		printf("\n pthread_creat failed\n");
		exit(0);
	}

	pthread_create(&t2, NULL, compare, argv[2]); 
	if(ret)
	{
		printf("\n pthread_creat failed\n");
		exit(0);
	}
	 pthread_kill(t1,SIGUSR2);
	
	pthread_join(t1,NULL);

	pthread_kill(t2, SIGUSR1);

	pthread_join(t2,NULL);

	pthread_sigmask(SIG_UNBLOCK,&set,NULL);

	fclose(fp);

	exit(0);
}
