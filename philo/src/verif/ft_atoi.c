/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besalort <besalort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:56:23 by besalort          #+#    #+#             */
/*   Updated: 2023/10/25 15:07:35 by besalort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_is_negative(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	return (j % 2);
}

char	*where_is_number(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (str);
		else if ((*str >= 7 && *str <= 13) || (
				*str == '-' || *str == ' ' || *str == '+'))
		{
			str++;
		}
		else
			return (NULL);
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	negative;

	i = 0;
	count = 0;
	negative = ft_is_negative(str);
	str = where_is_number(str);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		count = -count;
	return (count);
}
