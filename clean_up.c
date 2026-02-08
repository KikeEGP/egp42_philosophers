/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:32:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/08 19:49:17 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	return_error(int *return_status)
{
	*return_status = 0;
}

static int	check_index_and_clean(t_symposium, int now_it_is_turn_to)
{
	if (now_is_turn_to == /*something*/)//Repeat this
					    //Do something
					    //If it's okay, return 1
}

int	clean_up(t_symposium *data, int clean_index)
{
	int	return_status;

	return_error(&return_status);
	if (clean_index-- == SUCCESS_RETURN)
		return_status = 1;
	while (clean_index >= CLEAN_UP_COMPLETED)
	{
		if(!check_index_and_clean(data, clean_index) && return_status)
			return_error(&return_status);
		--clean_index;
	}
}
