/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/15 19:00:51 by enrgil-p         ###   ########.fr       */
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
	t_symposium		program_data;
	unsigned int	parse_data[MAX_ARGS];
	int				flag_stop_eat;

	if (argc == 5 || argc == 6)
	{
		flag_stop_eat = NON_STOP;
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		if (argc == 6 && parse_data[EAT_MIN_TIMES] == 0)
			flag_stop_eat = EAT_AND_STOP;
		if (!create_symposium(parse_data, &program_data, flag_stop_eat))
			return (1);
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
