/* Esercizio 5: Pipe Unix
๏ Scrivere un programma che crea una pipe anonima, dopodiché crea un
processo figlio
๏ Il processo padre crea 50 struct che contengono coordinate reali (x,y,z) e
le invia una alla volta al processo figlio tramite la pipe. Le coordinate
devono essere settate come: x = i; y = i*2; z = 3*i/2 con i=0,…,49.
๏ Il processo figlio legge dalla pipe le stuct inviate dal padre e le stampa.
๏ Nella lettura, gestire il fatto che il messaggio sia incompleto
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 50

typedef struct {
    float x;
    float y;
    float z;
} Tcoordinate;

int main (int argc, char* argv[]){
    int fd[2], sent, received;
    pid_t pid;

    if(pipe(fd) < 0){
        fprintf(stderr, "Pipe Error");
        exit (1);
    }
    pid = fork();

    if (pid < 0){
        fprintf(stderr, "Fork Error!");
        exit(1);
    }
    else if (pid == 0){
        Tcoordinate coordinate;
        //child process
        printf("CHILD: My PID = %d, My parent PID = %d, returned PID = %d\n", getpid(), getppid(), pid);
        close(fd[1]); //close pipe input

        for (unsigned int i = 0 ; i < N ; i++){
            int received = (int) read(fd[0], &coordinate, sizeof(coordinate));
            if (received < 0) {
                fprintf(stderr, "Reading Error!");
                exit(1);
            }
            else if (received < sizeof(coordinate))
                puts("Partial message!");
            else 
                printf("Reading...\t x = %.2f, y = %.2f, z = %.2f\n", coordinate.x, coordinate.y, coordinate.z);
        }
        close(fd[0]); //close pipe output
        exit(0);
    }
    else {
        Tcoordinate coordinate;
        //parent process
        close(fd[0]); //pipe read close
        printf("PARENT: My PID = %d, My parent PID = %d, returned PID = %d\n", getpid(), getppid(), pid);

        for (unsigned int i = 0 ; i < N ; i++){
            coordinate.x = i;
            coordinate.y = 2*i;
            coordinate.z = 3/2 * i;
            printf("Writing...\t x = %.2f, y = %.2f, z = %.2f\n", coordinate.x, coordinate.y, coordinate.z);
            sent = (int) write(fd[1], &coordinate, sizeof(coordinate));
            if (sent != sizeof(coordinate)){
                fprintf(stderr, "Writing Error");
                exit(1);
            }
            sleep(1);
        }
        close(fd[1]);
        exit(0);
    }
}