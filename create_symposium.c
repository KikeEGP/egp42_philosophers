/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/08 19:05:32 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	add_parse_data(t_symposium *data, unsigned int *parse_data, 
		int expected_meals)
{
	data->num_philos = parse_data[NUM_PHILOS];
	data->die_time = parse_data[TIME_DIE];
	data->eat_time = parse_data[TIME_EAT];
	data->sleep_time = parse_data[TIME_SLEEP];
	data->eat_min_times = parse_data[EAT_MIN_TIMES];
	data->expected_meals = expected_meals;
}



int	create_symposium(unsigned int *data, t_symposium *roundtable,
		int eat_times)
{
	t_philo		*philos;

	add_parse_data(roundtable, data, eat_times);
	if (!init_symposium_mutex(roundtable))
		return (0);
	//lock with mutex
	roundtable->threads_ready = 0;
	roundtable->philos_array = (s_philo)malloc(data[NUM_PHILOS]
			* sizeof(s_philo));//or t_philo?
	if (!roundtable->philos_array)
	{
		print_message("Error: failed trying to alloc philos", 2);
		return (clean_up(roundtable, MALLOC_FAILED));
	}
	if (!create_philos(data, rountable))
	{
		print_message("Error: failed trying to alloc philos", 2);
		return (clean_up(roundtable, PHILOS_DELETED));
	}
	if (pthread_create(&roundtable->delphi_oracle, NULL, delphi_routine,
			(void *)roundtable) != 0)
	{
		print_message("Error: failed creating delphi_oracle", 2);
		return (clean_up(roundtable, DELPHI_ORACLE_FAILED));
	}
	if (!get_time(&roundtable->start))
	{
		print_message("Error: gettimeofday failed", 2);
		return (clean_up(roundtable, DELETE_ALL));
	}
	roundtable->threads_ready = 1;
	//Unlock INIT_MUTEX
	return (1);
}
