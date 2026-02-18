/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_states.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:36:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/18 20:22:12 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	eat(t_symposium *table, t_philo *philo)
{
	//Take first fork
	//	Depends on id is even or odd
	//Take second fork
	//Do i need this?	pthread_mutex_lock(&table->symp_mutex[EAT_MUTEX]);
	get_unix_time(&philo->last_meal);
	state_change_log(EAT, philo, table);
	//Do I need this?	pthread_mutex_unlock(&table->symp_mutex[EAT_MUTEX]);
}
