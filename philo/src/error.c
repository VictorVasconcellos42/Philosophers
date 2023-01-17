/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 07:45:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/17 09:10:55 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	error_philo(void)

{
	printf("Really? You need at least " \
	"one philosopher or timestamp more than 60 ms\n");
	return (FALSE);
}

int	error_signal(int position)

{
	printf("Error! Argument [%i] is a negative number\n", position);
	return (FALSE);
}

int	error_digit(int position)

{
	printf("Error! Argument [%i] is not a number\n", position);
	return (FALSE);
}

int	error_format(void)

{
		printf("Error! ");
		printf("Format: <Number_of_philosophers> <time_to_die> " \
		"<time_to_eat> <time_to_sleep> " \
		"[number_of_times_each_philosopher_must_eat]\n");
		return (FALSE);	
}