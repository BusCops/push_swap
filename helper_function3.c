/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:16 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/20 18:15:26 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	wrong_number(char **args)
{
	free_array(args);
	write(2, "Error\n", 6);
	exit(4);
}

int	ft_atoi(char *str, char **args)
{
	int		i;
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (((-num * 10 - (str[i] - '0')) < INT_MIN) || ((num * 10 + (str[i] - '0')) > INT_MAX))
			wrong_number(args);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
