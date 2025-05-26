//if else
	
if(condition){
	//body of if statement
}
else{
	//body of the else statement
}
#Exercise
//Enter your age and verify you are eligible or not for the election voting



[2021ict89@fedora ~]$ touch IfElse.c
[2021ict89@fedora ~]$ vi IfElse.c
[2021ict89@fedora ~]$ chmod 777 IfElse.c
[2021ict89@fedora ~]$ gcc IfElse.c -o IfElse
[2021ict89@fedora ~]$ ./IfElse
Enter your current age: 23
You're Eligible for the voting

//CODE
#include<stdio.h>
int main(){

int age;
printf("Enter your current age: ",age);
scanf("%d", &age);

if(age>=18){
	printf("You're Eligible for the voting\n");
}
else if(age=0){
	printf("Invalid Input\n");
}
else{
	printf("You're Not Eligible for the voting\n");
}
return 0;
}
