/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/25 09:56:38 by dasalaza         ###   ########.fr       */
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
