/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:05:59 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/04 17:12:11 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print(int action, t_philo *ph)

{
	pthread_mutex_lock(&ph->table->dead);
	pthread_mutex_lock(&ph->table->print);
	if (action == THINK && ph->table->died == 0)
		printf("%s%ld\t%i is thinking\n%s", BLUE, time_now(ph), ph->index, END);
	else if (action == DREAMS && ph->table->died == 0)
		printf("%s%ld\t%i is sleeping\n%s", GREEN, time_now(ph), ph->index, END);
	else if (action == EAT && ph->table->died == 0)
		printf("%s%lu\t%i is eating\n%s", YELLOW, time_now(ph), ph->index, END);
	else if (action == FORK && ph->table->died == 0)
		printf("%ld\t%i has taken a fork\n", time_now(ph), ph->index);
	pthread_mutex_unlock(&ph->table->print);
	pthread_mutex_unlock(&ph->table->dead);
}

void	eat(t_philo *ph)
{
	if (ph->id % 2 && ph->index != ph->table->n_philo)
	{
		print(EAT, ph);
		smart_sleep(ph->table->time_eat, ph);
		pthread_mutex_lock(&ph->table->l_meal);
		ph->last_meal = time_now(ph);
		pthread_mutex_unlock(&ph->table->l_meal);
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
	}
	else
	{
		print(EAT, ph);
		smart_sleep(ph->table->time_eat, ph);
		pthread_mutex_lock(&ph->table->l_meal);
		ph->last_meal = time_now(ph);
		pthread_mutex_unlock(&ph->table->l_meal);
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
	}
}

void	think(t_philo *ph)

{
	print(THINK, ph);
}

void	dreams(t_philo *ph)

{
	print(DREAMS, ph);
	smart_sleep(ph->table->time_dream, ph);
}
