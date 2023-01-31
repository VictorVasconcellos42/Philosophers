/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:01:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/28 09:53:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_menu(t_philo *ph)

{
	if (ph->id % 2 == 0)
		usleep(500);
}

void	take_fork(t_philo *ph)

{
	if (ph->id % 2 && ph->index != ph->table->n_philo)
	{
		pthread_mutex_lock(&ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->l_fork] = 0;
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->r_fork] = 0;
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
	}
	else
	{
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->r_fork] = 0;
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
		pthread_mutex_lock(&ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->l_fork] = 0;
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
	}
}
