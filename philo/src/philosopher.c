/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:57:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/07 10:55:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_table *table)

{
	int	i;

	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_destroy(&table->m_fork[i]);
	pthread_mutex_destroy(&table->creed);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->l_meal);
	pthread_mutex_destroy(&table->print);
	free(table->m_fork);
}

void	one_dinner(t_philo *ph)

{
	print(FORK, ph);
	smart_sleep(ph->table->time_die, ph);
	print_death(ph[0]);
}

int	main(int argc, char **argv)

{
	t_table	table;

	if (!ft_valid_argc(argc, argv) || !init_vars(&table, argc, argv))
		return (0);
	table.ph = malloc(sizeof(t_philo) * table.n_philo);
	pthread_mutex_init(&table.creed, NULL);
	init_fork(&table);
	start_philo(&table, table.n_philo);
	finish_philo(&table, table.n_philo);
	return (0);
}
