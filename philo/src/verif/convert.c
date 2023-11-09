/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:48 by besalort          #+#    #+#             */
/*   Updated: 2023/11/09 17:11:53 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	convert_all(t_data *data, char **av)
{
	data->time_die.tv_usec = convert_milli_micro(av[2]);
	data->time_eat.tv_usec = convert_milli_micro(av[3]);
	data->time_sleep.tv_usec = convert_milli_micro(av[4]);
}

int	convert_milli_micro(char *time)
{
	int		count;

	count = ft_atoi(time);
	count *= 1000;
	return (count);
}
