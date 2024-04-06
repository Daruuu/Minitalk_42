/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:15:57 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/06 13:42:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "include/printf/ft_printf.h"

void	server();
char	*client(pid_t pidServer, char *strToSend);

#endif
