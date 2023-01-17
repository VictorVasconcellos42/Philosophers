/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:34:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/17 14:46:54 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	eat(t_philo *ph)

{
	printf("Philosopher [%i] is eating\n", ph->index);
}

void	think(t_philo *ph)

{
	printf("Philosopher [%i] is thinking\n", ph->index);
}

void	dreams(t_philo *ph)

{
	printf("Philosopher [%i] is sleeping\n", ph->index);
}