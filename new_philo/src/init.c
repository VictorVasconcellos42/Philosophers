/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:56:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/28 19:47:38 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*dinner(void *ph)

{
	t_philo	*filo;

	filo = (t_philo *)ph;
	check_menu(filo);
	while (DINNER)
	{
		take_fork(filo);
		eat(filo);
		dreams(filo);
		think(filo);
	}
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
		pthread_create(&table->ph[i].philo, NULL, &dinner, &table->ph[i]);
	}
}

void	finish_philo(t_table *table, int t_philo)

{
	int	i;

	i = 0;
	while (i < t_philo)
		pthread_join(table->ph[i++].philo, NULL);
}

void	init_fork(t_table *table)

{
	int	i;

	i = -1;
	table->m_fork = malloc(sizeof(t_mutex) * table->n_philo);
	table->fork = malloc(sizeof(int) * table->n_philo);
	pthread_mutex_init(&table->creed, NULL);
	pthread_mutex_init(&table->print, NULL);
	while (++i < table->n_philo)
	{
		pthread_mutex_init(&table->m_fork[i], NULL);
		table->fork[i] = 1;
	}
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
