/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:15:57 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/02 00:07:57 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
/*
typedef struct	s_message
{
	int		length;
	char	*content;
}		t_message;
*/
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include "include/printf/ft_printf.h"
# include "include/libft/libft.h"

# define TIME_WAITING 100

char	*client(char *strToSend);

#endif
