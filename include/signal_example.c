#include <stdio.h>
#include <signal.h>
#include <unistd.h>


/**
funcion manejadora de la senyal
*/
void	handle_sigint(int sig)
{
	printf("Capturada SIGINT (%d)\n", sig);

	signal(SIGINT, SIG_DFL);
}

int	main()
{
	// establecemos la funcion HANDLE_SIGINT como manejador de SIGINT
	signal(SIGINT, handle_sigint);

	// un loop infinito para mantener el programa en ejecucion
	while (1)
	{
		printf("esperando la senyal de SIGINT. Presiona Ctrl+C para enviarla.\n");
		sleep(1);	// sleep para reducir el uso de la CPU
	}
	return (0);
}
