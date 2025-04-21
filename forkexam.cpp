#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// This function demonstrates the use of fork()
void forkexample() {
    int p;
    p = fork();

    if (p == 0) {
        // Code executed by the child process
        printf("Hello from child!\n");
        printf("I am the child process having PID %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
    } else {
        // Code executed by the parent process
        wait(NULL); // Wait for the child process to terminate
        printf("Hello from parent!\n");
        printf("I am the parent process having PID %d\n", getpid());
        printf("My child PID is %d\n", p);
    }
}

// Main function to call forkexample()
int main() {
    forkexample();
    return 0;
}
