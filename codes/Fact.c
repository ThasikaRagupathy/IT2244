//write a C program to Calculate tha factorial of the given non-negative integers

[2021ict89@fedora ~]$ touch fib.c
[2021ict89@fedora ~]$ vi fib.c
[2021ict89@fedora ~]$ chmod 777 fib.c
[2021ict89@fedora ~]$ gcc fib.c -o fib
[2021ict89@fedora ~]$ ./fib
Enter the number of terms: 5
Fibonacci Series: 0 1 1 2 3

#include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }
    return 0;
}
