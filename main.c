/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/16 23:24:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	print_expected_usage(int error_fd)
{
	print_message(EXPECTED_USAGE_1, error_fd);
	print_message(EXPECTED_USAGE_2, error_fd);
}

static void	*test(void *philo)
{
	unsigned int *array = (unsigned int *)philo;
	int	flag = 0;

	while (!flag)
	{
		if (array[TIME_SLEEP] == 1)
		{
			flag = 1;
			array[NUM_PHILOS] += 10;
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	unsigned int	parse_data[argc - 1];
	pthread_t	thread;//testing
	pthread_mutex_t	mutex;//I could add this to a struct, and pass this
			      //struct as argument for thread routine
			      //In this way, main and thread would try to 
			      //block same mutex

	if (argc == 5 || argc == 6)
	{
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		pthread_create(&thread, NULL, test, (void *)parse_data);
		pthread_mutex_init(&mutex, NULL);
		pthread_mutex_lock(&mutex);
		printf("Before thread, num philos is %d\n", parse_data[NUM_PHILOS]);//debug
		parse_data[NUM_PHILOS] += 4;
		printf("Before pthread_join, increased one to num philos, so is %d\n", parse_data[NUM_PHILOS]);//debug
		//In some cases, increase first here, in others, in thread
		//pthread_detach(thread);//In case of detach, sometimes thread
		//	has operated, in others is detached before
		parse_data[TIME_SLEEP] = 1;
		pthread_mutex_unlock(&mutex);
		parse_data[NUM_PHILOS] += 100;
		pthread_join(thread, NULL);
		printf("After thread, num philos is %d\n", parse_data[NUM_PHILOS]);//debug
		//Create philos and forks
		pthread_mutex_destroy(&mutex);
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
