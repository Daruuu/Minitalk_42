#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Señal SIGINT (%d) capturada. No se terminará el proceso.\n", signum);
}

int	main() {
    struct sigaction act;
    act.sa_handler = sigint_handler; // Establece el manejador de SIGINT
    sigemptyset(&act.sa_mask);       // Inicializa el conjunto de señales a bloquear durante la ejecución del manejador en vacío
    act.sa_flags = 0;                // Ninguna bandera especial

    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        printf("Esperando por SIGINT (Ctrl+C).\n");
        sleep(1);
    }
    return 0;
}
