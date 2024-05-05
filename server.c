/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/05 20:26:54 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_message = {0};
void	signal_handle_length(int signum);

void	reset_structure(void)
{
	free(g_message.content);
	g_message.index = 0;
	g_message.length = 0;
}

void	reset_variables(int *c, int *i)
{
	*c = 0;
	*i = 0;
}

void	signal_handle_message(int signum)
{
	static int	c;
	static int	i;
	int			nb;

	if (signum == SIGUSR1)
		nb = 0;
	else
		nb = 1;
	c = (c << 1) + nb;
	i++;
	if (i == 8)
	{
		g_message.content[g_message.index] = c;
		g_message.index++;
		if (g_message.index == g_message.length)
		{
			g_message.content[g_message.index] = '\n';
			ft_printf("%s", g_message.content);
			reset_structure();
			signal(SIGUSR1, signal_handle_length);
			signal(SIGUSR2, signal_handle_length);
		}
		reset_variables(&i, &c);
	}
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
		g_message.content = malloc(sizeof(char) * (g_message.length + 1));
		if (!g_message.content)
		{
			free(g_message.content);
			ft_printf("Error creating MALLOC of message!");
			exit(EXIT_FAILURE);
		}
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Welcome to my SERVER\nThe server is UP and running.\n");
	ft_printf("The PID of server is: %d\n", getpid());
	signal(SIGUSR1, signal_handle_length);
	signal(SIGUSR2, signal_handle_length);
	while (1)
		usleep(80);
	return (0);
}
