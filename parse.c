/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:11:56 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/01/08 20:26:47 by enrgil-p         ###   ########.fr       */
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

static int	ft_atouint_protected_philo(const char *str, int *counter)
{
	long	result;

	result = 0;
	*counter = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32 || *str == '+'
		|| (*str == '0' && *(str + 1) != '\0'))
		++str;
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result + (*str++ - '0');
		++(*counter);
	}
	if (result > UINT_MAX || *counter > 10)
		return (0);
	return (result);
}

static int	string_to_int(char *source_str, unsigned int *result)
{
	int		atouint_counter;

	*result = 0;
	atouint_counter = 0;
	*result = ft_atouint_protected_philo(source_str, &atouint_counter);
	if ((*result == 0 && atouint_counter > 1) || !atouint_counter)
		return (0);
	return (1);
}

//Parse args. Store them in an array of unsigned int
int	parse_arguments(int argc, char **argument, unsigned int *data)
{
	if (argc == 5)
		data[EAT_MIN_TIMES] = 0;//Added 8/1/26, for cases not called it
	while (--argc >= 1)
	{
		if (!check_chars(argument[argc])
			|| !string_to_int(argument[argc], &data[argc - 1]))
		{
			print_message(WRONG_ARG, 2);
			return (0);
		}
	}
	if (data[0] == 0)
	{
		print_message(ZERO_PHILOS, 2);
		return (0);
	}
	return (1);
}
