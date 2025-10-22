#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM 5
#define NUM1 2 /* Prima parte da inviare */
#define NUM2 3 /* Seconda parte da inviare */

int leggi_messaggio(int fd, void * msg, int size);

int main() {
    int fd[2];

    if (pipe(fd) < 0) {
        printf("Errore nella creazione pipe\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        printf("Errore nella fork\n");
        return 1;
    } else if (pid == 0) {
        /* Processo figlio */
        close(fd[0]); /* Non interessato a leggere */
        /* Prepara il messaggio */
        int i, messaggio[NUM];
        for (i = 0; i < NUM; i++) {
            printf("Inserisci il numero %d: ", i+1);
            scanf("%d", &messaggio[i]);
        }
        /* Invia il messaggio in due parti */
        int inviati1 = write(fd[1], & messaggio[0], NUM1 * sizeof(int));
        sleep(1);
        int inviati2 = write(fd[1], & messaggio[NUM1], NUM2 * sizeof(int));
        if (inviati1 + inviati2 != sizeof(messaggio)) {
            printf("Errore nell'invio!\n");
            return 1;
        }
        close(fd[1]);
        return 0;
    } else {
        /* Processo padre */
        close(fd[1]); /* Non interessato a scrivere */
        int messaggio[NUM];
        int ricevuti = leggi_messaggio(fd[0], & messaggio, sizeof(messaggio));
        if (ricevuti < sizeof(messaggio)) {
            printf("Errore nella ricezione!\n");
        } else {
            printf("Numeri ricevuti: ");
            int i;
            for (i = 0; i < NUM; i++)
                printf("%d ", messaggio[i]);
            printf("\n");
        }
        close(fd[0]);
        return 0;
    }
}
int leggi_messaggio(int fd, void * msg, int size) {
    /* Puntatore a byte per manipolare il messaggio */
    unsigned char * p = (unsigned char * ) msg;

    /* Numero totale di byte ricevuti */
    int tot_ricevuti = 0;

    /* Ripete finché il messaggio è completo */
    while (tot_ricevuti < size) {
        int ricevuti = read(fd, p, size - tot_ricevuti);
        /* Se non può ricevere altri byte, ritorna */
        if (ricevuti <= 0)
            return tot_ricevuti;
        tot_ricevuti += ricevuti;

        /* Avanza il puntatore al pezzo mancante del messaggio */
        p += ricevuti;
    }
    return tot_ricevuti;
}