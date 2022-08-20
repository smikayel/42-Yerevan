/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:22:38 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/20 20:21:08 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_forks_current_philo(void *philo, int philo_number)
{
	int	fork_index[2];
	int	*forks;
	int status;

	fork_index[0] = philo_number;
	status = 0;
	forks = ((t_philo *)philo)->forks;
	if (philo_number == ((t_philo *)philo)->number_of_philosophers - 1)
		fork_index[1] = 0;
	else
		fork_index[1] = philo_number + 1;
	if (forks[fork_index[0]] == 1 && forks[fork_index[1]] == 1)
		status = 1;
	if (forks[fork_index[0]] == 1)
	{
		forks[fork_index[0]] = 0;
		printf("%llu %d has taken a fork\n", current_timestamp(), philo_number + 1);
	}
	if (forks[fork_index[1]] == 1)
	{
		forks[fork_index[1]] = 0;
		printf("%llu %d has taken a fork\n", current_timestamp(), philo_number + 1);
	}
	return (status);
}

int	put_forks_current_philo(void *philo, int philo_number)
{
	int	fork_index[2];
	int	*forks;

	fork_index[0] = philo_number;
	forks = ((t_philo *)philo)->forks;
	if (philo_number == ((t_philo *)philo)->number_of_philosophers - 1)
		fork_index[1] = 0;
	else
		fork_index[1] = philo_number + 1;
	if (forks[fork_index[0]] == 0 && forks[fork_index[1]] == 0)
	{
		forks[fork_index[0]] = 1;
		forks[fork_index[1]] = 1;
		return (0);
	}
	return (-1);
}