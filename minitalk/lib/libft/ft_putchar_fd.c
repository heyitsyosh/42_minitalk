/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:28:56 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/04 00:44:15 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //write
#include "../../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
