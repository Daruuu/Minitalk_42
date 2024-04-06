/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/06 11:57:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	server();

	return (0);
}
