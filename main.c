/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:04:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/08/03 21:17:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include <stdio.h>//DELETE THIISSSSSSSSSS

static void	print_expected_usage(int error_fd)
{
	print_message(EXPECTED_USAGE_1, error_fd);
	print_message(EXPECTED_USAGE_2, error_fd);
}

int	main(int argc, char **argv)
{
	unsigned int	parse_data[argc - 1];

	if (argc == 5 || argc == 6)
	{
		if (!parse_arguments(argc, argv, parse_data))
			return (1);
		printf("%u is third element of array\n", parse_data[2]);//debug
		return (0);
	}
	else
		print_expected_usage(2);
	return (1);
}
