/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:20:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/18 19:50:59 by enrgil-p         ###   ########.fr       */
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


void	state_change_log(char *message, t_philo *philo, t_symposium *data)
{
	unsigned long long	current_time;

	pthread_mutex_lock(&data->symp_mutex[PRINT_MUTEX]);
	get_program_time(&current_time, data);//This function needs an if
	printf(message, current_time, philo->id);
	pthread_mutex_unlock(&data->symp_mutex[PRINT_MUTEX]);
}
