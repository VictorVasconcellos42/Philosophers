/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 11:12:56 by vde-vasc         ###   ########.fr       */
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
# define DINNER 42
# define RIGHT (ph->id + 1) % ph->table->n_philo
# define LEFT (ph->id - 1) % ph->table->n_philo
# define LOCK pthread_mutex_lock
# define UNLOCK pthread_mutex_unlock

typedef struct s_config	t_config;
typedef struct s_philo t_philo;
typedef pthread_mutex_t t_mutex;

typedef struct s_philo
{
	int				index;
	int				id;
	long			last_meal;
	pthread_t		philo;
	t_table			*table;
}	t_philo;	

typedef struct s_table
{
	t_mutex	*m_fork;

	int		*fork;
	int		m_eat;
	int		n_philo;
	long	start_clock;
	long	time_eat;
	long	time_die;
	long	time_dream;
	t_philo	*ph;
}	t_table;

// UTILS FUNCTIONS

int		ft_isdigit(char c);
int		str_isdigit(char *str);
long	get_time(void);

// DINNER FUNCTIONS


#endif