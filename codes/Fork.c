//FORK
[2021ict89@fedora ~]$ touch fork.c
[2021ict89@fedora ~]$ vi fork.c
[2021ict89@fedora ~]$ chmod 777 fork.c
[2021ict89@fedora ~]$ gcc fork.c -o fork
[2021ict89@fedora ~]$ ./fork
Hello World
Hello World

#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
	printf("Hello World\n");	
	return 0;
}

--------------------------------------------------------------------------------------
//parent child
[2021ict89@fedora ~]$ vi fork.c
[2021ict89@fedora ~]$ gcc fork.c -o fork
[2021ict89@fedora ~]$ ./fork
I am parent
I am child

#include<stdio.h>
#include<unistd.h>
int main()
{
    int id=fork();
	if(id==0)
	{
	   printf("I am child\n");
	}	
	else{
		printf("I am parent\n");
	}
	return 0;
}
--------------------------------------------------------------------------------------
//print numbers from 1 to 10 and
//1 to 5 should print by child process and
//from 6 to 10 should be parent process
//calculate sum of those numbers
[2021ict89@fedora ~]$ vi fork.c
[2021ict89@fedora ~]$ gcc fork.c -o fork
[2021ict89@fedora ~]$ ./fork
Parent process:
6
7
8
9
10
Parent sum: 40
Child process:
1
2
3
4
5
Child sum: 15

#include <stdio.h>
#include <unistd.h>

int main() {
    int id = fork();
    int Csum = 0;
    int Psum = 0;
	
    if (id == 0) 
	{
        printf("Child process:\n");
        for (int i = 1; i <= 5; i++) 
		{
            printf("%d\n", i);
            Csum += i;
        }
        printf("Child sum: %d\n", Csum);
    } 
	 
        printf("Parent process:\n");
        for (int i = 6; i <= 10; i++) 
		{
            printf("%d\n", i);
            Psum += i;
        }
        printf("Parent sum: %d\n", Psum);
		
	printf("Total sum (Child + Parent): %d\n", Psum+Csum);
    return 0;
}
--------------------------------------------------------------------------------------
