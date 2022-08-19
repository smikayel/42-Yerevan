/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:04:08 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/18 19:17:28 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	*get_forks(int forks_count)
{
	int	*forks;
	int	i;

	forks = malloc(sizeof(int) * forks_count);
	if (!forks)
		error(1);
	i = 0;
	while (i < forks_count)
	{
		forks[i] = 1;
		i++;
	}
	return (forks);
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	pthread_t	*threds;

	if (argc < 5 || argc > 6)
		error(0);
	philo = get_arg(argv);
	threds = born_philo(philo);
	return (0);
}
