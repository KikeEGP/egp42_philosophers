/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/01 17:43:05 by enrgil-p         ###   ########.fr       */
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
	EAT_MIN_TIMES,
	MAX_ARGS
}	t_parse_data_index;

typedef enum e_mutex_index
{
	INIT = 0,
	EAT,
	SLEEP,
	EAT_MIN_TIMES,
	MAX_MUTEX
}	t_mutex_index;

//Time values are ms, miliseconds. 1 sec == 1.000 ms. 
//ms will be stored in unsigned long long
typedef struct s_symposium
{
	unsigned int		num_philos;
	unsigned long long	start;
	unsigned long long	die_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	unsigned int		eat_min_times;
	pthread_mutex_t		mutex[MAX_MUTEX];//Can I use an array?
		/*pthread_mutex_t	init_mutex;
		pthread_mutex_t	eat_mutex;
		pthread_mutex_t	sleep_mutex;
		pthread_mutex_t	die_mutex;
		pthread_mutex_t	print_mutex;*/
	int					threads_ready;
	pthread_t		delphi_oracle;//Observer
	struct s_philo		*philos_array;
}	t_symposium;

//This struct is for every philo. All of them, stored in philos_array, above
typedef struct s_philo
{
	int				id;//Integer or unsigned?
	//type??		life_timer;
	unsigned int			eaten_times;
	unsigned long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
}	t_philo;

#endif
