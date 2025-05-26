//Give list of numbers then calculate the sum and multiplication on using for loop

[2021ict89@fedora ~]$ touch forLoop_sum.c
[2021ict89@fedora ~]$ vi forLoop_sum.c
[2021ict89@fedora ~]$ chmod 777 forLoop_sum.c
[2021ict89@fedora ~]$ gcc forLoop_sum.c -o forLoop_sum
[2021ict89@fedora ~]$ ./forLoop_sum
Enter the number of elements: 5
Enter 5 numbers:
1
2
3
4
5
Sum = 15
product = 120

#include <stdio.h>
int main() {
    int n, sum = 0, product = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        product *= numbers[i];
    }
    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);

    return 0;
}
