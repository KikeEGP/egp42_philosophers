/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:08:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/14 19:21:02 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	delphi_oracle_routine(void *data)
{
	t_symposium	symp;

	symp = (t_symposium)data;
	printf("Hello, i'm delphi orcale\n");
	/*Wait to symposium->threads_ready
	Check if philos are alive
		//symp.philos_array[all].life_timer < symp.die_time
	Check if some error?
	if (symposium->eat_min_times != 0)
		check_all_eaten_min_times*/
}

void	philo_routine(void *data)
{
	t_symposium	symp;
	
	symp = (t_symposium)data;
	printf("Hello\n");
	//Log states function is already defined on utils.c
//	Wait to symposium->threads_ready
/*	if (philo->id % 2 == 0)
		sleep(/?*);
	while (*delphi_oracles orders stop*)
	{
		take_forks();//if n % 2 == 0, fork n - 1, else fork n
				//Later, take the other
				//philo 1 takes fork 1 and fork n
				//This actions locks 2 mutex and prints 2 logs 
		eat();
			//life_timer restarts to 0
			//if symp.eat_min_times != 0
			//symp.philos_array[index == n - 1].eaten_times += 1;
			//Prints log
		drop_forks();//Doesn't print logs. Between eat time and sleep?
				//Same order as take_froks?
		sleep_action();//Sleeps, then prints message
		think();//Prints log of thinking
			//Think is only time since philo has awaken 
			//and starts to eat again. This means: waits free fork
	}*/
}
