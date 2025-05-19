#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <num_processos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Número inválido de processos.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Processo filho
            char reps[10];
            sprintf(reps, "%d", i * 2); // Cada processo repete i*2 vezes

            execl("./hello", "hello", reps, NULL);
            perror("exec");
            exit(1);
        } else if (pid < 0) {
            perror("fork");
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}
