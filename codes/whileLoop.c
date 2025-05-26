//print the int from 1 to 10 using while loop

[2021ict89@fedora ~]$ touch while.c
[2021ict89@fedora ~]$ vi while.c
[2021ict89@fedora ~]$ chmod 777 while.c
[2021ict89@fedora ~]$ gcc while.c -o while
[2021ict89@fedora ~]$ ./while
1
2
3
4
5
6
7
8
9
10

#include <stdio.h>
int main() {
    int i = 1;

    while (i <= 10) {
        printf("%d\n", i);
        i++; 
    }
    return 0;
}
