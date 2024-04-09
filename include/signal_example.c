/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_example.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:41:54 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/09 10:45:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("Tratamiento SIGINT: %d\n", signum);
}

int main() {
    // Obtener el PID del proceso actual
    pid_t pid = getpid();

    // Imprimir el PID
    printf("El PID de este proceso es: %d\n", pid);
    signal(SIGINT, handle_sigint);
    while (1) {

    }
    return 0;
}
