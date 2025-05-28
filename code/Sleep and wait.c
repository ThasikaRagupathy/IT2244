01.

#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> //for sleep()

int main()
{
	printf("Program Started.\n");
	
	printf("Sleeping for 3 seconds....\n")
	sleep(3);//pause for 3 seconds
	
	printf("Exiting the program\n");
	exit(0);//clean exit
	return 0;
}

[2021ict89@fedora ~]$ vi ex1.c
[2021ict89@fedora ~]$ chmod 777 ex1.c
[2021ict89@fedora ~]$ gcc ex1.c -o ex1
[2021ict89@fedora ~]$ ./ex1
Program Started.
Sleeping for 3 seconds....
Exiting the program

--------------------------------------------------------------------------------------------------------
02.

#include <stdio.h>
#include <stdlib.h> //for exit()
#include <unistd.h> //for sleep(),fork()
#include <sys/wait.h> //wait()

int main()
{
	pid_t pid;
	printf("parent process started. PID: %d\n",getpid());
	
	pid=fork();// create new child process
	
	if(pid<0)
	{
		perror("fork failed");
		exit(1);
	}
	
	if(pid==0)
	{
		//child process
		printf("Child process. PID %d,Sleeping for 2 seconds...\n",getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0);//child exit with 0 status
	}
	else
	{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);//wait for child to finish
		if(WIFEXITED(status))//returns true if the child exited normally
		{
			printf("Child exitesd with status: %d\n",WEXITSTATUS(status));//extracts the actual exit code of the child
		}
		else
		{
			printf("Child didn't exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}
[2021ict89@fedora ~]$ vi ex1.c
[2021ict89@fedora ~]$ gcc ex1.c -o ex1
[2021ict89@fedora ~]$ ./ex1
parent process started. PID: 10753
Parent waiting for child to finish...
Child process. PID 10754,Sleeping for 2 seconds...
Child process exiting.
Child exitesd with status: 0
Parent process ending.

--------------------------------------------------------------------------------------------------------
03.
/*First child: slept for 1 seconds
Second child: slept for 3 seconds
parent: both children have finished*/

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 

int main()
{
	pid_t pid,first_child,second_child;
	printf("parent process started. PID: %d\n",getpid());
	
	first_child=fork();
	if(first_child==0)
	{
		printf("Child process. PID %d,Sleeping for 1 seconds...\n",getpid());
		sleep(1);
		printf("Child process exiting.\n");
		exit(0);
	}
	second_child=fork();
	if(second_child==0)
	{
		printf("Child process. PID %d,Sleeping for 3 seconds...\n",getpid());
		sleep(3);
		printf("Child process exiting.\n");
		exit(0);

	}	
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Child exitesd with status: %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("Child didn't exit normally.\n");
		}
		wait(NULL);
		wait(NULL);
		printf("Parent: both children have finished\n");
	
	return 0;
}
[2021ict89@fedora ~]$ vi ex1.c
[2021ict89@fedora ~]$ gcc ex1.c -o ex1
[2021ict89@fedora ~]$ ./ex1
parent process started. PID: 12700
Parent waiting for child to finish...
Child process. PID 12701,Sleeping for 1 seconds...
Child process. PID 12702,Sleeping for 3 seconds...
Child process exiting.
Child exitesd with status: 0
Child process exiting.
Parent: both children have finished

--------------------------------------------------------------------------------------------------------