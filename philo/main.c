/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/22 19:17:23 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	print_expected_usage(int error_fd)
{
	print_message(EXPECTED_USAGE_1, error_fd);
	print_message(EXPECTED_USAGE_2, error_fd);
}

static int	set_flag_stop_eat(int argc)
{
	if (argc == 5)
		return (NON_STOP);
	else
		return (EAT_AND_STOP);
}

int	main(int argc, char **argv)
{
	t_symposium		program_data;
	unsigned int	parse_data[MAX_ARGS];
	int				flag_stop_eat;

	if (argc == 5 || argc == 6)
	{
		flag_stop_eat = set_flag_stop_eat(argc);
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		if (!create_symposium(parse_data, &program_data, flag_stop_eat))
			return (1);
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
