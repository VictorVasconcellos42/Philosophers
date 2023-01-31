/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/31 20:04:33 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	scan(t_philo *ph)

{
	if (ph->last_meal + time_now(ph) > ph->table->time_die && \
	ph->last_meal != 0)
	{
		ph->table->died = 1;
		return (FALSE);
	}
	return (TRUE);
}
