/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:03:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/18 15:29:12 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	get_ms_time(int seconds)

{
	return (seconds * 1000);
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
