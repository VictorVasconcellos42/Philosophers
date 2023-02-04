/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:14:04 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/04 17:11:22 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static size_t	ft_ispace(const char *str)

{
	size_t	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long	ft_atol(const char *str)

{
	size_t	i;
	size_t	minus;
	long	num;

	num = 0;
	minus = 1;
	i = ft_ispace(str);
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = num * 10 + (str[i++] - '0');
	num = num * minus;
	if (num >= -2147483648 && num <= 2147483647)
		return (num);
	return (0);
}

long	time_now(t_philo *ph)

{
	long	start_program;

	start_program = ph->table->start_clock;
	return (get_time() - start_program);
}

void	smart_sleep(long duration, t_philo *ph)

{
	long	start_time;

	start_time = time_now(ph);
	while (time_now(ph) - start_time < duration)
		usleep(100);
}
