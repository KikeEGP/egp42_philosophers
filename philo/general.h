/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:05:34 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/20 14:13:11 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

/*
  	HERE YOU WILL FIND:
 
  	1) header files needed by allowed functions for this project 
		that has been used
  	2) prototypes of functions created for this project
*/

# include <unistd.h>//write, usleep
# include <stdio.h>//printf
# include <stdlib.h>//malloc, free
# include <string.h>//memset
# include <pthread.h>
# include <sys/time.h>//gettiimeofday
# include <limits.h>//UINT_MAX
# include "definitions.h"

/*	*	utils.c	*	*/
size_t	ft_strlen(const char *str);
void	print_message(char *message, int fd);
void	state_change_log(char *message, t_philo *philo, t_symposium *data);
//
//
/*	*	*	*	parse.c	*	*	*	*	*/
int		parse_arguments(int argc, char **argument, unsigned int *data);
//
//
/*	*	*	* create_symposium.c	*	*	*	*/
int		create_symposium(unsigned int *data,
			t_symposium *roundtable, int flag_stop_eat);
//
//
/*	*	*	mutex_init_and_destroy.c	*	*	*/
int		destroy_single_mutex(pthread_mutex_t *mutex);
int		init_single_mutex(pthread_mutex_t *mutex);
int		destroy_array_mutex(pthread_mutex_t *array, int max_index);
int		init_array_mutex(pthread_mutex_t *array, int max_index);
//
//
/*	*	*	* clean_functions.c	*	*	*	*/
int		single_clean(t_symposium *data, int now_it_is_turn_to);
int		clean_up(t_symposium *data, int clean_index);
int		abort_symposium(t_symposium *roundtable, int error);
//
//
/*	*	*	*	time_manage.c	*	*	*	*/
int		get_unix_time(unsigned long long *time_in_ms);
int		get_program_time(unsigned long long *diff_in_ms, t_symposium *data);
int		check_time(unsigned long long last_meal,
			unsigned long long time_to_check);
//
//
/*	*	*	* philos_create_and_destroy.c	*	*	*/
int		destroy_philos(t_symposium *roundtable, int max_index);
int		create_philos(unsigned int *data, t_symposium *roundtable);
//
//
/*	*	*	* threads_routines.c	*	*	*	*/
void	*delphi_oracle_routine(void *data);
void	*philo_routine(void *data);
/*	*    routines_general_utils.c	*	*/
void	wait_all_threads(t_symposium *data, t_philo *philo);
void	set_target_forks(unsigned int *left, unsigned int *right,
			int philo_id, unsigned int num_philos);
/*	*    	routines_states.c	*	*/
void	eat(t_symposium *table, t_philo *philo);

#endif
