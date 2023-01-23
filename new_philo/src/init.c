/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:56:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 15:16:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_fork(t_table *table)

{
	int	i;

	i = -1;
	table->m_fork = malloc(sizeof(t_mutex) * table->n_philo);
	table->fork = malloc(sizeof(int) * table->n_philo);
	while (++i < table->n_philo)
	{
		pthread_mutex_init(&table->m_fork[i], NULL);
		table->fork[i] = 1;
	}
}

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
