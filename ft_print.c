/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:28 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/07 14:17:05 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	numchar;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			numchar = n + 48;
			write(fd, &numchar, 1);
		}
	}
}

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

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

static int	num_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
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
	ft_putstr_fd(str, 1);
	return (count = count + (int)ft_strlen(str));
}

int print_per(int count)
{
	ft_putchar_fd('%', 1);
	return (count = count + 1);
}

int print_u(va_list args, int count)
{
	unsigned int	dig;

	dig = va_arg(args, unsigned int);
	ft_putunsig(dig);
	return (count = count + num_len(dig));
}

static int	formater(char format, va_list args, int count)
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
	else
		return (count);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	int		i;
	int		count;

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
			ft_putchar_fd(fmt_str[i], 1);
		i++;
	}
	va_end(args);
	printf("counter: %d", count + i);
}

int	main(void)
{
	int	num = 11;
	unsigned int  nr = 98;
	char *str = "vieja";
	int *p = &num;
	//ft_printf("las probabilidades son de un %d%% %s", 5589, str);
	//printf("\n");
	//printf("ORIG las probabilidades son de un %d%% %s", 5589, str);
	//prinft si hay menos argumentos que los %, tiene comportamiento rari
	ft_printf("%u", nr);
	printf("%p", p);
}
