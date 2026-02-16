/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:49:16 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/15 18:52:52 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	wait_all_threads(t_symposium *data)
{
	while (data->threads_ready != 1)
	{
		if (data->threads_ready)
			break ;
	}
	return ;
}
