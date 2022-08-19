/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:48:05 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/17 15:01:22 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	error(int error_code)
{
	if (error_code == 0)
		printf("Arg. error: Need \n \
[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]!\n \
<[number_of_times_each_philosopher_must_eat]> ");
	else if (error_code == 1)
		printf("Allocation error: memory does not allocated!");
	else if (error_code == 2)
		printf("Arg. error: need arguments intager numbers with miliseconds!");
	else if (error_code == 3)
		printf("Arg. error: argument is negative!");
	else if (error_code == 4)
		printf("Thred error: Something went wrong!");
	else if (error_code == 5)
		printf("Thred error: can't create mutex!");
	exit(1);
}
