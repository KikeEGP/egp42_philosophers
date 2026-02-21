/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/21 20:14:40 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

/*
  	HERE YOU WILL FIND:
  	
	1) defined strings
	2) enums
	3) structs
*/

//Errors
# define EXPECTED_USAGE_1 "Error. Expected usage: ./philo n_philos time_to_die "
# define EXPECTED_USAGE_2 "time_to_eat time_to_sleep [n_meals for each philo]\n"
# define WRONG_ARG "Error. Some argument can't be converted to unsigned int\n"
# define ZERO_PHILOS "Error. n_philos's value can't be 0\n"
//
//Logs (messages for 'any state change of a philosopher')
# define TAKE_FORK "%llu %d has taken a fork\n" 
# define EAT "%llu %d is eating\n"
# define SLEEP "%llu %d is sleeping\n"
# define THINK "%llu %d is thinking\n"
# define DIE "%llu %d died\n"

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

//
//EAT_AND_STOP && NON_STOP are flags to count or not-count eaten meals,
//also check those counters or not
typedef enum e_flag_stop_eat
{
	EAT_AND_STOP,
	NON_STOP
}	t_flag_stop_eat;

//
/*INDEX FOR PARSE_DATA*/
typedef enum e_mutex_index
{
	INIT_MUTEX = 0,
	EATEN_TIMES_MUTEX,
	DIE_MUTEX,
	PRINT_MUTEX,
	MAX_MUTEX
}	t_mutex_index;

//
/*Flags to check what must be destroyed and free*/
typedef enum e_creation_failed
{
	CLEAN_UP_COMPLETED = 0,
	FREE_ALLOCATIONS = 0,
	MUTEX_FAILED = 0,
	DESTROY_MUTEX = 1,
	GET_TIME_FAILED = 1,
	PHILOS_DELETED = 1,
	DESTROY_PHILOS = 2,
	DELPHI_ORACLE_FAILED = 2,
	DESTROY_DELPHI_ORACLE = 3,
	SUCCESS_RETURN = 4
}	t_creation_failed;

//Purpose: Check if fork is free, so philo still think and can check
//		if delphi_oracle sets somebody has died
typedef enum e_fork_state
{
	FORK_TAKEN = 0,
	FORK_FREE
}	t_fork_state;

//Index of t_philo->hands[] (mutex)
typedef enum e_mutex_philo_hands
{
	LEFT = 0,
	RIGHT,
	BOTH_HANDS
}	t_mutex_philo_hands;

//Time values are ms, miliseconds. 1 sec == 1.000 ms. 
//ms will be stored in unsigned long long. "delphi_oracle" == monitor, observer
typedef struct s_symposium
{
	unsigned int		num_philos;
	unsigned long long	start;
	unsigned long long	die_time;
	unsigned long long	eat_time;
	unsigned long long	sleep_time;
	unsigned int		eat_min_times;
	int					flag_stop_eat;
	int					dead_found;
	pthread_mutex_t		symp_mutex[MAX_MUTEX];
	pthread_mutex_t		*fork_mutex;
	int					threads_ready;
	pthread_t			delphi_oracle;
	struct s_philo		*philos_array;
}	t_symposium;

//This struct is for every philo. All of them, stored in philos_array, above
typedef struct s_philo
{
	int					id;
	unsigned long long	last_meal;
	unsigned int		eaten_times;
	pthread_t			thread;
	int					fork;
	int					left_target;
	int					right_target;
	pthread_mutex_t		hands[2];
	t_symposium			*symposium;
}	t_philo;

#endif
