(01)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16

char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";


int main(){
	char inbuf[MSGSIZE];
	int p[2],i;
	
	if(pipe(p)<0)
		exit(1);
	
	/*continued
	write pipe*/
	
	write(p[1], msg1,MSGSIZE); //write(file descriptor ,message,message size)
	write(p[1], msg2,MSGSIZE);
	write(p[1], msg3,MSGSIZE);
	
	for(i=0;i<3;i++){
		//read pipe
		read(p[0],inbuf,MSGSIZE); //read(fildes,msg,msgsize)
		printf("%s\n",inbuf);
	}
	return 0;
}
[2021ict89@fedora ~]$ vi pipe.c
[2021ict89@fedora ~]$ chmod 777 pipe.c
[2021ict89@fedora ~]$ gcc pipe.c -o pipe
[2021ict89@fedora ~]$ ./pipe
hello, world #1
hello, world #2
hello, world #3

===================================================================================================================================================
(02)
1. get 2 inputs from users(//parent process)
name:
regno:
age:
2. print the output from the child(//child process)

name:tikku
regno:2021ict89
age:23

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char name[50];
    char regno[20];
    int age;

    // Taking input in the parent process
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Reg No: ");
    scanf("%s", regno);
    printf("Enter Age: ");
    scanf("%d", &age);

    pid_t pid = fork();  // Creating the child process

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) { // Child process
        printf("\nChild Process Output:\n");
        printf("Name: %s\n", name);
        printf("Reg No: %s\n", regno);
        printf("Age: %d\n", age);
    }
    else { // Parent process
        wait(NULL); // Wait for child to finish
        printf("\nParent Process Completed!\n");
    }

    return 0;
}

[2021ict89@fedora ~]$ vi exer.c
[2021ict89@fedora ~]$ chmod 777 exer.c
[2021ict89@fedora ~]$ gcc exer.c -o exer
[2021ict89@fedora ~]$ ./exer
Enter Name: Tikku
Enter Reg No: 2021ict89
Enter Age: 23

Child Process Output:
Name: Tikku
Reg No: 2021ict89
Age: 23

Parent Process Completed!
===================================================================================================================================================
