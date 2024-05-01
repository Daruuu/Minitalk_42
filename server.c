/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/01 11:51:02 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
// SE DESPLAZA UN BIT A LA IZQUIERDA multiplica x 2
// SE INTRODUCE UN 0 EN LA DERECHA
void	handle_sigusr1(int signum)
{
	char	received_char;
	
	received_char = 0;
	received_char <<= 1;
}
// SE DESPLAZA UN BIT A LA DERECHA divide entre 2
// SE INTRODUCE UN 1 EN LA DERECHA
void	handle_sigusr2(int signum, char received_char)
{
	received_char <<= 1;
	received_char |= 1;
}

// recoge la longitd que he pasado del cliente al servidor
// para comparar la longitud recibida con la longitud que recibo
void	get_length_message()
{

}

// convertir los bits que envio del cliente hacia el servidor
// y aqui comprobar la longitud del cliente con el servidor
int	binary_to_char(int **ptr)
{
	static char received_char = 0;
	handle_sigusr1(SIGUSR1);
	handle_sigusr1(SIGUSR2);

	return (0);
}
*/
void	signals_handle(int signal)
{
	static int	i;
	static int	c;
	int			nb;

	if (signal == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	c = (c << 1) + nb;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	received_data_from_server()
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
	static char received_char = 0;

    // Configuracion del tratamiento de las señales SIGUSR1 y SIGUSR2.
    //signal(SIGUSR1, handle_sigusr1);
    //signal(SIGUSR2, handle_sigusr2);
	//server();
	signal(SIGUSR1, signals_handle);

	while (1)
		usleep(100);
	return (0);
}
