/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:56:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/07 09:50:23 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*dinner(void *t)

{
	t_philo	*ph;

	ph = (t_philo *)t;
	if (ph->table->n_philo == 1)
	{
		one_dinner(ph);
		return (NULL);
	}
	check_menu(ph);
	while (DINNER)
	{
		if (ph->ate == ph->table->m_eat)
			break ;
		pthread_mutex_lock(&ph->table->dead);
		if (ph->table->died == 1)
			break ;
		pthread_mutex_unlock(&ph->table->dead);
		take_fork(ph);
		eat(ph);
		dreams(ph);
		think(ph);
	}
	pthread_mutex_unlock(&ph->table->dead);
	return (NULL);
}

void	start_philo(t_table *table, int t_philo)

{
	int	i;

	i = -1;
	while (++i < t_philo)
	{
		table->ph[i].index = i + 1;
		table->ph[i].id = i;
		table->ph[i].l_fork = i;
		table->ph[i].table = table;
		table->ph[i].ate = 0;
		pthread_create(&table->ph[i].philo, NULL, &dinner, &table->ph[i]);
	}
	if (table->n_philo != 1)
		scan(table);
}

void	finish_philo(t_table *table, int t_philo)

{
	int	i;

	i = 0;
	while (i < t_philo)
		pthread_join(table->ph[i++].philo, NULL);
	free(table->ph);
}

void	init_fork(t_table *table)

{
	int	i;

	i = -1;
	table->m_fork = malloc(sizeof(t_mutex) * table->n_philo);
	pthread_mutex_init(&table->l_meal, NULL);
	pthread_mutex_init(&table->dead, NULL);
	pthread_mutex_init(&table->print, NULL);
	while (++i < table->n_philo)
		pthread_mutex_init(&table->m_fork[i], NULL);
	i = -1;
	while (++i < table->n_philo)
	{
		if (i == (table->n_philo - 1) && table->n_philo > 1)
			table->ph[i].r_fork = 0;
		else
			table->ph[i].r_fork = i + 1;
	}
}

int	init_vars(t_table *table, int argc, char **argv)

{
	table->died = 0;
	table->n_philo = ft_atol(argv[1]);
	table->time_die = ft_atol(argv[2]);
	table->time_eat = ft_atol(argv[3]);
	table->time_dream = ft_atol(argv[4]);
	table->start_clock = get_time();
	if (argc == 6)
		table->m_eat = ft_atol(argv[5]);
	else
		table->m_eat = -1;
	if (valid_times(table) == FALSE)
		return (FALSE);
	return (TRUE);
}
