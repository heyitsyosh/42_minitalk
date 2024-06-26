/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:20:25 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/07 02:40:56 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*uc_dst;
	const unsigned char	*uc_src = src;
	size_t				i;

	if (dst == src)
		return (NULL);
	uc_dst = dst;
	i = 0;
	while (i < n)
	{
		*(uc_dst + i) = *(uc_src + i);
		i++;
	}
	return (dst);
}
