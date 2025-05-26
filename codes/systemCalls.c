//system calls-1
[2021ict89@fedora ~]$ touch systemCall.c
[2021ict89@fedora ~]$ vi systemCall.c
[2021ict89@fedora ~]$ chmod 777 systemCall.c
[2021ict89@fedora ~]$ gcc systemCall.c -o systemCall
[2021ict89@fedora ~]$ ./systemCall

the pid is 
the fork is 

#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nHello world");
	int f=fork();
	int p=getpid();
	printf("\n the pid is %d",p);
	printf("\n the fork is %d",f);
	
	return 0;
}

---------------------------------------------------------------------------------------------
/*fork()*/
[2021ict89@fedora ~]$ touch systemCall.c
[2021ict89@fedora ~]$ vi systemCall.c
[2021ict89@fedora ~]$ chmod 777 systemCall.c
[2021ict89@fedora ~]$ gcc systemCall.c -o systemCall
[2021ict89@fedora ~]$ ./systemCall

Hello world

Hello world

Hello world
Hello world

#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	fork();
	printf("\nHello world\n");
	return 0;
}

---------------------------------------------------------------------------------------------
//print only 1 for each parent and child
[2021ict89@fedora ~]$ touch systemCall.c
[2021ict89@fedora ~]$ vi systemCall.c
[2021ict89@fedora ~]$ chmod 777 systemCall.c
[2021ict89@fedora ~]$ gcc systemCall.c -o systemCall
[2021ict89@fedora ~]$ ./systemCall

I am the parent process
I am the child process

#include<stdio.h>
#include<unistd.h>
int main()
{
    int f = fork();

    if (f == 0) {
        printf("\nI am the child process\n");
    } else {
        printf("\nI am the parent process");
    }
    return 0;
}

---------------------------------------------------------------------------------------------
//print one parent process and two child processes for the parent process
[2021ict89@fedora ~]$ vi systemCall.c
[2021ict89@fedora ~]$ gcc systemCall.c -o systemCall
[2021ict89@fedora ~]$ ./systemCall

A (Parent process)
I'm A my ID is 24467
I'm A my parent ID is 2151
B (Child of A)
I'm B my parent ID is 24467
C (Child of A)
I'm C my parent ID is 24467

#include<stdio.h>
#include<unistd.h>

int main() {

    printf("\nA (Parent process)\n");
        printf("I'm A my ID is %d\n",getpid());
        printf("I'm A my parent ID is %d\n",getppid());
		
    int f1 = fork();
    if (f1 == 0) {
        printf("B (Child of A)\n");
                printf("I'm B my parent ID is %d\n",getppid());
    } else {
        int f2 = fork();
        if (f2 == 0) {
            printf("C (Child of A)\n");
                        printf("I'm C my parent ID is %d\n",getppid());
        }
    }
    return 0;
}
---------------------------------------------------------------------------------------------
