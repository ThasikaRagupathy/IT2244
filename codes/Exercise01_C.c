//creating the c file
touch exercise01.c
vi exercise01.c
chmod 777 exercise01.c

//change the file permission
gcc exercise01.c -o exercise01

//run the file
./exercise01

//First exercise
#include <stdio.h>

int main(){
printf ("Hello world");
return 0;
}


