/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:39:00 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/17 14:47:05 by vde-vasc         ###   ########.fr       */
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

typedef struct	s_philo

{
	pthread_t	philo;
	int			index;
	
}	t_philo;	

typedef	struct	s_config

{
	pthread_mutex_t	mutex;
	int		fork;
	t_philo		*ph;
}	t_config;

int		ft_valid_argc(int argc, char **argv);
int		error_digit(int position);
int		error_format(void);
int		error_signal(int position);
int		error_philo(void);
void	eat(t_philo *ph);
void	think(t_philo *ph);
void	dreams(t_philo *ph);
#endif