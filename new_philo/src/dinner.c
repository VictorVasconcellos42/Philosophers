/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:01:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 20:05:20 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_menu(t_philo *ph)

{
	if (ph->id % 2 != 0)
		usleep(600);
}

void	take_fork(t_philo *ph)

{
	if (ph->id % 2 != 0)
	{
		lock(ph->table->m_fork[ph->l_fork]);
		lock(ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->l_fork] = 0;
		ph->table->fork[ph->r_fork] = 0;		
	}
	else
	{
		lock(ph->table->m_fork[ph->r_fork]);
		lock(ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->l_fork] = 0;
		ph->table->fork[ph->r_fork] = 0;
	}
}