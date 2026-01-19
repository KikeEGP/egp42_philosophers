/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/19 18:27:13 by enrgil-p         ###   ########.fr       */
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

int	create_symposium(unsigned int *data, t_symposium *roundtable)
{
	int			counter;
	t_philo		*philos;//Can't be stack, VLA_FORBIDDEN

	add_parse_data(roundtable, data);
	if (!init_symposium_mutex(roundtable))
		return (0);
	roundtable->threads_ready = 0;
		counter = 0;
	//malloc philos
	while (counter < data[NUM_PHILOS])
	{
		//Where I do create the mutex?
		//	In struct
		philos[counter] = create_a_philo(data);
		++counter;
		//Array of structs?
		//	One general, t_philo in an arry, yes
		//Create a thread, and a fork too[not a fork(), just a 'fork']
		//	I guess this means: struct with times and create mutex
		//	Remember, pmendez talked about five mutex, and people
		//	use to create those five
	}
	//pthread_create(&roundtable->delphi_oracle, NULL, delphi_routinei, (void *)roundtable);
	//Create here MONITOR, another thread that checks when some philo dies
	return (1);
}
