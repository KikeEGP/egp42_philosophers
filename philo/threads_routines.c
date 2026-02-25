/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:08:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/24 18:28:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	philos_finished(t_symposium *symposium, int index,
			t_philo *philo_observed)
{
	static unsigned int	sum;

	pthread_mutex_lock(&symposium->symp_mutex[EATEN_TIMES_MUTEX]);
	if (!symposium->checklist[index]
		&& philo_observed->eaten_times >= symposium->eat_min_times)
	{
		symposium->checklist[index] = 1;
		pthread_mutex_unlock(&symposium->symp_mutex[EATEN_TIMES_MUTEX]);
		sum += 1;
		if (sum == symposium->num_philos)
			return (1);
	}
	pthread_mutex_unlock(&symposium->symp_mutex[EATEN_TIMES_MUTEX]);
	return (0);
}

static int	dinner_may_stop(t_symposium *symposium, unsigned int index,
			t_philo *philo_observed)
{
	if (!check_time(philo_observed->last_meal, symposium->die_time))
	{
		die_state(symposium, philo_observed);
		return (1);
	}
	else if (symposium->checklist != NULL
		&& philos_finished(symposium, index, philo_observed))
		return (1);
	return (0);
}

void	*delphi_oracle_routine(void *data)
{
	t_symposium		*symposium;
	unsigned int	index;
	t_philo			*philo_observed;

	symposium = (t_symposium *)data;
	wait_all_threads(symposium);
	index = 0;
	while (1)
	{
		if (index == symposium->num_philos)
			index = 0;
		philo_observed = &symposium->philos_array[index];//May I put this below mutex_lock?
		pthread_mutex_lock(&symposium->symp_mutex[DIE_MUTEX]);
		if (dinner_may_stop(symposium, index, philo_observed))
		{
			symposium->dinner_over = 1;
			pthread_mutex_unlock(&symposium->symp_mutex[DIE_MUTEX]);
			break ;
		}
		pthread_mutex_unlock(&symposium->symp_mutex[DIE_MUTEX]);
		++index;
	}
	return (data);//WHY I DO THIS?
}

void	*philo_routine(void *has_taken_a_seat)
{
	t_philo		*philo;
	t_symposium	*table;

	philo = (t_philo *)has_taken_a_seat;
	table = philo->symposium;
	wait_all_threads(table);
	while (1)
	{
		think_state(table, philo);
		if (!eat_state(table, philo) || !sleep_state(table, philo))
			break ;
	}
	return (has_taken_a_seat);//WHY I DO THIS?
}
