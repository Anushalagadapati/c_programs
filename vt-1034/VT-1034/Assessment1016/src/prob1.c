/*** Program for creating 4 threads and printing 1,2,3,4 synchronously ***/

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

sem_t *sem1,*sem2,*sem3,*sem4;	//Semaphore varibles

void * thread1(void *arg)	//Thread function for printing 1
{
	while(1){			
		sem_wait(sem1);
		printf("1 ");
		usleep(20);
		sem_post(sem2);
	}	
}
void * thread2(void *arg) //THread function for printing 2
{
	while(1){
		sem_wait(sem2);
		printf("2 ");
		usleep(20);
		sem_post(sem3);
	}
}
void * thread3(void *arg)	//Thread function for printing 3
{
	while(1){
		sem_wait(sem3);
		usleep(20);
		printf("3 ");
		sem_post(sem4);
	}
}

void * thread4(void *arg)  //Thread function for printing 4
{
	while(1){
		sem_wait(sem4);
		printf("4\n");
		sleep(1);
		sem_post(sem1);
	}
}
int main(){
	pthread_t th1,th2,th3,th4;  //Thread variables
	/* Four semaphores created for Synchronizing the threads */
	sem1=sem_open("pSem1",O_CREAT|O_EXCL,0666,1); 
	sem2=sem_open("pSem2",O_CREAT|O_EXCL,0666,0);
	sem3=sem_open("pSem3",O_CREAT|O_EXCL,0666,0);
	sem4=sem_open("pSem4",O_CREAT|O_EXCL,0666,0);

	/* Sem_unlink will prevent Semaphores to exist forever */
	sem_unlink("pSem1");
	sem_unlink("pSem2");
	sem_unlink("pSem3");
	sem_unlink("pSem4");

	/* Four thread created for printing 1,2,3,4 */
	pthread_create(&th1,NULL,thread1,NULL);
	pthread_create(&th2,NULL,thread2,NULL);
	pthread_create(&th3,NULL,thread3,NULL);
	pthread_create(&th4,NULL,thread4,NULL);

	/* Main thread will wait for child threads to join at exit */
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	pthread_join(th3,NULL);
	pthread_join(th4,NULL);
	return 0;
}

