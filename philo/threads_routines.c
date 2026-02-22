/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:08:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/22 17:48:57 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	philos_finished(t_symposium *symposium, int index,
			t_philo *philo_observed)
{
	static unsigned int	sum;

	if (symposium->checklist != NULL && !symposium->checklist[index]
		&& philo_observed->eaten_times >= symposium->eat_min_times)
	{
		symposium->checklist[index] = 1;
		sum += 1;
		if (sum == symposium->num_philos)
			return (1);
	}
	return (0);
}

void	*delphi_oracle_routine(void *data)
{
	t_symposium	*symposium;
	int		index;
	t_philo		*philo_observed;

	symposium = (t_symposium *)data;
	wait_all_threads(symposium, NULL);	
	index = 0;
	while (1)
	{
		if (index == symposium->num_philos)
			index = 0;
		//mutex?
		philo_observed = symposium->philos_array[index];
		if (!check_time(philo_observed->last_meal, data->die_time)
			|| philos_finished(symposium, index, philo_observed))
		{
			data->dinner_over == 1;
			break ;
		}
		++philo_index;
	}
	return (data);//WHY I DO THIS?
}

void	*philo_routine(void *has_taken_a_seat)
{
	t_philo	*philo;
	t_symposium *table;
	
	philo = (t_philo *)has_taken_a_seat;
	table = philo->symposium;
	wait_all_threads(table, philo);
	while (1)
	{
		think_state(table, philo);
		if (!eat_state(table, philo) || !sleep_state(table, philo))
			break ;
	}
	return (has_taken_a_seat);//WHY I DO THIS?
}
