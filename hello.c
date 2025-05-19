#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <num_repeticoes>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Numero invalido de repeticoes.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("Repeticao %d: Hello World!\n", i);
    }

    return 0;
}
