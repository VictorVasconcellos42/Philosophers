/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:12:03 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/14 15:32:50 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_isdigit(char c)

{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static int	str_isdigit(char *str)

{
	int i;

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

int	ft_valid_argc(int argc, char **argv)

{
	int i;

	if (argc != 5 && argc != 6)
		return (error_format());
	else
	{
		i = 0;
		while (argv[++i])
		{
			if (argv[1][0] == '0')
				return (error_philo());
			if (str_isdigit(argv[i]) == FALSE)
			{
				if (argv[i][0] == '-')
					return (error_signal(i));
				return (error_digit(i));
			}
		}
	}
	return (TRUE);
}
