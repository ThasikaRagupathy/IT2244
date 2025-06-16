(01)
//single thread
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//normal C function that is executed as a thread
//when its name is specified in pthread_create()

void *helloWorld(void *vargp)
{
	sleep(1);
	printf("Hello world\n");
	return NULL;
}

int main(){
	pthread_t thread_id;
	printf("Before thread\n");	
	printf("After Thread\n");
	pthread_create(&thread_id,NULL,helloWorld,NULL);
	pthread_join(thread_id,NULL);
	exit(0);
}

[2021ict89@fedora ~]$ vi thread.c
[2021ict89@fedora ~]$ gcc thread.c -o thread
[2021ict89@fedora ~]$ ./thread
Before thread
After Thread
Hello world

=========================================================================================================================================================================================
(02)
//multi0-threaded process
#include <stdio.h>
#include <pthread.h>

//function to be executed by the thread
void *print_message(void *arg){
	char* message=(char*)arg;
	printf("%s\n",message);
	return NULL;
}

int main(){
	pthread_t thread1,thread2;
	
	//create first thread
	pthread_create(&thread1,NULL,print_message,"HELLO FROM THREAD1 !");
	
	//create second thread
	pthread_create(&thread2,NULL,print_message,"HELLO FROM THREAD2 !");
	
	//wait for both threads to finish
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
	printf("Both threads completed.\n");
	return 0;
}

[2021ict89@fedora ~]$ vi thread.c
[2021ict89@fedora ~]$ gcc thread.c -o thread
[2021ict89@fedora ~]$ ./thread
HELLO FROM THREAD1 !
HELLO FROM THREAD2 !
Both threads completed.

=========================================================================================================================================================================================
(03)
#include <stdio.h>
#include <pthread.h>

//function to be executed by the thread
void *print_message(void *arg){
	char* message=(char*)arg;
	printf("%s\n",message);
	return NULL;
}
int main(){
	pthread_t threads[3];
	char* messages[]={
		"Thread 1 says Hi!",
		"Thread 2 says Hello!",
		"Thread 3 says Hey!"
	};
	
	for(int i=0;i<3;i++){
		pthread_create(&threads[i],NULL,print_message,messages[i]);
	}
	
	for(int i=0;i<3;i++){
		pthread_join(threads[i],NULL);
	}
	
	printf("All threads done.\n");
	return 0;	
}
=========================================================================================================================================================================================
(04)
//using threads to compare parts of a sum(parallel sum)
#include <stdio.h>
#include <pthread.h>

#define SIZE 6

int array[SIZE] = {1, 2, 3, 4, 5, 6};
int sum1=0,sum2=0;

void* sum_part1(void* arg) {
    
    for (int i = 0; i < SIZE/2; i++) {
        sum1+=array[i];
    }

    return NULL;
}

void* sum_part2(void* arg) {
    
    for (int i= SIZE/2 ; i<SIZE ;i++) {
        sum2+=array[i];
    }

    return NULL;
}
int main(){
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,sum_part1,"HELLO FROM THREAD1 !");
	pthread_create(&t2,NULL,sum_part2,"HELLO FROM THREAD2 !");
	
	//wait for both threads to finish
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("Total sum=%d\n",sum1+sum2);
	return 0;
}

