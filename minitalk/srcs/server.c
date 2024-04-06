/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:14:08 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 00:01:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h> //sigaction, kill, siginfo_t, SA_SIGINFO, SIGUSR1, SIGUSR2
#include <sys/types.h>
#include <unistd.h> //getpid, pause
#include <stdlib.h> //exit
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

static void	handler(int signal, siginfo_t *s_info, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	if (signal == SIGUSR1)
		c = c << 1;
	else
		c = (c << 1) + 1;
	if (++bit == 8)
	{
		if (c == 4)
			if (kill(s_info->si_pid, SIGUSR1) == -1)
				exit (1);
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
