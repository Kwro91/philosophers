/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:54:50 by besalort          #+#    #+#             */
/*   Updated: 2023/10/23 14:54:52 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_only_number(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > '9' || av[i][j] < '0')
			{
				printf("Error arg\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}