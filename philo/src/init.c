/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:03:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/18 15:55:34 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)

{
	struct timeval	tp;
	long		milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

static int	valid_times(t_config *table)

{
	if (table->time_to_die < 60 || \
	table->time_to_eat < 60 || \
	table->time_to_sleep < 60)
		return (error_philo_and_time());
	return (TRUE);
}

int	init_vars(t_config *table, int argc, char **argv)

{
	table->number_of_philo = atoi(argv[1]);
	table->time_to_die = atoi(argv[2]);
	table->time_to_eat = atoi(argv[3]);
	table->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		table->must_eat = atoi(argv[5]);
	else
		table->must_eat = -1;
	if (valid_times(table) == FALSE)
		return (FALSE);
	return (TRUE);
}
