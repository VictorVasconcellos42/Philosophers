/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:16:56 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/17 09:06:13 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*routine(void *ph)

{
	t_philo *filo;
	
	filo = (t_philo *)ph;
		printf("Hello, I'm philosopher %i\n", filo->index);
	return (NULL);
}

long	get_time(void)

{
	struct timeval	tp;
	long		milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}


int	main(int argc, char **argv)

{
	t_config	my;
	int		i;
	int		total_philo;

	if (ft_valid_argc(argc, argv) == FALSE)
		return (1);
	total_philo = atoi(argv[1]);
	my.ph = malloc(sizeof(t_philo) * total_philo);
	i = 0;
	while (i < total_philo)
	{
		my.ph[i].index = i + 1;
		pthread_create(&my.ph[i].philo, NULL, &routine, &my.ph[i]);
		i++;
	}
	while (--i)
		pthread_join(my.ph[i].philo, NULL);
	return (0);
}
