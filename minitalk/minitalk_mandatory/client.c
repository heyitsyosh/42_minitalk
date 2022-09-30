/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:16:21 by myoshika          #+#    #+#             */
/*   Updated: 2022/09/22 22:56:35 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static bool	str_is_num(char *str)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len || str_len == 0)
		if (!ft_isdigit(str[i]) || str_len == 0)
			return (false);
	return (true);
}

static pid_t	check_pid(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3 || !str_is_num(argv[1]))
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		exit (1);
	return (pid);
}

static void	send_byte(pid_t pid, int character)
{
	int	shift;
	int	bit_to_send;
	int	kill_status;

	shift = 7;
	while (shift-- >= 0)
	{
		bit_to_send = (character >> shift) & 1;
		if (bit_to_send == 1)
			kill_status = kill(pid, SIGUSR2);
		else
			kill_status = kill(pid, SIGUSR1);
		if (kill_status == -1)
			exit(1);
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	pid = check_pid(argc, argv);
	message = argv[2];
	while (*message)
		send_byte(pid, *message++);
	send_byte(pid, 4);
}
