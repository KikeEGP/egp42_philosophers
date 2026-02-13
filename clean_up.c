/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:32:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/13 14:16:21 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	return_error(int *return_status)
{
	*return_status = 0;
}

int	single_clean(t_symposium *data, int now_it_is_turn_to)
{
	if (now_is_turn_to == DESTROY_MUTEX)//Last to manage
		return (/*function to destroy mutex*/);
	else if (now_is_turn_to == FREE_PHILOS_ARRAY)
		free(data->philos_array);
	else if (now_is_turn_to == DESTROY_PHILOS)
		return (/*function to destroy mutex*/);
	else if (now_is_turn_to == DESTROY_DELPHI_ORACLE)//First to manage
		return (/*function to destroy mutex*/);
	return (1);
}

int	clean_up(t_symposium *data, int clean_index)
{
	int	return_status;

	return_error(&return_status);
	if (clean_index == SUCCESS_RETURN)
	{
		return_status = 1;
		--clean_index;
	}
	while (clean_index >= CLEAN_UP_COMPLETED)
	{
		if (!single_clean(data, clean_index) && return_status)
			return_error(&return_status);
		--clean_index;
	}
}
