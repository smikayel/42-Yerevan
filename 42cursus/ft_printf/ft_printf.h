/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:45:33 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/28 19:16:09 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

int	hex_print(unsigned int number, char upper_lower);
int	ft_print_unsigned_int(unsigned int number);
int	ft_print_pointer(unsigned long long int nbr);
int	print_str(char *string);
int	print_dec_int(int nbr);
int	ft_printf(const char *form, ...);

#endif
