//exercise

IPC using message queue

read inputs from the parent process
Enter Name: Tikku
Enter regNo: 2021ICT89
Enter Age: 23

Message sent successfully.

give the output from the child process

Recieved Name: Tikku
Recieved regNo: 2021ICT89
Recieved Age:23

//send
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_NAME_LEN 100
#define MAX_REGNO_LEN 100

struct msg_buffer {
    long msg_type;
    char name[MAX_NAME_LEN];
    char regNo[MAX_REGNO_LEN];
    int age;
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate unique key
    key = ftok("details", 89);

    // Create message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }

    // Parent process: Sending message
    message.msg_type = 1;
    printf("Enter Name: ");
    scanf("%s", message.name);
    printf("Enter regNo: ");
    scanf("%s", message.regNo);
    printf("Enter Age: ");
    scanf("%d", &message.age);

    if (msgsnd(msgid, &message, sizeof(message) - sizeof(long), 0) == -1) {
        perror("msgsnd failed");
        exit(EXIT_FAILURE);
    }
    printf("\nMessage sent successfully.\n");

    // Child process: Receiving message
    if (msgrcv(msgid, &message, sizeof(message) - sizeof(long), 1, 0) == -1) {
        perror("msgrcv failed");
        exit(EXIT_FAILURE);
    }
    
    printf("\nReceived Name: %s\n", message.name);
    printf("Received regNo: %s\n", message.regNo);
    printf("Received Age: %d\n", message.age);

    // Destroy message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
