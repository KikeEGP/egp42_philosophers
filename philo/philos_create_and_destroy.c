/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create_and_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:06:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/02 19:50:35 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	destroy_philos(t_symposium *roundtable, int max_index)
{
	int		index;
	int		return_status;

	index = 0;
	return_status = 1;
	while (index < max_index)
	{
		if (pthread_join(roundtable->philos_array[index].thread, NULL) != 0)
		{
			print_message("Error. Join a philo's thread has failed\n", 2);
			return_status = 0;
		}
		++index;
	}
	return (return_status);
}

static void	set_target_forks(t_philo *philo, unsigned int num_philos)
{
	philo->left_target = philo->id - 1;
	if (philo->id == 1 && num_philos > 1)
		philo->right_target = num_philos - 1;
	else
		philo->right_target = philo->id - 2;
	return ;
}

int	create_philos(unsigned int *data, t_symposium *roundtable)
{
	unsigned int	counter;
	t_philo			*new;

	counter = 0;
	while (counter < data[NUM_PHILOS])
	{
		new = &roundtable->philos_array[counter];
		new->id = counter + 1;
		set_target_forks(new, roundtable->num_philos);
		new->eaten_times = 0;
		new->symposium = roundtable;
		new->last_meal = roundtable->start;
		if (pthread_create(&new->thread, NULL, philo_routine, (void *)new) != 0)
		{
			destroy_philos(roundtable, counter);
			return (0);
		}
		++counter;
	}
	return (1);
}
