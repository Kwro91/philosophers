/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:43:32 by besalort          #+#    #+#             */
/*   Updated: 2023/11/13 17:05:28 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int		check_values(t_data *data, char **av)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	(void)data;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb < 1)
			return (-1);
		i++;
	}
	return (0);
}