/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:01:17 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/07 16:01:43 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	print_p(va_list args, int count)
{
	void *ptr;
	uintptr_t ptr_num;

	ptr = va_arg(args, void *);
	ptr_num = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	printf("el pointe%ld", ptr_num);
	return (2 + count);
}
