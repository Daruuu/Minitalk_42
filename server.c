/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/01 18:48:57 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_message(int length, char c)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char *) * length);
	if (!str)
	{
		ft_printf("error al crear malloc!");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i] != '\0')
	{

		i++;
	}

	return (0);
}

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
		//ft_printf("")
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to my SERVER\n");
	ft_printf("The server is UP and running.\nThe PID of server is: %d\n", getpid());
	signal(SIGUSR1, signals_handle);
	signal(SIGUSR2, signals_handle);
	//if ()
	while (1)
		usleep(10);
		//pause();
	return (0);
}
