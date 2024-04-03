/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:23:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/03 21:35:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf/ft_printf.h"
#include "minitalk.h"
/*
int	main(void)
{
	//ft_printf("hello world");
	//ft_printf("my rocess ID is %d\n", getpid());
	//printf("my process ID is %d\n", getpid());
	//server();

	exit (0);
}
*/

// funcion que captura una senal que se envia cuando se pulsa Ctrl C y la
// ignore
/*
 * controlador para Ctrl-C
 * indica en pantalla que no se quiere salir y pone el controlador por defecto
 * para Ctrl-C
*/

/*
void	controlador(int numberSignal)
{
	ft_printf("no se sale\n");
	ft_printf("try again\n");
	// se pone controlador por default
	signal(SIGINT, SIG_DFL);
}
*/

/*
int	main()
{
	// si cambia el controlador para ctrl-c, escribiendo error por pantalla
	// si que hay 
	if (signal(SIGINT, controlador) == SIG_ERR)
	{
		ft_printf("no se puede cambiar signal\n");
		exit (EXIT_FAILURE);
	}
	loop infinito de espera, pause() deja el proceso dormido hasta que
	llegue una signal
	while (1)
		pause ();

	return (0);
}
*/
/*
 * ejemplo de como un procesos peude eviar una senal a otro proceso mediante
 * kill()
*/
//programam principal
// crear un proceso hijo y le envie una senyal SIGUSR1 cada segundo

int	main()
{
	// id del proceso hijo
	pid_t	idProceso;

	// se crea el proceso jhijo y se comprueba el error
	idProceso = fork();
	if (idProceso == -1)
	{
		ft_printf("no se puede lanzar procesos\n");
		exit(-1);
	}

	return (0);
}





