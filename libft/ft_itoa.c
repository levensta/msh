/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:49:12 by mhufflep          #+#    #+#             */
/*   Updated: 2021/04/28 23:15:42 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		c;
	int		digits;
	
	digits = 1;
	if (n < 0)
		digits++;
	while (n / 10 != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);	
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*str;
	int		sign;

	sign = 1 * (n < 0) + 0 * (n >= 0);
	digits = count_digits(n);
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[digits] = '\0';
	while (digits > sign)
	{
		if (n < 0)
			str[--digits] = (n % 10) * (-1) + '0';
		else	
			str[--digits] = (n % 10) + '0';	
		n /= 10;
	}
	return (str);
}