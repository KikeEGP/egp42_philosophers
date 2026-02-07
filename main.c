/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/07 19:16:40 by enrgil-p         ###   ########.fr       */
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
	t_symposium	program_data;

	if (argc == 5 || argc == 6)
	{
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		if (argc == 6 && parse_data[EAT_MIN_TIMES] == 0)
			return (0);//Is this allowed? Maybe, but better
				   //create symposium and let stop a little
				   //bit lower
		//Create philos and forks
		if (!create_symposium(parse_data, &program_data))
			return (1);
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
