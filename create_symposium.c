/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/07 20:47:07 by enrgil-p         ###   ########.fr       */
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
}

static int	create_philos(unsigned int *data, t_symposium *roundtable)
{
	int	counter;
	t_philo	new;

	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		new = roundtable->philos_array[counter];
		new->id = counter + 1;		
		new->eaten_times = 0;
		new->last_meal = 0;//Update to start time of program.
			   	//This is so important, is time to die
				//Or in the thread
		new->fork = /**/;
		if (pthread_create(&new->thread, NULL, philo_routine,
				(void *)roundtable) != 0)
		++counter;
	}
}

int	create_symposium(unsigned int *data, t_symposium *roundtable)
{
	t_philo		*philos;//Can't be stack, VLA_FORBIDDEN

	add_parse_data(roundtable, data);
	if (!init_symposium_mutex(roundtable))
		return (0);
	//lock with mutex
	roundtable->threads_ready = 0;
	roundtable->philos_array = (s_philo)malloc(data[NUM_PHILOS]
			* sizeof(s_philo));//or t_philo?
	if (!roundtable->philos_array || !create_philos(data, rountable) ||
			/*!creation(delphi_oracle)*/)
	{
		//What error? Malloc, fail of create philo?
		//DESTROY ALL: MUTEX, MALLOCS, etc.
	}
	//pthread_create(&roundtable->delphi_oracle, NULL, delphi_routine, (void *)roundtable);
	//Create here MONITOR, another thread that checks when some philo dies
	if (!get_time(&roundtable->start))
	{
		print_message("Error: gettimeofday failed", 2);
		return (0);
	}
	//Unlock INIT_MUTEX
	return (1);
}
