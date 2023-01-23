/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/23 14:21:44 by vde-vasc         ###   ########.fr       */
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

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef pthread_mutex_t	t_mutex;

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

// UTILS FUNCTIONS //

int		ft_isdigit(char c);
int		str_isdigit(char *str);
long	get_time(void);

// ERROR FUNCTIONS //

int		error_philo_and_time(void);
int		error_digit(int position);
int		error_signal(int position);
int		error_format(void);

// VALIDATES FUNCTIONS //

int		ft_valid_argc(int argc, char **argv);
int		valid_times(t_table *table);

// INIT FUNCTIONS //

int		init_vars(t_table *table, int argc, char **argv);

// MUTEX FUNCTIONS //

int		lock(t_mutex mutex);
int		unlock(t_mutex mutex);

#endif
