/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/13 20:33:22 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 *	check number of args in client
 *	check in argv 2 no send a PID of server
 */
int	check_correct_args(int argc, char **argv)
{
	pid_t	pid;
	char	str;

	if (argc != 3)
	{
		ft_printf("number of args is incorrect!");
		return (1);
	}
	else
	{
		//call client function
        pid = (pid_t) ft_atoi(argv[1]);
		str = argv[2][0];
		//call function of create malloc funct y length
        //char c = argv[2][0];
        //send_char(pid, c);
	}
	return (0);
}

// Que queremos hacer: Comunicarnos con el servidor mediante señales para
// enviar un string.
void	send_char(pid_t pid, char c) {
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
		usleep(100);// tiempo a esperar, para asegurar que la senyal sea manejada
		i--;
	}
}

void	checkMessageClientValid(char *str)
{
	int		length_message;
	char	*cleanMessage;

	length_message = ft_strlen(str);
}

char	*client(pid_t pidServer, char *strToSend)
{
	char	*strReturn;
	size_t	i;
	ft_printf("%ui\n", pidServer);
	ft_printf("%s\n", strToSend);

	strReturn = NULL;
	i = 0;
	while (strToSend[i])
	{
		strReturn[i] = strToSend[i];
		i++;
	}
	return (strReturn);
}

int	main (int argc, char **argv)
{
    check_correct_args(argc, argv);
	return (0);
}
