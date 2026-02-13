/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:32:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/13 14:46:29 by enrgil-p         ###   ########.fr       */
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

//Created for clen in every case, now is only expected in case of successful
//end of execution. In any case, I prefer to guarantee that program pass
//a flag of SUCCESS_RETURN
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

//Like clean_up, only for fails while create_symposium though.
//Main difference consist in need of unlock init's mutex 
//after threads have been joined
static int	abort_symposium(t_symposium *roundtable, int error)
{
	while (1)
	{
		if (error == MALLOC_FAILED)
		{
			single_clean(roundtable, DESTROY_MUTEX);
			break ;
		}
		else if (error == PHILOS_DELETED)
		{
			print_message("Error: failed while creating philos\n", 2);
			single_clean(roundtable, FREE_PHILOS_ARRAY);
			pthread_mutex_unlock(&mutex[INIT]);//Locked after malloc
			//Before destroy mutex, they have to be unlocked
		}
		else if (error == DELPHI_ORACLE_FAILED)
		{
			print_message("Error: failed creating delphi_oracle\n", 2);
			single_clean(roundtable, DESTROY_PHILOS);
		}
		--error;
	}
	return (0);
}
