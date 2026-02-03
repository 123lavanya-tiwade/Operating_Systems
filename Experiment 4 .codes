#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Parent process started\n");
    printf("Parent PID is %d\n\n", getpid());

    // Child 1
    pid = fork();
    if (pid == 0) {
        printf("HI ! I am child 1 and my PID is %d. || My parent PID is %d\n",
               getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 2
    pid = fork();
    if (pid == 0) {
        printf("HI ! I am child 2 and my PID is %d. || My parent PID is %d\n",
               getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 3
    pid = fork();
    if (pid == 0) {
        printf("HI ! I am child 3 and my PID is %d. || My parent PID is %d\n",
               getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 4
    pid = fork();
    if (pid == 0) {
        printf("HI ! I am child 4 and my PID is %d. || My parent PID is %d\n",
               getpid(), getppid());
        exit(0);
    }
    wait(NULL);
    
    //child 5
    pid = fork();
    if (pid == 0) {
        printf("HI ! I am child 5 and my PID is %d. || My parent PID is %d\n",
               getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    printf("\nAll child processes have finished execution\n");
    printf("Parent process exiting\n");

    return 0;
}
