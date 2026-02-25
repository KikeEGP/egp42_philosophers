/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/25 18:34:37 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	add_parse_data(t_symposium *data, unsigned int *parse_data)
{
	data->num_philos = parse_data[NUM_PHILOS];
	data->die_time = parse_data[TIME_DIE];
	data->eat_time = parse_data[TIME_EAT];
	data->sleep_time = parse_data[TIME_SLEEP];
	data->eat_min_times = parse_data[EAT_MIN_TIMES];
	data->dinner_over = 0;
}

static int	alloc_checklist(t_symposium *symposium, int flag_stop_eat)
{
	unsigned int	expected;
	unsigned int	i;

	expected = symposium->num_philos;
	if (flag_stop_eat == NON_STOP)
		symposium->checklist = NULL;
	else
	{
		symposium->checklist = (int *)malloc(expected * sizeof(int));
		if (!symposium->checklist)
		{
			print_message("Error: failed trying to alloc meals checklist\n", 2);
			single_clean(symposium, FREE_ALLOCATIONS);
			return (0);
		}
		i = 0;
		while (i < expected)
			symposium->checklist[i++] = 0;
	}
	return (1);
}

static int	alloc_chairs_and_forks(t_symposium *table)
{
	unsigned int	expected;
	int				philo_size;
	int				f_m_size;

	expected = table->num_philos;
	philo_size = sizeof(t_philo);
	f_m_size = sizeof(pthread_mutex_t);
	table->philos_array = (t_philo *)malloc(expected * philo_size);
	if (!table->philos_array)
	{
		print_message("Error: failed trying to alloc philos\n", 2);
		return (0);
	}
	table->fork_mutex = (pthread_mutex_t *)malloc(expected * f_m_size);
	if (!table->fork_mutex)
	{
		free(table->philos_array);
		print_message("Error: failed trying to alloc fork_mutex\n", 2);
		return (0);
	}
	return (1);
}

static int	init_symposium_mutex(t_symposium *data)
{
	if (!init_array_mutex(data->symp_mutex, MAX_MUTEX))
		return (0);
	if (!init_array_mutex(data->fork_mutex, data->num_philos))
	{
		destroy_array_mutex(data->symp_mutex, MAX_MUTEX);
		return (0);
	}
	return (1);
}

int	create_symposium(unsigned int *data, t_symposium *roundtable,
		int flag_stop_eat)
{
	add_parse_data(roundtable, data);
	if (!alloc_chairs_and_forks(roundtable)
		|| !alloc_checklist(roundtable, flag_stop_eat))
		return (0);
	if (!init_symposium_mutex(roundtable))
		return (abort_symposium(roundtable, MUTEX_FAILED));
	if (!get_unix_time(&roundtable->start))
		return (abort_symposium(roundtable, GET_TIME_FAILED));
	pthread_mutex_lock(&roundtable->symp_mutex[INIT_MUTEX]);
	if (!create_philos(data, roundtable))
		return (abort_symposium(roundtable, PHILOS_DELETED));
	if (pthread_create(&roundtable->delphi_oracle, NULL,
			delphi_oracle_routine, (void *)roundtable) != 0)
		return (abort_symposium(roundtable, DELPHI_ORACLE_FAILED));
	pthread_mutex_unlock(&roundtable->symp_mutex[INIT_MUTEX]);
	return (clean_up(roundtable, SUCCESS_RETURN));
}
