/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:16:21 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/22 06:22:46 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static bool	str_is_num(char *str)
{
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

static void	check_pid(pid_t *pid, int argc, char **argv)
{
	if (argc != 3 || !str_is_num(argv[1]))
	{
		ft_printf("Error: invalid input\n");
		exit(1);
	}
	*pid = ft_atoi(argv[1]);
	if (*pid < 100 || *pid > 99998)
		exit (1);
}

static void	send_byte(pid_t pid, int character)
{
	int	shift;
	int	bit_to_send;
	int	kill_status;

	shift = 8;
	while (shift-- > 0)
	{
		bit_to_send = (character >> shift) & 1;
		if (bit_to_send == 1)
			kill_status = kill(pid, SIGUSR2);
		else
			kill_status = kill(pid, SIGUSR1);
		if (kill_status == -1)
			exit(1);
		usleep(60);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	check_pid(&pid, argc, argv);
	message = argv[2];
	while (*message)
		send_byte(pid, *message++);
	send_byte(pid, 4);
}
