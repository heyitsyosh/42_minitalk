/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:14:08 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/18 05:10:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signal, siginfo_t s_info, void *context)
{
	static int	c;
	static int	bit;
	pid_t		client_pid;

	client_pid = s_info->si_pid;
	if (signal == SIGUSR1)
		c = c << 1;
	else
		c = (c << 1) + 1;
	if (++bit == 8)
	{
		if (c == 4)
			kill(client_pid, SIGUSR2);
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	s;

	s.sa_flags = SA_SIGINFO;
	s.sa_sigaction = handler;
	ft_printf("pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		exit (1);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		exit (1);
	while (1)
		pause ;
}

/*
do i really need to use pause?
make sure to check that acknowledge actually works

かわださんのに追記で、UTF-8では上位ビットを見ることでそのバイトがどの文字に属するのかがわかるようになっています。1文字の1byte目は、 0 , 110 , 1110 , 11110 のいずれかが上位ビットにきます。それぞれ、1byte, 2byte, 3byte, 4byteで1文字を表すことを示します。2~4byte文字の場合、それ以降に 10 で続くバイト列が並びます。
まとめると、
- 1byte文字 → 0XXXXXXX 
- 2byte文字 → 110XXXXX 10XXXXXX
- 3byte文字 → 1110XXXX 10XXXXXX 10XXXXXX 
- 4byte文字 → 11110XXX 10XXXXXX 10XXXXXX 10XXXXXX 
の形式を取ることになります。
少なくとも1byteずつ読んでいってもASCIIであるか否かは最上位bitだけ確認すれば良いということになります。
*/