/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:52:10 by mhufflep          #+#    #+#             */
/*   Updated: 2021/05/08 00:48:09 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	char	arr[2];

	if (c < 0)
	{
		arr[0] = ((c & 0xC0) >> 6) | 0xC0;
		arr[1] = (c & 0x3F) | 0x80;
		write(fd, arr, 2);
	}
	else
		write(fd, &c, 1);
}
