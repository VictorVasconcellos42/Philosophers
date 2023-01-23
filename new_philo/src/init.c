/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:56:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 12:03:59 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_vars(t_table *table, int argc, char **argv)

{
	table->n_philo = atoi(argv[1]);
	table->time_die = atoi(argv[2]);
	table->time_eat = atoi(argv[3]);
	table->time_dream = atoi(argv[4]);
	table->start_clock = get_time();
	if (argc == 6)
		table->m_eat = atoi(argv[5]);
	else
		table->m_eat = -1;
	if (!valid_times(table))
		return (FALSE);
	return (TRUE);
}
