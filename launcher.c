#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Uso: ./launcher <num_processos>\n", 33);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        write(2, "Número inválido de processos.\n", 30);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            // Cada processo filho executa o hello
            execl("./hello", "hello", NULL);
            write(2, "Erro no exec\n", 13);
            exit(1);
        } else if (pid < 0) {
            write(2, "Erro no fork\n", 13);
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}
