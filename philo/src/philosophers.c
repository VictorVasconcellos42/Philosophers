/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 13:16:56 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/05 17:44:48 by vasconcel        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)

{
	struct timeval	tp;
	long		milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}


int	main(void)

{
	long start_time;

	start_time = get_time();

	while (1)
	{
		printf("%ld\n", get_time() - start_time);
		usleep(200 * 1000);
	}
	return (0);
}
