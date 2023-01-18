/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:16:56 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/17 21:38:56 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"



void	*routine(void *ph)

{
	t_philo *filo;
	
	filo = (t_philo *)ph;
	eat(ph);
	dreams(ph);
	think(ph);
	return (NULL);
}

static void	start_philo(t_config *table, int t_philo)

{
	int i;

	i = -1;
	while (++i < t_philo)
	{
		table->ph[i].index = i + 1;
		pthread_create(&table->ph[i].philo, NULL, &routine, &table->ph[i]);
	}
}

static void	finish_philo(t_config *table, int t_philo)

{
	int i;

	i = 0;
	while (i < t_philo)
		pthread_join(table->ph[i++].philo, NULL);
}

int	main(int argc, char **argv)

{
	t_config	my;
	int		total_philo;

	if (ft_valid_argc(argc, argv) == FALSE)
		return (1);
	total_philo = atoi(argv[1]);
	my.ph = malloc(sizeof(t_philo) * total_philo);
	start_philo(&my, total_philo);
	finish_philo(&my, total_philo);
	return (0);
}
