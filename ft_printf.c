/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piranucc <piranucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:48:07 by piranucc          #+#    #+#             */
/*   Updated: 2016/12/15 15:15:14 by piranucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
#include <stdio.h>

int		print_s(char *s, int fd)
{
	int ret;

	write(fd, s, ft_strlen(s));
	ret = ft_strlen(s);
	return (ret);
}

int		print_i(int lennb, int fd)
{

	int ret;

	ret = ft_len_nb(lennb);
	ft_putnbr_fd(lennb, fd);
	return (ret);

}

int		fd_printf(int fd, char *str, ...)
{
	va_list	pa;
	int		ret;
	int		i;

	i = -1;
	va_start(pa, str);
	ret = 0;
	while (str[++i] !='\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ret += print_s(va_arg(pa, char *), fd);
			else if (str[i] == 'i')
				ret += print_i(va_arg(pa, int), fd);
		}
		else
		{
			ft_putchar_fd(str[i], fd);
			ret ++;
		}
	}
	va_end(pa);
	return (ret);
}
