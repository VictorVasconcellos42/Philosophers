/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:53:43 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/21 15:24:32 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_menu(t_philo *ph)

{
	if (ph->id % 2 == 0)
		usleep(600);
}

int	take_fork(t_philo *ph)

{
	LOCK(&ph->table->mutex_fork[ph->id]);
	if (ph->index != ph->table->number_of_philo)
	{
		LOCK(&ph->table->mutex_fork[ph->id + 1]);
		if (ph->table->fork[ph->id] == 1 && ph->table->fork[ph->id + 1] == 1)
		{
			ph->table->fork[ph->id] = 0;
			ph->table->fork[ph->id + 1] = 0;			
			printf("[%ld]ms %i taken a fork\n", get_time(), ph->index);
			printf("[%ld]ms %i taken a fork\n", get_time(), ph->index);
			return (1);
		}
		else
		{	
			UNLOCK(&ph->table->mutex_fork[ph->id]);
			UNLOCK(&ph->table->mutex_fork[ph->id + 1]);
			return (0);
		}
	}
	else
	{	
		LOCK(&ph->table->mutex_fork[0]);
		if (ph->table->fork[ph->id] == 1 && ph->table->fork[0] == 1)
		{
			ph->table->fork[ph->id] = 0;
			ph->table->fork[0] = 0;
			printf("[%ld]ms %i taken a fork\n", get_time(), ph->index);
			printf("[%ld]ms %i taken a fork\n", get_time(), ph->index);
			return (1);
		}
		else
		{	
			UNLOCK(&ph->table->mutex_fork[ph->id]);
			UNLOCK(&ph->table->mutex_fork[0]);
			return (0);
		}	
	}
}