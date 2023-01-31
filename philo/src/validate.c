/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:49:48 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 12:02:07 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	valid_times(t_table *table)

{
	if (table->time_die < 60 || \
	table->time_eat < 60 || \
	table->time_dream < 60)
		return (error_philo_and_time());
	return (TRUE);
}

int	ft_valid_argc(int argc, char **argv)

{
	int	i;

	if (argc != 5 && argc != 6)
		return (error_format());
	else
	{
		i = 0;
		while (argv[++i])
		{
			if (argv[i][0] == '0')
				return (error_philo_and_time());
			if (!str_isdigit(argv[i]))
			{
				if (argv[i][0] == '-')
					return (error_signal(i));
				return (error_digit(i));
			}
		}
	}
	return (TRUE);
}
