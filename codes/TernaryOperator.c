//Ternary operator
test_condition ? expression1 : expression2;

[2021ict89@fedora ~]$ touch IfElse.c
[2021ict89@fedora ~]$ vi IfElse.c
[2021ict89@fedora ~]$ chmod 777 IfElse.c
[2021ict89@fedora ~]$ gcc IfElse.c -o IfElse
[2021ict89@fedora ~]$ ./IfElse
Enter your current age: 26
You're Eligible

#include<stdio.h>
int main(){

int age;
printf("Enter your current age: ",age);
scanf("%d", &age);

(age>=18?printf("You're Eligible"):printf("You're Not Eligible\n"));

return 0;
}
