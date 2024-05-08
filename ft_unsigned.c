/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:34:22 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/08 11:35:55 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsig(unsigned int n)
{
	char numchar;

	if (n > 9)
	{
		ft_putunsig(n / 10);
		ft_putunsig(n % 10);
	}
	else
	{
		numchar = (int)n + 48;
		write(1, &numchar, 1);
	}
}

int unsig_num_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int print_u(va_list args, int count)
{
	unsigned int	dig;

	dig = va_arg(args, unsigned int);
	ft_putunsig(dig);
	return (count = count + unsig_num_len(dig));
}
