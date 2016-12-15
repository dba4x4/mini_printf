/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piranucc <piranucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:48:07 by piranucc          #+#    #+#             */
/*   Updated: 2016/12/15 14:47:57 by piranucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>


#include <stdio.h>
int		ft_printf(int fd, char *str, ...)
{
	va_list pa;
	int ret;
	int i;
	char *s;

	i = 0;
	va_start(pa, str);
	ret = 0;
	while (str[i] !='\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
			{
				s = va_arg(pa, char *);
				write(1, s, ft_strlen(s));
				//i++;
				va_end(pa);
			}
			else if (str[i] == 'i')
			{
				ft_putnbr(va_arg(pa, int));
				//i++;
			}
		}
		else
			ft_putchar_fd(str[i], fd);
		i++;

	}
	va_end(pa);
	return (ret);
}


int main()
{
	int i;

	i = 300;
	ft_printf(1,"debut =>%s | suite => %i | fin =>%s", "FIRST", i, "LAST");
	//ft_printf(1,"coucou %i tout va bien", i);
	return (0);

}
