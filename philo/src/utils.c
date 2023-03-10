/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:54 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/03 11:53:30 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_time(void)

{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

int	ft_isdigit(char c)

{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	str_isdigit(char *str)

{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
	}
	return (TRUE);
}
