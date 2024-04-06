/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/06 15:34:29 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	strReturn[i]= '\0';
	return (strReturn);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("incorrect arguments");
	}
	else
	{
		//client(argv[1][1], argv[2]);

		printf("%s\n", argv[1]);
		printf("%s\n", argv[2]);
	}
}
