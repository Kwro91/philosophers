/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:54:50 by besalort          #+#    #+#             */
/*   Updated: 2023/10/31 15:59:22 by besalort         ###   ########.fr       */
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

void	max_meal(t_data *data, int ac, char **av)
{
	if (ac == 6)
		data->meal_max = ft_atoi(av[5]);
	else
		data->meal_max = -1;
}