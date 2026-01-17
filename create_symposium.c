/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_symposium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/17 20:56:19 by enrgil-p         ###   ########.fr       */
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

int	create_symposium(unsigned int *data, unsigned int num_philos, t_symposium *roundtable)
/*t_symposium	create_symposium(unsigned int *data, unsigned int num_philos)*/
{
	int		counter;
	t_philo		philos[num_philos];//Point this with
					   //roundtable->philos_array

	add_parse_data(roundtable, data);
	//init_symposium_mutex(roundtable);
	roundtable->threads_ready = 0;
	//pthread_create(&roundtable->delphi_oracle, NULL, );
	counter = 0;
	while (counter < num_philos)
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
	//Create here MONITOR, another thread that checks when some philo dies
}
