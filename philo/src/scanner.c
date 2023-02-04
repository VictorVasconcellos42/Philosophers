/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/04 16:03:48 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	print_death(t_philo ph)

{
	pthread_mutex_lock(&ph.table->print);
	printf("%s%lu\t%i died\n%s", RED, time_now(&ph), ph.index, END);
	pthread_mutex_unlock(&ph.table->print);
}

int	scan(t_table *table)

{
	int	i;

	i = 0;
	usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&table->l_meal);
		if (time_now(table->ph) - table->ph[i].last_meal > table->time_die)
		{
			pthread_mutex_lock(&table->dead);
			table->died = 1;
			print_death(table->ph[i]);
			pthread_mutex_unlock(&table->l_meal);
			break ;
		}
		pthread_mutex_unlock(&table->l_meal);
		i = (i + 1) % table->n_philo;
	}
	pthread_mutex_unlock(&table->dead);
	return (TRUE);
}
