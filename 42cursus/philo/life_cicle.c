/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:19:07 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/19 18:30:25 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ◦ timestamp_in_ms X has taken a fork + 
// ◦ timestamp_in_ms X is eating +
// ◦ timestamp_in_ms X is sleeping -
// ◦ timestamp_in_ms X is thinking -
// ◦ timestamp_in_ms X died -

#include "main.h"

int	take_fork_eat(void *philo, int philo_number)
{
	int	status_take_fork;

	status_take_fork = get_forks_current_philo(philo, philo_number);
	if (status_take_fork < 0)
		return (-1);
	printf("%llu %d has taken a fork\n", current_timestamp(), philo_number);
	return (0);
}

int	eat(void *philos, int philo_number, t_current *curr)
{
	t_philo *philo;

	philo = (t_philo *)philos;
	printf("%llu %d is eating\n", current_timestamp(), philo_number + 1);
	pthread_mutex_unlock(philo->mutex);
	curr->time_not_eating = 0;
	usleep(philo->time_to_eat);
	put_forks_current_philo(philo, philo_number);
	return (1);
}

void	sleeping(void *philos, int philo_number, t_current *curr)
{
	t_philo *philo;

	printf("%llu %d is sleeping\n", current_timestamp(), philo_number + 1);
	philo = (t_philo *)philos;
	usleep(philo->time_to_sleep);
}

int	is_any_died(t_current	*curr)
{
	int	i;
	int *is_dead_aray;
	int	philo_count;

	i = 0;
	is_dead_aray = curr->philo->is_dead_philos;
	philo_count = curr->philo->number_of_philosophers;
	while (i < philo_count)
	{
		if (is_dead_aray[i])
			return (1);
		i++;
	}
	return (0);
}

void	thinking(void *philos, int philo_number)
{
	printf("%llu %d is thinking\n", current_timestamp(), philo_number + 1);
}