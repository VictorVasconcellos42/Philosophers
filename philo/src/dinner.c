/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:53:43 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/19 18:54:23 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_menu(t_philo *ph)

{
	if (ph->index % 2 != 0)
		usleep(600);
}

void	take_fork(t_philo *ph)

{
	if (ph->index % 2 == 0)
	{
		pthread_mutex_lock(&ph->table->mutex_fork[ph->index + 1 % ph->index]);
		ph->table->fork[ph->index + 1 % ph->index] = 0;
		ph->left = 1;
		pthread_mutex_lock(&ph->table->mutex_fork[ph->index]);
		ph->table->fork[ph->index] = 0;
		ph->right = 1;
	}
	else
	{
		pthread_mutex_lock(&ph->table->mutex_fork[ph->index]);
		ph->table->fork[ph->index + 1 % ph->index] = 0;
		ph->right = 1;
		pthread_mutex_unlock(&ph->table->mutex_fork[ph->index]);
		pthread_mutex_lock(&ph->table->mutex_fork[ph->index + 1 % ph->index]);
		ph->table->fork[ph->index] = 0;
		ph->left = 1;
		pthread_mutex_unlock(&ph->table->mutex_fork[ph->index + 1 % ph->index]);		
	}
		
}