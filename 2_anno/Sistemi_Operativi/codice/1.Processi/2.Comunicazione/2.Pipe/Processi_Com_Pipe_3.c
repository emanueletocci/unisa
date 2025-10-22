#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 10

int main() {
    int fd[2], i, n, message;

    if (pipe(fd) < 0) {
        printf("Pipe creation error\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid<0) {
        printf("fork error\n");
        return 1;

    } else if (pid == 0) {
        // Child process
        close(fd[0]); // Close read pipe
        // Compose message
        puts("Inserire un numero: \n");
        scanf("%d", &message);
        int sent = (int)write(fd[1], &message, sizeof(message));
        if (sent != sizeof(message)) {
            printf("Sending error!\n");
            return 1;
        }
        close(fd[1]);
        return 0;
    } else {
        // Father process
        close(fd[1]); // Close write pipe
        int received = (int)read(fd[0], &message, sizeof(message));
        if (received < 0) {
            printf("Receiving error!\n");
        } else {
            if (received < sizeof(message))
                printf("Messagge incomplete!\n");
            // verify bytes received
            n = received/(int)sizeof(int);
            printf("Ho ricevuto: %d ", message);
            printf("\n");
        }
        close(fd[0]);
        return 0;
    }
}
