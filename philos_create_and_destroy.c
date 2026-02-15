/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create_and_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:06:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/15 17:05:17 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	destroy_philos(t_symposium *roundtable, int max_index)
{
	int	index;
	int	return_status;
	t_philo	current_philo;

	index = max_index;
	return_status = 1;
	while (index >= 0)
	{
		current_philo = roundtable->philos_array[index];
		//First, destroy mutex. Then you can join the thread
		printf("Hi, index %d\n", index);
		if (!destroy_single_mutex(&current_philo.right_hand)
			|| !destroy_single_mutex(&current_philo.left_hand))
			return_status = 0;//????
		if (pthread_join(current_philo.thread, NULL) != 0)
			return_status = 0;//????
		
		--index;
	}
	return (return_status);
	 //if everthing okay, return 1
}

int	create_philos(unsigned int *data, t_symposium *roundtable)
{
	unsigned int	counter;
	t_philo	*new;

	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		new = &roundtable->philos_array[counter];
		new->id = counter + 1;		
		new->fork = 0;		
		new->eaten_times = 0;
		new->symposium = roundtable;
		//Needed mutex to get start?
		new->last_meal = roundtable->start;
		if (pthread_create(&new->thread, NULL,
				philo_routine, (void *)new) != 0)
		{
			destroy_philos(roundtable, counter);
			return (0);
		}
		++counter;
	}
	return (1);
}
