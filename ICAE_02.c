#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int is_vowel(char ch){
        ch=tolower(ch);
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
int comapre(const void *a,const void *b){
        return strcmp(*(char **)a,*(char **)b);
}
int main(){
        int shmid1 ,shmid2;
        char(*words)[MAX_LEN];
        int *vowel_count;

        shmid1=shmget(IPC_PRIVATE,MAX_WORDS * MAX_LEN,IPC_CREAT | 0666);
        if(shmid1<0){
                perror("shmget");
                exit(1);
        }
        words=shmat(shmid1,NULL,0);

        shmid2=shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT | 0666);
        if(shmid2<0){
                perror("shmget");
                exit(1);
        }
        vowel_count=shmat(shmid2,NULL,0);
        int n;
        printf("Enter number of words: ");
        scanf("%d",&n);
        getchar();
        printf("Enter %d words:\n",n);
        for(int i=0;i<n;i++)
        {
                scanf("%s",words[i]);
        }
        pid_t child_pid=fork();
         if(child_pid==0)//child process
        {
                printf("Child process ID: %d, Parent ID: %d\n",getpid(),getppid());

                qsort(words,n,MAX_LEN,(int (*)(const void*,const void*))strcmp);
                pid_t grandchild_pid=fork();
                if(grandchild_pid==0)//grandchild process
                {
                        printf("Grandchild process ID: %d, Parent ID: %d\n",getpid(),getppid());

                        int count=0;
                        for(int i=0;i<n;i++)
                        {
                                if(is_vowel(words[i][0]))
                                        count++;
                        }
                        *vowel_count=count;
                        exit(0);
                        }
                        else{
                                wait(NULL); //wait for grandchild
                                exit(0);
                        }
                }
                else{
                        wait(NULL); //wait for child
                        printf("parent processID: %d\n",getpid());

                        printf("Sorted words:\n");
                        for(int i=0;i<n;i++)
                        {
                                printf("%s\n",words[i]);
                        }
                        printf("Number of words starting with vowels :%d\n", *vowel_count);

                        shmdt(words);
                        shmdt(vowel_count);
                        shmctl(shmid1,IPC_RMID,NULL);
                        shmctl(shmid2,IPC_RMID,NULL);
                }
        return 0;
}
