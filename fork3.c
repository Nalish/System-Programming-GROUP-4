#include <stdio.h>
#include <unistd.h>

int main() {
    int id = fork();

    if (id == 0) {
        // Child process
        printf("The child process\n");
    } else {
        // Parent process
        printf("The main process\n");
    }

    if (id != 0) {
        // Only the parent process will fork again
        fork();
    }

    printf("Child process: %d\nParent process: %d\n", getpid(), getppid());
    return 0;
}
