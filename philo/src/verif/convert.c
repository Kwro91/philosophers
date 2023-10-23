/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:48 by besalort          #+#    #+#             */
/*   Updated: 2023/10/23 16:54:50 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	convert_all(t_data *data, char **av)
{
	convert_die(data, av[2]);
	convert_eat(data, av[3]);
	convert_sleep(data, av[4]);
	printf("%06ld est le temps en microseconde pour mourir\n",
		data->time_die.tv_usec);
	printf("%06ld est le temps en microseconde pour manger\n",
		data->time_eat.tv_usec);
	printf("%06ld est le temps en microseconde pour dormir\n",
		data->time_sleep.tv_usec);
}

void	convert_die(t_data *data, char *time)
{
	int				i;
	long int		count;

	i = 0;
	time = invert_tab(time);
	while (time && time[i])
	{
		if (i == 0)
			count = (time[i] - '0');
		else
		count = ((time[i] - '0') * (i * 10));
		i++;
	}
	count *= 1000;
	data->time_die.tv_usec = count;
}

void	convert_eat(t_data *data, char *time)
{
	int			i;
	long int	count;

	i = 0;
	time = invert_tab(time);
	while (time && time[i])
	{
		if (i == 0)
			count = (time[i] - '0');
		else
		count = ((time[i] - '0') * (i * 10));
		i++;
	}
	count *= 1000;
	data->time_eat.tv_usec = count;
}

void	convert_sleep(t_data *data, char *time)
{
	int					i;
	long int			count;

	i = 0;
	time = invert_tab(time);
	while (time && time[i])
	{
		if (i == 0)
			count = (time[i] - '0');
		else
			count = ((time[i] - '0') * (i * 10));
		i++;
	}
	count *= 1000;
	data->time_sleep.tv_usec = count;
}

char	*invert_tab(char *tab)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (tab && tab[j + 1])
		j++;
	while (i < j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i++;
		j--;
	}
	return (tab);
}
