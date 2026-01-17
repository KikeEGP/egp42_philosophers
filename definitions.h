/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/17 18:19:56 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

//Errors
# define EXPECTED_USAGE_1 "Error. Expected usage: ./philo n_philos time_to_die "
# define EXPECTED_USAGE_2 "time_to_eat time_to_sleep [n_meals for each philo]\n"
# define WRONG_ARG "Error. Some argument can't be converted to unsigned int\n"
# define ZERO_PHILOS "Error. n_philos's value can't be 0\n"
//
# define MAX_ARGS 5
//
//Logs (messages for 'any state change of a philosopher')
# define TAKE_FORK "%u %d has taken a fork\n" 
# define EAT "%u %d is eating\n"
# define SLEEP "%u %d is sleeping\n"
# define THINK "%u %d is thinking\n"
# define DIE "%u %d died\n"
//
/*INDEX FOR PARSE_DATA*/

typedef enum e_parse_data_index
{
	NUM_PHILOS = 0,
	TIME_DIE,
	TIME_EAT,
	TIME_SLEEP,
	EAT_MIN_TIMES
}	t_parse_data_index;

typedef struct s_philo
{
	int		id;//Integer or unsigned?
	pthread_t	thread;//Or *thread??????
	/*type*/	fork;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_min_times;
}	t_philo;

#endif
