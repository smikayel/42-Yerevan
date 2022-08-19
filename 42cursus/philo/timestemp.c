/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:50:02 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/18 16:05:51 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

long long	current_timestamp(void)
{
	struct timeval	te;

	gettimeofday(&te, 0);
	return (te.tv_sec * 1000LL + te.tv_usec / 1000);
}
