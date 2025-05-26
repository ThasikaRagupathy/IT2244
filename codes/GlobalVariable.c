/* X AND Y CHILD ,
Get 3 numbers as input A B C 
then in child X find the factorial of the A from user input
and for Y child find Fibonacci for varibale B
and check C primeNumber or not
(using Global variable)*/
     
[2021ict89@fedora ~]$ vi globalvar.c
[2021ict89@fedora ~]$ gcc globalvar.c -o globalvar
[2021ict89@fedora ~]$ ./globalvar
Enter the number (X:) 10
Enter the number (Y:) 5
Enter the number (Z:) 7
Process A (Parent) PID: 15887
Process B (Child 1) PID: 15903, Parent PID: 15887
Factorial of 10 is 3628800
Process C (Child 2) PID: 15904, Parent PID: 15887
Fibonacci series of 5 : Fibonacci series: 0 1 1 2 3
7 is a prime number.
	 
#include<stdio.h>
#include <unistd.h>//for sleep

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series: %d %d", a, b);
    for (int i = 2; i < n; i++) {
        next = a + b;
        printf(" %d", next);
        a = b;
        b = next;
    }
    printf("\n");
}

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) 
		return 0;
    }
    return 1;
}


int main(){
	
	int X, Y, Z;
    printf("Enter the number (X:) ");
    scanf("%d", &X);
	
	printf("Enter the number (Y:) ");
    scanf("%d", &Y);
	
	printf("Enter the number (Z:) ");
    scanf("%d",&Z);
	
	
    int f1, f2;
    int p = getpid();
    printf("Process A (Parent) PID: %d\n", p);

    f1 = fork();  

    if (f1 == 0) {
       
        printf("Process B (Child 1) PID: %d, Parent PID: %d\n", getpid(), getppid());
		printf("Factorial of %d is %d\n", X, factorial(X));
    } else {
       
        f2 = fork();

        if (f2 == 0) {
            
            printf("Process C (Child 2) PID: %d, Parent PID: %d\n", getpid(), getppid());
			printf("Fibonacci series of %d : ", Y);
			fibonacci(Y);
			if (is_prime(Z)) {
                printf("%d is a prime number.\n", Z);
            } else {
                printf("%d is not a prime number.\n", Z);
            }			
        }
    }

    return 0;
}
