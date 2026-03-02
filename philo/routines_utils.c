/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:49:16 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/02 18:04:57 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	oracle_counsel(t_symposium *symposium)
{
	int	counsel_given;

	counsel_given = 1;
	pthread_mutex_lock(&symposium->symp_mutex[CONTROL]);
	if (symposium->dinner_over)
		counsel_given = 0;
	pthread_mutex_unlock(&symposium->symp_mutex[CONTROL]);
	return (counsel_given);
}

int	state_change_log(char *message, t_philo *philo, t_symposium *data,
		int oracle_glance)
{
	unsigned long long	current_time;

	pthread_mutex_lock(&data->symp_mutex[PRINT_MUTEX]);
	get_program_time(&current_time, data);
	if (oracle_glance != ORACLE_FOUND_DEAD && !oracle_counsel(data))
	{
		pthread_mutex_unlock(&data->symp_mutex[PRINT_MUTEX]);
		return (0);
	}
	printf(message, current_time, philo->id);
	pthread_mutex_unlock(&data->symp_mutex[PRINT_MUTEX]);
	return (1);
}

void	take_fork(t_symposium *table, t_philo *philo, pthread_mutex_t *fork)
{
	unsigned long long	unix_time;

	pthread_mutex_lock(fork);
	get_unix_time(&unix_time);
	state_change_log(TAKE_FORK, philo, table, NON_STOP);
}

void	release_forks(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_target;
	right = philo->right_target;
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&table->fork_mutex[left]);
		pthread_mutex_unlock(&table->fork_mutex[right]);
	}
	else
	{
		pthread_mutex_unlock(&table->fork_mutex[right]);
		pthread_mutex_unlock(&table->fork_mutex[left]);
	}
	return ;
}

void	wait_all_threads(t_symposium *data)
{
	pthread_mutex_lock(&data->symp_mutex[INIT_MUTEX]);
	pthread_mutex_unlock(&data->symp_mutex[INIT_MUTEX]);
}
