/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/21 15:29:52 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	back_fork(t_philo *ph)

{
	ph->table->fork[ph->id] = 0;
	if (ph->id != ph->table->number_of_philo)
	{	
		ph->table->fork[ph->id + 1] = 0;
		UNLOCK(&ph->table->mutex_fork[ph->id]);
		UNLOCK(&ph->table->mutex_fork[ph->id + 1]);
	}
	else
	{
		ph->table->fork[0] = 0;
		UNLOCK(&ph->table->mutex_fork[ph->id]);
		UNLOCK(&ph->table->mutex_fork[0]);
	}
}


void	eat(t_philo *ph)

{
	printf("[%ld]ms %i is eating\n", get_time(), ph->index);
	back_fork(ph);
	usleep(ph->table->time_to_eat * 1000);
}

void	think(t_philo *ph)

{
	if (!(ph->id % 2) && (ph->table->number_of_philo % 2))
		usleep(600);
	printf("[%ld]ms %i is thinking\n", get_time(), ph->index);
}

void	dreams(t_philo *ph)

{
	printf("[%ld]ms %i is sleeping\n", get_time(), ph->index);
}

void	test(t_philo *ph)

{
	printf("[%ld]ms %i eat [%i] times\n", get_time(), ph->index, ph->table->must_eat);
}