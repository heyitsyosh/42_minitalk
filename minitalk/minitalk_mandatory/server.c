/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:14:08 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/06 23:20:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h> //getpid, pause
#include <stdlib.h> //exit
#include "../includes/minitalk.h"

static void	handler(int signal, siginfo_t *s_info, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	(void)s_info;
	if (signal == SIGUSR1)
		c = c << 1;
	else
		c = (c << 1) + 1;
	if (++bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	ft_printf("pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		exit (1);
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		exit (1);
	while (1)
		pause();
}
