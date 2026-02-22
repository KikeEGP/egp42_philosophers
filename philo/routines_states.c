/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/22 14:53:51 by enrgil-p         ###   ########.fr       */
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
		return ;//debug
		//Do something here
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

int	eat_state(t_symposium *table, t_philo *philo)
{
	take_both_forks(table, philo);
	get_unix_time(&philo->last_meal);//may protect here
	state_change_log(EAT, philo, table);
	if (!ft_usleep(table->eat_time, table))
	{
		release_forks(table, philo);
		return (0);
	}
	//	If counted >= min_times_eat, change a flag
	return (1);
}

int	sleep_state(t_symposium *table, t_philo *philo)
{
	release_forks(table, philo);
	state_change_log(SLEEP, philo, table);
	if (!ft_usleep(table->sleep_time, table))
		return (0);
	return (1);
}

void	think_state(t_symposium *table, t_philo *philo)
{
	state_change_log(THINK, philo, table);
}
