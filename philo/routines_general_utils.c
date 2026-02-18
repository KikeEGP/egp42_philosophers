/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:49:16 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/18 19:33:40 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	wait_all_threads(t_symposium *data, t_philo *philo)
{
	while (data->threads_ready != 1)
	{
		if (data->threads_ready)
			break ;
	}
	if (philo && philo->id % 2 == 0)
		usleep(10000);
	return ;
}
