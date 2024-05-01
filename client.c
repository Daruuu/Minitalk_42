/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/01 11:37:16 by dasalaza         ###   ########.fr       */
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

void	send_char(int pid, char c)
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
		usleep(TIME_WAITING);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*message_to_send;
	int		length_message;
	int		*count_chars;

	message_to_send = argv[2];
	count_chars = 0;
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
		//ft_printf("%d\n", count_chars);
	}
	else
		ft_printf("number of args are incorrect!\n");
	return (0);
}
