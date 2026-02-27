/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/27 22:38:24 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	take_both_forks(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_target;
	right = philo->right_target;
	if (table->num_philos == 1 && philo->id == 1)
	{
		take_fork(table, philo, &table->fork_mutex[left]);
		ft_usleep(table->die_time, table);
		release_forks(table, philo);
		return (0);
	}
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
	return (1);
}

int	eat_state(t_symposium *table, t_philo *philo)
{
	if (!oracle_counsel(table) || !take_both_forks(table, philo))
		return (0);
	pthread_mutex_lock(&table->symp_mutex[CONTROL]);
	get_unix_time(&philo->last_meal);
	pthread_mutex_unlock(&table->symp_mutex[CONTROL]);
	state_change_log(EAT, philo, table, NON_STOP);
	if (!ft_usleep(table->eat_time, table))
	{
		release_forks(table, philo);
		return (0);
	}
	pthread_mutex_lock(&table->symp_mutex[CONTROL]);
	if (table->checklist)
		philo->eaten_times += 1;
	pthread_mutex_unlock(&table->symp_mutex[CONTROL]);
	return (1);
}

int	sleep_state(t_symposium *table, t_philo *philo)
{
	release_forks(table, philo);
	state_change_log(SLEEP, philo, table, NON_STOP);
	if (!ft_usleep(table->sleep_time, table))
		return (0);
	return (1);
}

//In order to be sure that every philo eats more or less the same times,
//	think is great scope to put some delay to odd philos
//	if num_philos is odd too
void	think_state(t_symposium *table, t_philo *philo)
{
	state_change_log(THINK, philo, table, NON_STOP);
/*	if (table->num_philos % 2 != 0 && philo->id % 2 != 0)
		usleep(1000);*///Commented by me
}

void	die_state(t_symposium *table, t_philo *philo)
{
	state_change_log(DIE, philo, table, ORACLE_FOUND_DEAD);
}
