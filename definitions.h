/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/17 20:51:43 by enrgil-p         ###   ########.fr       */
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

typedef struct s_symposium
{
	unsigned int	num_philos;
	unsigned int	die_time;
	unsigned int	eat_time;
	unsigned int	sleep_time;
	unsigned int	eat_min_times;
	pthread_mutex_t	init_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	print_mutex;
	int				threads_ready;
	pthread_t		delphi_oracle;//Observer
	struct s_philo	*philos_array;
}	t_symposium;

//This struct is for every philo. All of them, stored in philos_array, above
typedef struct s_philo
{
	int				id;//Integer or unsigned?
	pthread_t		thread;
	pthread_mutex_t	fork;
}	t_philo;

#endif
