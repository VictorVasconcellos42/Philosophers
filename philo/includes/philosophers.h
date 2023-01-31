/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/29 13:36:15 by vde-vasc         ###   ########.fr       */
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
# define EAT 90
# define THINK 91
# define DREAMS 92
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define END "\033[0m"

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;
typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int				index;
	int				id;
	long			last_meal;
	int				r_fork;
	int				l_fork;
	pthread_t		philo;
	t_table			*table;
}	t_philo;	

typedef struct s_table
{
	t_mutex		*m_fork;
	t_mutex		creed;
	t_mutex		print;
	int			*fork;
	int			died;
	int			m_eat;
	int			n_philo;
	long		start_clock;
	long		time_eat;
	long		time_die;
	long		time_dream;
	pthread_t	scanner;
	t_philo		*ph;
}	t_table;

// UTILS FUNCTIONS //

int		ft_isdigit(char c);
long	get_time(void);
long	time_now(t_philo *ph);
long	ft_atol(const char *str);
void	smart_sleep(long duration, t_philo *ph);

// ERROR FUNCTIONS //

int		error_philo_and_time(void);
int		error_digit(int position);
int		error_signal(int position);
int		error_format(void);

// VALIDATES FUNCTIONS //

int		ft_valid_argc(int argc, char **argv);
int		str_isdigit(char *str);
int		valid_times(t_table *table);

// INIT FUNCTIONS //

int		init_vars(t_table *table, int argc, char **argv);
void	start_philo(t_table *table, int t_philo);
void	finish_philo(t_table *table, int t_philo);
void	init_fork(t_table *table);

// SCAN FUNCTIONS //

int		scan(t_philo *ph);

// MUTEX FUNCTIONS //

void	lock(t_mutex mutex);
void	unlock(t_mutex mutex);

// DINNER FUNCTIONS //

void	*dinner(void *ph);
void	dreams(t_philo *ph);
void	eat(t_philo *ph);
void	think(t_philo *ph);
void	take_fork(t_philo *ph);
void	check_menu(t_philo *ph);
#endif
