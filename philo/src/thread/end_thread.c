/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:52:34 by besalort          #+#    #+#             */
/*   Updated: 2023/10/31 17:31:20 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	end_thread(t_data *data)
{
	t_philo		*tmp;
	int			i;

	tmp = data->philo;
	i = 0;
	while (i < 200)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	while (tmp->next)
	{
		pthread_join(tmp->tid, NULL);
		tmp = tmp->next;
	}
}

int	check_all_ate(t_data *data)
{
	t_philo	*tmp;

	tmp = data->philo;
	while (tmp->next)
	{
		if (tmp->meal < tmp->meal_max)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_end(t_data *data)
{
	t_philo		*tmp;
	int			died;
	
	died = 0;
	while (died == 0)
	{
		tmp = data->philo;
		while (tmp->next)
		{
			if (tmp->alive == 0 || check_all_ate(data) == 1)
			{
				died = 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	end_thread(data);
	return (0);
}
