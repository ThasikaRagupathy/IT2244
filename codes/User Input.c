//getting user inputs

#include<stdio.h>
int main(){
	
	int age;
	double number;
	char alpha;

    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Age = %d\n", age);
	
    printf("Enter double input: ");
    scanf("%lf", &number);
    printf("Number is = %lf\n", number);
	
   
    printf("Enter char input: ");
    scanf(" %c", &alpha);  //new line input buffer
    printf("Char is = %c\n", alpha);
	
    return 0;
}
