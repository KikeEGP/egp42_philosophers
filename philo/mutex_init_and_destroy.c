/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_and_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:07:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/26 12:04:31 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//Error message were so useful to debug
int	destroy_single_mutex(pthread_mutex_t *mutex)
{
	int	check;

	check = 0;
	check = pthread_mutex_destroy(mutex);
	if (check != 0)
	{
		print_message("Error. A mutex destroy has failed\n", 2);
		return (0);
	}
	return (1);
}

int	init_single_mutex(pthread_mutex_t *mutex)
{
	int	check;

	check = 0;
	check = pthread_mutex_init(mutex, NULL);
	if (check != 0)
	{
		print_message("Error. A mutex init has failed\n", 2);
		return (0);
	}
	return (1);
}

int	destroy_array_mutex(pthread_mutex_t *array, int max_index)
{
	int	return_status;
	int	i;

	return_status = 1;
	i = 0;
	while (i < max_index)
	{
		if (!destroy_single_mutex(&array[i]))
			return_status = 0;
		++i;
	}
	return (return_status);
}

int	init_array_mutex(pthread_mutex_t *array, int max_index)
{
	int	i;

	i = 0;
	while (i < max_index)
	{
		if (!init_single_mutex(&array[i]))
		{
			destroy_array_mutex(array, i);
			return (0);
		}
		++i;
	}
	return (1);
}
