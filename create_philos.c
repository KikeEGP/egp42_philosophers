/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/08 20:52:46 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//pmendez created philos direclty with a start_routine function that was 
//the whole states and actions expected from philosophers

/*void?*/	create_philos(unsigned int *data)
{
	int	counter;
	t_philo	philos[data[NUM_PHILOS]];//Is this possible?

	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		//Where I do create the mutex?
		philos[counter] = add_data(data);
		++counter;
		//Array of structs?
		//Create a thread, and a fork too[not a fork(), just a 'fork']
		//	I guess this means: struct with times and create mutex
		//	Remember, pmendez talked about five mutex, and people
		//	use to create those five
	}
	//Create here MONITOR, another thread that checks when some philo dies
}
