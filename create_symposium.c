/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/17 20:35:09 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//pmendez created philos direclty with a start_routine function that was 
//the whole states and actions expected from philosophers

int	create_symposium(unsigned int *data, unsigned int num_philos, t_symposium *roundtable)
/*t_symposium	create_symposium(unsigned int *data, unsigned int num_philos)*/
{
	int		counter;
	t_philo		philos[num_philos];//Point this with
					   //roundtable->philos_array

	add_parse_data(data);
	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		//Where I do create the mutex?
		//	In struct
		philos[counter] = add_data(data);
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
