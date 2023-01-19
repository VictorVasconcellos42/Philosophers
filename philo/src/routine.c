/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/19 18:56:44 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_philo *ph)

{
	if (ph->right == 1 && ph->left == 1)
		printf("[%ld]ms %i is eating\n", get_time(), ph->index);
	pthread_mutex_unlock(&ph->table->mutex_fork[ph->index + 1 % ph->index]);
	ph->right = 0;
	ph->left = 0;
	pthread_mutex_unlock(&ph->table->mutex_fork[ph->index]);
	usleep(1000);
}

void	think(t_philo *ph)

{
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