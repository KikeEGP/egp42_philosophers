/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_and_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:07:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/18 17:18:16 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	destroy_symposium_mutex(t_symposium *data, int max_index)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < max_index)
	{
		check = pthread_mutex_destroy(&data->mutex[i]);
		if (check != 0)
		{
			print_message("Error. A mutex destroy has failed\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}

int	init_symposium_mutex(t_symposium *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < MAX_MUTEX)
	{
		check = pthread_mutex_init(&data->mutex[i], NULL);
		if (check != 0)
		{
			if (!destroy_symposium_mutex(data, i))
				return (0);
			print_message("Error. A mutex init has failed\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}
