/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:44:34 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/02/11 20:33:33 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//1 sec == 1000 ms. tv_Sec == seconds, signed integer
//tv_usec == µs, microsecond, signed integer 
//	from -1 to 1.000.000 (value of 1 sec). 1 ms == 1000 µs
int	get_time(unsigned long long *time_in_ms)
{
	struct timeval		unix_time;

	*time_in_ms = 0;
	if (gettimeofday(&unix_time, NULL) == -1)
	{
		print_message("Error: gettimeofday failed\n", 2);
		return (0);
	}
	*time_in_ms = (unix_time.tv_sec * 1000) + (unix_time.tv_usec / 1000);
	return (1);
}

int	check_time(unsigned long long last_meal,
		unsigned long long time_to_check)
{
	unsigned long long	now;

	if (!get_time(&now))
		return (2);
	if ((now - last_meal) >= time_to_check)
		return (0);
	return (1);
}
