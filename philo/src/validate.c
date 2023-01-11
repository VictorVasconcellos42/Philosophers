/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:12:03 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/01/11 04:27:12 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_valid_argc(int argc, char **argv)

{
	if (argc != 5 && argc != 6)
	{
		printf("Error! %s\n", FORMAT);
		return (NULL);
	}
}
