/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:11:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/26 22:10:48 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	check_chars(char *argument)
{
	int	i;
	
	i = 0;
	if (argument[i] != '+' && !char_is_digit(argument[i]))
		return (0);
	while (argument[++i] != '\0')
	{
		if (!char_is_digit(argument[i]))
			return (0);
	}
	return (1);
}

unsigned int	array_to_unsigned_int(char *argument)
{
	unsigned int	result;

	result = 0;
	//ft_atol
	//check result
}

int	parse_arguments(int argc, char **argument, unsigned int **data)
{
	while (--argc > 1)
	{
		if (!check_chars(argument[argc]))
			//message and return (0)
		*data[argc] = array_to_unsigned_int(argument[argc]);
		//if data == UNSIGNED_INT__MAX, check if it is true
	}
	//n_philos, integer or more? Max_num?
}
