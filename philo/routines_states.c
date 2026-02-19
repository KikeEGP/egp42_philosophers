/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/19 20:07:59 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static /**/	take_both_forks(t_symposium *table, t_philo *philo)
{
	unsigned int	left;
	unsigned int	right;

	left = philo->id;
	if ()
	if (table->num_philos == 1 && philo->id == 1)
		//take one fork and wait to die;
	else if (philo->id % 2 != 0)
	{
		take_fork(table->fork_mutex[n]);
		take_fork(table->fork_mutex[n - 1]);
	}
	else
	{
		take_fork(table->fork_mutex[n - 1]);
		take_fork(table->fork_mutex[n]);
	}
}

void	eat(t_symposium *table, t_philo *philo)
{
	//take_both_forks();
	//Take first fork
	//	Depends on id is even or odd
	//Take second fork
	get_unix_time(&philo->last_meal);
	state_change_log(EAT, philo, table);
}
