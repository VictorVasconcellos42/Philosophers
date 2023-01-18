/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:16:56 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/18 12:58:42 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *ph)

{
	t_philo	*filo;

	filo = (t_philo *)ph;
	eat(filo);
	dreams(filo);
	think(filo);
	return (NULL);
}

static void	start_philo(t_config *table, int t_philo)

{
	int	i;

	i = -1;
	while (++i < t_philo)
	{
		table->ph[i].index = i + 1;
		pthread_create(&table->ph[i].philo, NULL, &routine, &table->ph[i]);
	}
}

static void	finish_philo(t_config *table, int t_philo)

{
	int	i;

	i = 0;
	while (i < t_philo)
		pthread_join(table->ph[i++].philo, NULL);
}

int	main(int argc, char **argv)

{
	t_config	table;

	if (ft_valid_argc(argc, argv) == FALSE || \
	init_vars(&table, argc, argv) == FALSE)
		return (1);
	table.ph = malloc(sizeof(t_philo) * table.number_of_philo);
	start_philo(&table, table.number_of_philo);
	finish_philo(&table, table.number_of_philo);
	return (0);
}
