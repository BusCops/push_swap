/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check_and_combinor1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:58:29 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 15:10:42 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**args_check(int ac, char **av)
{
	char	**args;

	arg_num_check(ac);
	arg_check_int(av);
	args = args_combinor(av);
	if (!args)
		exit(3);
	if (!args[0])
	{
		free_array(args);
		exit(4);
	}
	return (args);
}

void	arg_num_check(int ac)
{
	if (ac == 1)
		exit(1);
}

void	arg_check_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9')
					&& (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+'))
			{
				write(2, "Error\n", 6);
				exit(2);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

char	**args_combinor(char **av)
{
	char	*tmp1;
	char	*tmp2;
	int		i;
	char	**args;

	i = 2;
	tmp1 = ft_strjoin(av[1], " ");
	if (!tmp1)
		return (NULL);
	while (av[i])
	{
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		if (!tmp2)
			return (NULL);
		tmp1 = ft_strjoin(tmp2, " ");
		free(tmp2);
		if (!tmp1)
			return (NULL);
		i++;
	}
	args = ft_split(tmp1, ' ');
	free(tmp1);
	return (args);
}

t_list	*stack_filler(char **args)
{
	t_list	*new;
	int		i;

	i = 0;
	new = NULL;
	new = ft_lst_new(ft_atoi(args[i], args, new));
	if (!new)
		return (NULL);
	i++;
	while (args[i])
	{
		if (ft_lst_add_back(&new, ft_atoi(args[i], args, new)) == -1)
		{
			free_linked_list(&new);
			return (NULL);
		}
		i++;
	}
	return (new);
}
