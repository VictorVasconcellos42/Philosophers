/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:01:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/04 15:26:33 by vde-vasc         ###   ########.fr       */
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
		print(FORK, ph);
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->r_fork] = 0;
		print(FORK, ph);
	}
	else
	{
		pthread_mutex_lock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->r_fork] = 0;
		print(FORK, ph);
		pthread_mutex_lock(&ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->l_fork] = 0;
		print(FORK, ph);
	}
}
