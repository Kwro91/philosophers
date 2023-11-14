/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:48 by besalort          #+#    #+#             */
/*   Updated: 2023/11/14 19:00:50 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	convert_all(t_data *data, char **av)
{
	data->time_die = convert_milli_micro(av[2]);
	data->time_eat = convert_milli_micro(av[3]);
	data->time_sleep = convert_milli_micro(av[4]);
}

unsigned long	convert_milli_micro(char *time)
{
	int		count;

	count = ft_atoi(time);
	count *= 1000;
	return (count);
}
