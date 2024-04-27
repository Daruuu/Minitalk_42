/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/27 23:51:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 *	check number of args in client
 *	check in argv 2 no send a PID of server*/

static int	check_correct_args(int argc, char **argv)
{
	char	*chars_pid_server;
	int		i;

	chars_pid_server = "012456789";
	if (argc != 3)
	{
		ft_printf("number of args are incorrect!\n");
		return (-1);
	}
	i = 0;
	while (argv[1][i])
	{
		if (!(ft_strchr(chars_pid_server, argv[1][i])))
		{
			ft_printf("Invalid PID for server!\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

// Que queremos hacer: Comunicarnos con el servidor mediante señales para
// enviar un string.
void	send_char(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)// 30
			kill(pid, SIGUSR1);
		else	// 31
			kill(pid, SIGUSR2);
		// tiempo a esperar, para asegurar que la senyal sea manejada
		usleep(100);
		i--;
	}
}

int	check_length_message(char *str)
{
	int	length_message;

	length_message = ft_strlen(str);
	if (length_message > 0)
		return (length_message);
	return (-1);
}

char	*client (pid_t pidServer, char *strToSend)
{
	if (!strToSend)
		ft_printf("No Message to send!\n");
	else
		ft_printf("%ui\n", pidServer);
		ft_printf("%s\n", strToSend);

	return (0);
}

int	main (int argc, char **argv)
{
	int		lengthMessage;
	int		i;
	char	*message;
	pid_t	pidServer;

	if (check_correct_args(argc, argv) != 0)
		return (1);
	lengthMessage = check_length_message(argv[2]);
	if (lengthMessage < 0)
	{
		ft_printf("Invalid mmessage length!\n");
		return (1);
	}

	// SEND STRING TO SERVER VIA SIGUSER1-2 
	i = 0;
	message = argv[2];
	pidServer = ft_atoi(argv[1]);
	while (message[i] != '\0' && i <= lengthMessage)
	{
		send_char(pidServer, message[i]);
		i++;
	}
	return (0);
}
