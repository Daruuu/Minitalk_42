/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:09:43 by dasalaza          #+#    #+#             */
/*   Updated: 2024/05/03 16:37:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	g_message = {0};

void	signal_handle_message(int signum);

void	signal_handle_message(int signum)
{
    static int	c;
    static int	i;
    int 		nb;

    if (signum == SIGUSR1)
        nb = 0;
    else
        nb = 1;
    c = (c << 1) + nb;
    i++;
    if (i == 8)
    {
        g_message.content[g_message.index] = c;
        g_message.index = g_message.index + 1;
        if (g_message.index == g_message.length)
        {
            g_message.content[g_message.index] =
                    '\n';
            printf("message: %s", g_message.content);
            free(g_message.content);
            g_message.length = 0;
            g_message.index = 0;
        }
        // write(1, &c, 1);
        i = 0;
        c = 0;
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
        printf("%d\n", g_message.length);
        g_message.content = malloc(sizeof(char *) * (g_message.length + 1));
        i = 0;
    }
}

int	main(void)
{
    ft_printf("Welcome to my SERVER\n");
    ft_printf("The server is UP and running.\n");
    ft_printf("The PID of server is: %d\n", getpid());
    signal(SIGUSR1, signal_handle_length);
    signal(SIGUSR2, signal_handle_length);
    while (1)
        usleep(100);
    return (0);
}