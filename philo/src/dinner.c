/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:53:43 by vde-vasc          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/22 15:50:08 by vasconcel        ###   ########.fr       */
=======
/*   Updated: 2023/01/23 09:58:03 by vde-vasc         ###   ########.fr       */
>>>>>>> 96e7a08ff32d37906a6eaa3ea63ae71ae802c1c1
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_menu(t_philo *ph)

{
	if (ph->id % 2 != 0)
		usleep(542);
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
			printf("[%ld]ms\t%i taken a fork\n", time_now(ph), ph->index);
			printf("[%ld]ms\t%i taken a fork\n", time_now(ph), ph->index);
			return (1);
		}
		else
		{
			UNLOCK(&ph->table->mutex_fork[ph->id]);
			UNLOCK(&ph->table->mutex_fork[ph->id + 1]);
<<<<<<< HEAD
			printf("wait\n");
=======
>>>>>>> 96e7a08ff32d37906a6eaa3ea63ae71ae802c1c1
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
			printf("[%ld]ms\t%i taken a fork\n", time_now(ph), ph->index);
			printf("[%ld]ms\t%i taken a fork\n", time_now(ph), ph->index);
			return (1);
		}
		else
		{	
			UNLOCK(&ph->table->mutex_fork[ph->id]);
			UNLOCK(&ph->table->mutex_fork[0]);
<<<<<<< HEAD
			printf("wait\n");
=======
>>>>>>> 96e7a08ff32d37906a6eaa3ea63ae71ae802c1c1
			return (0);
		}	
	}
}
