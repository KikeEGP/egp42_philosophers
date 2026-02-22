/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:08:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/22 14:52:27 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	*delphi_oracle_routine(void *data)
{
	t_symposium	*symp;

	symp = (t_symposium *)data;
	wait_all_threads(symp, NULL);	
	usleep(60000);
	printf("Hello, i'm delphi orcale\n");
	/*Wait to symposium->threads_ready
	Check if philos are alive
		//symp.philos_array[all].life_timer < symp.die_time
	Check if some error?
	if (symposium->eat_min_times != 0)
		check_all_eaten_min_times*/
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
