/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/18 14:22:10 by vde-vasc         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0

typedef struct s_config	t_config;

typedef struct s_philo
{
	int				index;
	int				right;
	int				left;
	long int		last_meal;
	pthread_t		philo;
	t_config		*table;
}	t_philo;	

typedef struct s_config
{
	pthread_mutex_t	*number_of_forks;

	int				*fork;
	int				must_eat;
	int				number_of_philo;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	t_philo			*ph;
}	t_config;

int		ft_valid_argc(int argc, char **argv);
int		error_digit(int position);
int		error_format(void);
int		error_signal(int position);
int		error_philo_and_time(void);
void	eat(t_philo *ph);
void	think(t_philo *ph);
void	dreams(t_philo *ph);
int		init_vars(t_config *table, int argc, char **argv);
#endif