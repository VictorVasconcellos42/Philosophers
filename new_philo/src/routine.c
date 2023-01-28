/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:05:59 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/28 09:52:56 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eat(t_philo *ph)
{
	if (ph->id % 2)
	{
		printf("%lu\t%i is eating\n", time_now(ph), ph->index);
		smart_sleep(ph->table->time_eat, ph);
		ph->table->fork[ph->l_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->r_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
	}
	else
	{
		printf("%lu\t%i is eating\n", time_now(ph), ph->index);
		smart_sleep(ph->table->time_eat, ph);
		ph->table->fork[ph->r_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->l_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
	}
}

void	think(t_philo *ph)

{
	printf("%ld\t%i is thinking\n", time_now(ph), ph->index);
}

void	dreams(t_philo *ph)

{
	printf("%ld\t%i is sleeping\n", time_now(ph), ph->index);
	smart_sleep(ph->table->time_dream, ph);
}
