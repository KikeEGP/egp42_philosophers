/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:05:34 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/28 10:58:46 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <unistd.h>//write, usleep
# include <stdio.h>//printf
# include <stdlib.h>//malloc, free
# include <string.h>//memset
# include <pthread.h>
# include <sys/time.h>//gettiimeofday
# include "definitions.h"

/*	*	utils.c	*	*/
size_t	ft_strlen(const char *str);
void	print_message(char *message, int fd);
/*	*	*	*	parse.c	*	*	*	*	*/
int		parse_arguments(int argc, char **argument, unsigned int *data);
/*	* parse_utils.c	*	*/
int		char_is_digit(int c);

#endif
