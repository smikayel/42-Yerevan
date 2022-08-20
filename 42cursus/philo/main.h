/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:08:47 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/20 20:34:40 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
 
typedef struct s_philo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				*forks;
	int				*is_dead_philos;
	pthread_mutex_t	*mutex;
}	t_philo;

typedef struct s_current
{
	t_philo	*philo;
	int		philo_number;
	int		time_not_eating;
	int		state;
	int		think_state;
}	t_current;

void		error(int error_code);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
long long	current_timestamp(void);
t_philo		*get_arg(char **argv);
pthread_t	*born_philo(t_philo	*philo);
void		*life(void *philo);
int			*get_forks(int forks_count);
int			get_forks_current_philo(void *philo, int philo_number);


int			take_fork_eat(void *philo, int philo_number, int state);
int			eat(void *philos, int philo_number, t_current	*curr);
void		sleeping(void *philos, int philo_number, t_current *curr);
int			put_forks_current_philo(void *philo, int philo_number);
void		thinking(void *philos, int philo_number, t_current *curr);
int			is_any_died(t_current	*curr);

#endif