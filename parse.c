/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:11:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/28 11:25:16 by enrgil-p         ###   ########.fr       */
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

static int	check_valid_int(unsigned int result, int atoi_count, char *str)
{
	if (count > 10 && result == INT_MAX || /*In push_swap, 
						 I call ft_atoi to check here
						 if atoi == protected_atoi*/)
		return (0);
	return (1);
}

static int	string_to_int(char *source_str, unsigned int &result)
{
	int		atoi_counter;

	*result = 0;
	atoi_counter = 0;
	*result = ft_atoi_protected(source_str, &atoi_counter);
	if (!check_valid_int(*result, atoi_counter, source_str))
		//if data == UNSIGNED_INT__MAX, check if it is true
		return (0);
	return (1);
}

int	parse_arguments(int argc, char **argument, unsigned int *data)
{
	while (--argc > 1)
	{
		if (!check_chars(argument[argc])
			|| !string_to_int(argument[argc], &data[argc]))
		{
			print_message(WRONG_ARG, 2);
			return (0);
		}
	}
	return (1);
}
