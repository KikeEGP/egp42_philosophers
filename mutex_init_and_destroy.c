/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_and_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:07:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/18 17:08:08 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	init_symposium_mutex(t_symposium *data)
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
			print_message("Error. A mutex init has failed\n", 2);
			return (0);
		}
		++i;
	}
	return (1);
}
