/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create_and_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:06:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/13 16:45:27 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	destroy_philos(t_symposium *roundtable, int max_index)
{
	int	index;

	index = max_index;
	while (index >= 0)
	{

		--index;
	}
	 //if everthing okay, return 1
}

int	create_philos(unsigned int *data, t_symposium *roundtable)
{
	int	counter;
	t_philo	new;

	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		new = roundtable.philos_array[counter];
		new->id = counter + 1;		
		new->fork = 0;		
		new->eaten_times = 0;
		//Needed mutex to get start?
		new->last_meal = roundtable->start;
		if (pthread_create(&new->thread, NULL, philo_routine,
				(void *)roundtable) != 0)
		{
			destroy_philos(roundtable, counter);
			return (0);
		}
		++counter;
	}
	return (1);
}
