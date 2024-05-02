/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/02 02:05:37 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_received_message = {0};

char	*print_message(int length, char c)
{
	char	*str;
	int		i;

	if (g_received_message == NULL)
	{
		g_received_message = malloc(sizeof(char *) * length);
		if (!g_received_message)
		{
			ft_printf("Error malloc failed!\n");
			exit(EXIT_FAILURE);
		}
		g_received_message[0] = '\0';
	}

	str = malloc(sizeof(char *) * length);
	if (!str)
	{
		ft_printf("error al crear malloc!");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i] != '\0')
	{
		// ADD NEW FUNCTION
		i++;
	}
	return (0);
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

int	main(void)
{
	char	*message;
	int		total_message;

	ft_printf("Welcome to my SERVER\n");
	ft_printf("The server is UP and running.\n");
	ft_printf("The PID of server is: %d\n", getpid());
	signal(SIGUSR1, signals_handle);
	signal(SIGUSR2, signals_handle);
	//if ()
	total_message = get_length_message();
	//message = print_message(total_message, );
	while (1)
		usleep(100);
		/*pause();*/
	return (0);
}
