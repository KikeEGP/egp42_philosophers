/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/12/11 22:21:55 by enrgil-p         ###   ########.fr       */
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
	array[NUM_PHILOS] += 10;
	return (NULL);
}

int	main(int argc, char **argv)
{
	unsigned int	parse_data[argc - 1];
	pthread_t	thread;//testing

	if (argc == 5 || argc == 6)
	{
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		pthread_create(&thread, NULL, test, (void *)parse_data);
		printf("Before thread, num philos is %d\n", parse_data[NUM_PHILOS]);//debug
		++parse_data[NUM_PHILOS];
		printf("Before pthread_join, increased one to num philos, so is %d\n", parse_data[NUM_PHILOS]);//debug
		pthread_join(thread, NULL);
		printf("After thread, num philos is %d\n", parse_data[NUM_PHILOS]);//debug
		//Create philos and forks
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
