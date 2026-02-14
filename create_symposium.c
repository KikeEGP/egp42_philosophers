/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/14 19:24:13 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	add_parse_data(t_symposium *data, unsigned int *parse_data,
		int flag_stop_eat)
{
	data->num_philos = parse_data[NUM_PHILOS];
	data->die_time = parse_data[TIME_DIE];
	data->eat_time = parse_data[TIME_EAT];
	data->sleep_time = parse_data[TIME_SLEEP];
	data->eat_min_times = parse_data[EAT_MIN_TIMES];
	data->flag_stop_eat = flag_stop_eat;
	data->dead_found = 0;
}

static int	allocate_philos(unsigned int *data, t_symposium *table)
{
	table->philos_array = (t_philo *)malloc(data[NUM_PHILOS] * sizeof(t_philo));
	if (!table->philos_array)
	{
		print_message("Error: failed trying to alloc philos\n", 2);
		return (0);
	}
	return (1);
}

static int	end_of_symposium(t_symposium *roundtable)
{
	(void)roundtable;//DELETE THIS
	//When dead_found == 1, end all. However, this is
	//delphi_oracle business, isn't it?
	return (1);
}

int	create_symposium(unsigned int *data, t_symposium *roundtable,
		int flag_stop_eat)
{
	t_philo		*philos;

	add_parse_data(roundtable, data, flag_stop_eat);
	if (!init_symposium_mutex(roundtable))
		return (0);
	if (!allocate_philos(data, roundtable))
		return (abort_symposium(roundtable, MALLOC_FAILED));
	if (!get_time(&roundtable->start))
		return (abort_symposium(roundtable, GET_TIME_FAILED));
	pthread_mutex_lock(&roundtable->mutex[INIT_MUTEX]);
	roundtable->threads_ready = 0;
	if (!create_philos(data, roundtable))
		return (abort_symposium(roundtable, PHILOS_DELETED));
	if (pthread_create(&roundtable->delphi_oracle, NULL,
			delphi_oracle_routine, (void *)roundtable) != 0)
		return (abort_symposium(roundtable, DELPHI_ORACLE_FAILED));
	roundtable->threads_ready = 1;
	pthread_mutex_unlock(&mutex[INIT]);
	return (end_of_symposium(roundtable));//Correct?
}
