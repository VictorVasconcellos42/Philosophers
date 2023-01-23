/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 10:39:02 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	smart_sleep(long duration, t_philo *ph)

{
    long    start_time;

    start_time = time_now(ph);
    while (time_now(ph) - start_time < duration)
		usleep(100);
}

void	back_fork(t_philo *ph)

{
	ph->table->fork[ph->id] = 1;
	if (ph->id != ph->table->number_of_philo)
	{	
		UNLOCK(&ph->table->mutex_fork[ph->id]);
		UNLOCK(&ph->table->mutex_fork[ph->id + 1]);
		ph->table->fork[ph->id + 1] = 1;
		if (ph->table->fork[ph->id + 1] == 1)
			printf("[%ld]ms %i put a fork in table\n", time_now(ph), ph->index);
		printf("[%ld]ms\t%i put a fork in table\n", time_now(ph), ph->index);
	}
	else
	{
		UNLOCK(&ph->table->mutex_fork[ph->id]);
		UNLOCK(&ph->table->mutex_fork[0]);
		ph->table->fork[0] = 1;
		if (ph->table->fork[0] == 1)
			printf("[%ld]ms %i put a fork in table\n", time_now(ph), ph->index);
		printf("[%ld]ms %i put a fork in table\n", time_now(ph), ph->index);
	}
}


void	eat(t_philo *ph)

{
	//if (!(ph->id % 2) && (ph->table->number_of_philo % 2))
	//	usleep(5000);
	printf("[%ld]ms\t%i is eating\n", time_now(ph), ph->index);
	smart_sleep(ph->table->time_to_eat, ph);
	back_fork(ph);
}

void	think(t_philo *ph)

{
	printf("[%ld]ms\t%i is thinking\n", time_now(ph), ph->index);
}

void	dreams(t_philo *ph)

{
	printf("[%ld]ms\t%i is sleeping\n", time_now(ph), ph->index);
	smart_sleep(ph->table->time_to_sleep, ph);
}