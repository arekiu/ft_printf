/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:25:48 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/08 11:27:07 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(const char *fmt_str, ...);
int		formater(char format, va_list args, int count);
int		print_p(va_list args, int count);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		print_u(va_list args, int count);
int		print_per(int count);
int		print_str(va_list args, int count);
int		print_c(va_list args, int count);
int		print_d(va_list args, int count);
int		num_len(int n);
void	ft_putunsig(unsigned int n);
int		unsig_num_len(unsigned int n);

#endif
