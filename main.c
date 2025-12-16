/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/12/16 17:43:01 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	print_expected_usage(int error_fd)
{
	print_message(EXPECTED_USAGE_1, error_fd);
	print_message(EXPECTED_USAGE_2, error_fd);
}

int	main(int argc, char **argv)
{
	unsigned int	parse_data[MAX_ARGS];

	if (argc == 5 || argc == 6)
	{
		/*if (!parse_arguments(argc, argv, parse_data)
			|| !create_philos(parse_data))*/
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		create_philos(parse_data);
		//Create philos and forks
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
