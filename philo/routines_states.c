/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/21 21:33:39 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void take_both_forks(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_target;
	right = philo->right_target;
	if (table->num_philos == 1 && philo->id == 1)
		//
		return ;//debug
	else if (philo->id % 2 != 0)
	{
		take_fork(table, philo, &table->fork_mutex[left]);
		take_fork(table, philo, &table->fork_mutex[right]);
	}
	else
	{
		take_fork(table, philo, &table->fork_mutex[right]);
		take_fork(table, philo, &table->fork_mutex[left]);
	}
}

void	eat_state(t_symposium *table, t_philo *philo)
{
	take_both_forks(table, philo);
	get_unix_time(&philo->last_meal);
	state_change_log(EAT, philo, table);
	//If needed to count meals, count.
	//	If counted >= min_times_eat, change a flag
	//Wait to eat_time and then you finish here
}

void	sleep_state(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;
	unsigned long long	unix_time;

	left = philo->left_target;
	right = philo->right_target;
	pthread_mutex_unlock(&table->fork_mutex[left]);
	pthread_mutex_unlock(&table->fork_mutex[right]);
	get_unix_time(&unix_time);
	state_change_log(SLEEP, philo, table);
	//Wait to sleep_time and then you finish here
}
