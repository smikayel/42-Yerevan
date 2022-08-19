/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:53:17 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/19 18:31:04 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*init_is_dead(int philo_count)
{
	int	*philos_is_dead;
	int	i;

	philos_is_dead = malloc(sizeof(int) * philo_count);
	i = 0;
	while (philos_is_dead[i])
	{
		philos_is_dead[i] = 0;
		i++;
	}
	return (philos_is_dead);
}

void	*life(void *cur_philo)
{
	t_current	*curr;
	t_philo		*philo;
	int eat_count;

	curr = (t_current *)cur_philo;
	philo = curr->philo;
	eat_count = curr->philo->number_of_times_each_philosopher_must_eat || 1;
	//need to check
	// while (eat_count && !is_any_died(curr))
	// {
	// 	pthread_mutex_lock(philo->mutex);
	// 	if (!take_fork_eat(curr->philo, curr->philo_number))
	// 		eat_count -= eat(curr->philo, curr->philo_number, curr);
	// 	else
	// 	{
	// 		pthread_mutex_unlock(philo->mutex);
	// 		sleeping(curr->philo, curr->philo_number, curr);
	// 		thinking(curr->philo, curr->philo_number);
	// 	}
	// }
	return (NULL);
}

void	create_thred(pthread_t	*threds, int thred_num, t_philo *philosophers)
{
	t_current	*philo;

	philo = malloc(sizeof(t_current));
	if (!philo)
		error(1);
	philo->philo_number = thred_num;
	philo->philo = philosophers;
	if (pthread_create(&threds[thred_num], NULL, life, (void *)philo) < 0)
		error(4);
}

pthread_t	*born_philo(t_philo	*philo)
{
	pthread_t		*threds;
	int				i;
	pthread_mutex_t	mutex;
	int				*forks;

	philo->forks = get_forks(((t_philo *)philo)->number_of_philosophers);
	threds = malloc(sizeof(pthread_t) * philo->number_of_philosophers);
	if (!threds)
		error(1);
	philo->mutex = &mutex;
	if (pthread_mutex_init(&mutex, NULL) < 0)
		error(5);
	philo->is_dead_philos = init_is_dead(philo->number_of_philosophers);
	i = 0;
	while (i++ < philo->number_of_philosophers)
		create_thred(threds, i - 1, philo);
	i = 0;
	while (i++ < philo->number_of_philosophers)
		if (pthread_join(threds[i], NULL) < 0)
			error(4);
	pthread_mutex_destroy(&mutex);
	return (threds);
}
