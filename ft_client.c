/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/08 13:53:45 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 *	check number of args in client
 *	check in argv 2 no send a PID of server
 */
int	check_correct_args(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("number of args incorrect");
		return (1);

	}
	else
	{
		//call client function
	}
	return (0);
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


	return (0);
}
