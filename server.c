/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/29 12:00:17 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
static char character = '0';
static int bitpos = 7;

void	handle_sigusr1(int signum)
{
	static int	bit;

}

void	handle_sigusr2(int signum)
{

}
// esta funcion recoge la longitd que he pasado del cliente al servidor
// para comparar la longitud recibida con la longitud que recibo
void	get_length_message()
{

}
// convertir los bits que envio del cliente hacia el servidor
// y aqui comprobar la longitud del cliente con el servidor:x
//
int	binary_to_char(int **ptr)
{

	return (0);
}

void	server()
{
	pid_t	server_pid;

	server_pid = getpid();
	//printf("%d\n", server_pid);
	if (!server_pid)
	{
		ft_printf("%s\n", "PID NOT FOUND");
		exit(-1);
	}
	ft_printf("PID of Server: %d\n", server_pid);
}

int	main()
{
    // Configuracion del tratamiento de las señales SIGUSR1 y SIGUSR2.
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
	server();
	return (0);
}
