/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_and_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:07:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/14 17:45:44 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

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

int	destroy_symposium_mutex(t_symposium *data, int max_index)
{
	int	i;

	i = 0;
	while (i < max_index)
	{
		if (!destroy_single_mutex(&data.mutex[i]))
		{//Really? Return 0? And doesn't continue trying to destroy?
			return (0);
		}
		++i;
	}
	return (1);
}

int	init_symposium_mutex(t_symposium *data)
{
	int	i;

	i = 0;
	while (i < MAX_MUTEX)
	{
		if (!init_single_mutex(&data.mutex[i]))
		{//Avoid a next if, never nest
			if (!destroy_symposium_mutex(data, i))//Do I need this?
				return (0);//In any case, I will return 0
			return (0);
		}
		++i;
	}
	return (1);
}
