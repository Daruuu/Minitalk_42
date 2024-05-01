/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/01 18:19:34 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_correct_args(char **argv)
{
	int		i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printf("Invalid PID for server!\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

//SIGUSR2 = 1
//SIGUSR1 = 0
void	send_length_message_to_server(int pid_server, int num)
{
	int	i;

	i = sizeof(int) * 8 - 1;
	if (num > 0)
	{
		while (i >= 0) 
		{
			if ((num >> i) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			usleep(100);
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*message_to_send;
	int		length_message;
	int		pid_server;

	i = 0;

	if (argc == 3)
	{
		check_correct_args(argv);
		message_to_send = argv[2];
		length_message = ft_strlen(message_to_send);
		pid_server = ft_atoi(argv[1]);
		if (length_message > 0)
			send_length_message_to_server(pid_server, length_message);
		ft_printf("LENGTH MESSAGE => %d\n", length_message);
		while (message_to_send[i] != '\0')
		{
			send_char(pid_server, message_to_send[i]);
			i++;
		}
	}
	else
		ft_printf("number of args are incorrect!\n");
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int		i;
	char	*message_to_send;
	int		length_message;

	message_to_send = argv[2];
	i = 0;
	if (argc == 3)
	{
		length_message = ft_strlen(message_to_send);
		check_correct_args(argv);
		ft_printf("LENGTH MESSAGE => %d\n", length_message);
		while (message_to_send[i] != '\0')
		{
			send_char(ft_atoi(argv[1]), message_to_send[i]);
			i++;
		}
	}
	else
		ft_printf("number of args are incorrect!\n");
	return (0);
}
*/
