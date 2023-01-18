/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:14 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_philo *ph)

{
	printf("[%ld]ms %i is eating\n", get_time(), ph->index);
}

void	think(t_philo *ph)

{
	printf("[%ld]ms %i is thinking\n", get_time(), ph->index);
}

void	dreams(t_philo *ph)

{
	printf("[%ld]ms %i is sleeping\n", get_time(), ph->index);
}
