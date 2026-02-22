/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:49:16 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/22 18:01:21 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	oracle_counsel(t_symposium *symposium)
{
	int	counsel_given;

	counsel_given = 1;
	pthread_mutex_lock(&symposium->symp_mutex[DIE_MUTEX]);
	if (symposium->dinner_over)
		counsel_given = 0;
	pthread_mutex_unlock(&symposium->symp_mutex[DIE_MUTEX]);
	return (counsel_given);
}

void	state_change_log(char *message, t_philo *philo, t_symposium *data)
{
	unsigned long long	current_time;

	pthread_mutex_lock(&data->symp_mutex[PRINT_MUTEX]);
	get_program_time(&current_time, data);//This function needs an if
	printf(message, current_time, philo->id);
	pthread_mutex_unlock(&data->symp_mutex[PRINT_MUTEX]);
}

void	take_fork(t_symposium *table, t_philo *philo, pthread_mutex_t *fork)
{
	unsigned long long	unix_time;

	pthread_mutex_lock(fork);
	get_unix_time(&unix_time);
	state_change_log(TAKE_FORK, philo, table);
}

void	release_forks(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_target;
	right = philo->right_target;
	pthread_mutex_unlock(&table->fork_mutex[left]);
	pthread_mutex_unlock(&table->fork_mutex[right]);
	return ;
}

void	wait_all_threads(t_symposium *data, t_philo *philo)
{
	while (data->threads_ready != 1)
	{
		if (data->threads_ready)
			break ;
	}
	if (philo && philo->id % 2 == 0)
		usleep(500);//Try with max 850 || 900 µs
	return ;
}
