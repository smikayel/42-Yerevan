/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:34 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/28 19:17:04 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

void	check_form(const char form, va_list arguments, int *len, int *j)
{
	int	i;
	int	count;

	i = *j;
	count = *len;
	if (form == 'c')
		count += ft_putchar(va_arg(arguments, int), 1);
	else if (form == 's')
		count += print_str(va_arg(arguments, char *));
	else if (form == 'p')
		count += ft_print_pointer(va_arg(arguments, unsigned long long));
	else if (form == 'd' || form == 'i')
		count += print_dec_int(va_arg(arguments, int));
	else if (form == 'u')
		count += ft_print_unsigned_int(va_arg(arguments, unsigned int));
	else if (form == 'x' || form == 'X')
		count += hex_print(va_arg(arguments, int), form);
	else if (form == '%')
		count += ft_putchar('%', 1);
	i++;
	*j = i;
	*len = count;
}

int	ft_printf(const char *form, ...)
{
	va_list	arguments;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arguments, form);
	while (form[i] != '\0')
	{
		if (form[i + 1] && form[i] == '%')
		{
			check_form(form[i + 1], arguments, &count, &i);
		}
		else
			count += ft_putchar(form[i], 1);
		i++;
	}
	va_end(arguments);
	return (count);
}
