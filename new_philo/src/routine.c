/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:05:59 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/31 14:58:01 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	print(int action, t_philo *ph)

{
	if (ph->table->died == 0)
	{
		pthread_mutex_lock(&ph->table->print);
		if (action == THINK)
			printf("%s%ld\t%i is thinking\n%s", BLUE, time_now(ph), ph->index, END);
		else if (action == DREAMS)
			printf("%s%ld\t%i is sleeping\n%s", GREEN, time_now(ph), ph->index, END);
		else if (action == EAT)
			printf("%s%lu\t%i is eating\n%s", RED, time_now(ph), ph->index, END);
		pthread_mutex_unlock(&ph->table->print);
	}
}

void	eat(t_philo *ph)
{
	if (ph->id % 2)
	{
		print(EAT, ph);
		smart_sleep(ph->table->time_eat, ph);
		ph->last_meal = time_now(ph);
		ph->table->fork[ph->l_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->l_fork]);
		ph->table->fork[ph->r_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
	}
	else
	{
		print(EAT, ph);
		smart_sleep(ph->table->time_eat, ph);
		ph->table->fork[ph->r_fork] = 1;
		pthread_mutex_unlock(&ph->table->m_fork[ph->r_fork]);
		ph->table->fork[ph->l_fork] = 1;
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
