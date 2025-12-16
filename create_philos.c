/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:59:00 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/12/16 20:12:58 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//pmendez created philos direclty with a start_routine function that was 
//the whole states and actions expected from philosophers

/*void?*/	create_philos(unsigned int *data)
{
	int	philos_counter;

	philos_counter = 0;
	while (++philos_counter <= data[NUM_PHILOS])
	{
		//Create a thread, and a fork too
		//	I guess this means: struct with times and create mutex
		//	Remember, pmendez talked about five mutex, and people
		//	use to create those five
	}
}
