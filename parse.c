/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:11:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/24 12:22:31 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	check_chars(char *argument)
{
	int	i;
	
	i = 0;
	while (argument[i] != '\0')
	{
		if (!char_is_digit(argument[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argument)
{
	while (--argc > 1)
	{
		if (!check_chars(argument[argc]))
			//message and return (0)
	}
	//n_philos, integer or more? Max_num?
}
