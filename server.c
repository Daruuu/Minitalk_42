/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/03 13:33:48 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_message = {0};

void	signal_handle_message(int signum)
{
	static int	c;
	static int	i;
	int			nb;

	if (signum == SIGUSR2)
		nb = 0;
	else
		nb = 1;
	c = (c << 1) + nb;
	i++;
	if (i == 8)
	{
		g_message.content[g_message.index] = c;
		g_message.index = g_message.index + 1;
		if (g_message.index == g_message.length)
		{
			g_message.content[g_message.index] = '\0';
			ft_printf("message: %s\n", g_message.content);
			g_message.index = 0;
			g_message.length = 0;
		}
		i = 0;
		c = 0;
	}
}

int	get_length_message(void)
{
	int		length;
	int		i;

	length = 0;
	length = (length << 1) + 1;
	if (++i == 32)
	{
		length = 0;
		i = 0;
		return (length);
	}
	return (-1);
}

void	signal_handle_length(int signum)
{
	static int	i;
	int			nb;

	if (signum == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	g_message.length = (g_message.length << 1) + nb;
	i++;
	if (i == 32)
	{
		signal(SIGUSR1, signal_handle_message);
		signal(SIGUSR2, signal_handle_message);
		ft_printf("length message SERVER: %d\n", g_message.length);
		g_message.content = malloc(sizeof(char *) * (g_message.length + 1));
		i = 0;
	}
}

int	main(void)
{
	char	*message;
	int		total_message;

	ft_printf("Welcome to my SERVER\n");
	ft_printf("The server is UP and running.\n");
	ft_printf("The PID of server is: %d\n", getpid());
	signal(SIGUSR1, signal_handle_length);
	signal(SIGUSR2, signal_handle_length);
	while (1)
		usleep(TIME_WAITING);
	return (0);
}
