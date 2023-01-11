/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/11 04:24:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define FORMAT "Format: <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_spleep> [number_of_times_each_philosopher_must_eat]"

typedef struct	s_philo

{
	pthread_t	philo;
	int		index;
}	t_philo;	

typedef	struct	s_config

{
	pthread_mutex_t	mutex;
	int		fork;
	t_philo		*ph;
}	t_config;

#endif
