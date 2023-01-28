/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:09:51 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/28 15:48:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	scan(t_philo *ph)

{
	//printf("LAST MEAL [%ld] AND TIME DIE [%ld]", ph->last_meal, ph->table->time_die);
	if (ph->last_meal + ph->table->time_die > time_now(ph) && ph->last_meal != 0)
	{
		ph->table->died = 1;
		return (FALSE);
	}
	return (TRUE);
}
