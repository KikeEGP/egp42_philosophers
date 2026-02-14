/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:20:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/14 18:09:48 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_message(char *message, int fd)
{
	size_t	len_message;

	len_message = ft_strlen(message);
	write(fd, message, len_message);
}

/*
void	state_change_log(char *message, *time?*, t_symposium *data)
{
	//Obtain time??
	t_philo	philo;

	philo = data->philos_array[*index?*];
	printf(message, *time*, philo->id);
}*/
