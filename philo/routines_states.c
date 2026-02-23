/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/23 18:50:31 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	take_both_forks(t_symposium *table, t_philo *philo)
{
	int	left;
	int	right;

	left = philo->left_target;
	right = philo->right_target;
	if (table->num_philos == 1 && philo->id == 1)
	{
		take_fork(table, philo, &table->fork_mutex[left]);
		ft_usleep(table->die_time, table);//PS: Not checked this
		//I put this line above last hour yesterday, not tried
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
}

int	eat_state(t_symposium *table, t_philo *philo)
{
	//I do not take care of odd num_philos == 1 philo eats more than others
	//	PS: "I do this in think_state", but must be checked
	take_both_forks(table, philo);
	get_unix_time(&philo->last_meal);//may protect here
	state_change_log(EAT, philo, table);
	if (!ft_usleep(table->eat_time, table))
	{
		release_forks(table, philo);
		return (0);
	}
	pthread_mutex_lock(&table->symp_mutex[EATEN_TIMES_MUTEX]);
	if (table->checklist)
		philo->eaten_times += 1;
	pthread_mutex_unlock(&table->symp_mutex[EATEN_TIMES_MUTEX]);
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

//In order to be sure that every philo eats more or less the same times,
//	think is great scope to put some delay to odd philos
//	if num_philos is odd too
void	think_state(t_symposium *table, t_philo *philo)
{
	state_change_log(THINK, philo, table);
	if (table->num_philos % 2 != 0 && philo->id % 2 != 0)
		usleep(850);//Try with other values
}

void	die_state(t_symposium *table, t_philo *philo)
{
	state_change_log(DIE, philo, table);
}
