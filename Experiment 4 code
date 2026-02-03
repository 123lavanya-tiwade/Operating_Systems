#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Parent started\n");
    printf("Parent PID: %d\n\n", getpid());

    // Child 1
    pid = fork();
    if (pid == 0) {
        printf("Child 1 PID: %d | Parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 2
    pid = fork();
    if (pid == 0) {
        printf("Child 2 PID: %d | Parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 3
    pid = fork();
    if (pid == 0) {
        printf("Child 3 PID: %d | Parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    // Child 4
    pid = fork();
    if (pid == 0) {
        printf("Child 4 PID: %d | Parent PID: %d\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);

    printf("\nAll child processes finished in sequence\n");
    printf("Parent exiting\n");

    return 0;
}
