/*write a C program to generate and print the Fibonacci series up to a specified number of terms, 
the program should take the number of term as input from the user 
and the display the corresponding Fibonaccisequence*/

[2021ict89@fedora ~]$ touch fib.c
[2021ict89@fedora ~]$ vi fib.c
[2021ict89@fedora ~]$ chmod 777 fib.c
[2021ict89@fedora ~]$ gcc fib.c -o fib
[2021ict89@fedora ~]$ ./fib
Enter the number of terms: 5
Fibonacci Series: 0 1 1 2 3

#include <stdio.h>
void fibonacci(int n) {
    int first = 0, second = 1, next;   
    printf("Fibonacci Series: ");
    
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}
int main() {
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        fibonacci(terms);
    }
    return 0;
}
