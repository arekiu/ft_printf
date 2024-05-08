/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/08 11:27:44 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

int	num_len(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n < 10)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i = i + 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_d(va_list args, int count)
{
	int	dig;

	dig = va_arg(args, int);
	ft_putnbr_fd(dig, 1);
	return (count = count + num_len(dig));
}

int print_c(va_list args, int count)
{
	char ch;

	ch = va_arg(args, int);
	ft_putchar_fd(ch, 1);
	return (count = count + 1);
}

int print_str(va_list args, int count)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (count = count + 6);
	}
	else
		ft_putstr_fd(str, 1);
	return (count = count + (int)ft_strlen(str));
}

int print_per(int count)
{
	ft_putchar_fd('%', 1);
	return (count = count + 1);
}

int	formater(char format, va_list args, int count)
{
	if (format == '%')
		count = print_per(count);
	else if(format == 'd' || format == 'i')
		count = print_d(args, count);
	else if(format == 'c')
		count = print_c(args, count);
	else if(format == 's')
		count = print_str(args, count);
	else if(format == 'u')
		count = print_u(args, count);
	else if(format == 'p')
		count = print_p(args, count);
	return (count);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	int		i;
	int		count;
	
	if (*fmt_str == '\0')
		return (0);
	i = 0;
	count = 0;
	va_start(args, fmt_str);

	while (fmt_str[i] != '\0')
	{
		if (fmt_str[i] == '%')
		{
			count = formater(fmt_str[i + 1], args, count);
			i++;
		}
		else
		{
			ft_putchar_fd(fmt_str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
	//printf("counter: %d", count);
}
/*
int	main(void)
{
	// int	num = 11;
	// unsigned int  nr = 98;
	// char *str = "vieja";
	// int *p = &num;
	// ft_printf("las probabilidades son de un %d%% %s", 5589, str);
	// printf("\n");
	// printf("ORIG las probabilidades son de un %d%% %s", 5589, str);
	// //prinft si hay menos argumentos que los %, tiene comportamiento rari
	// ft_printf("%p", p);
	// printf("\n");
	// printf("%p", p);
	return (0);
}*/
