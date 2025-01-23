/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:16 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 11:23:15 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	wrong_number(char **args, t_list *lst)
{
	free_array(args);
	free_linked_list(&lst);
	write(2, "Error\n", 6);
	exit(5);
}

int	ft_atoi(char *str, char **args, t_list *lst)
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
		num = num * 10 + (str[i] - '0');
		i++;
		if (sign * num < INT_MIN || sign * num > INT_MAX)
			wrong_number(args, lst);
	}
	return (num * sign);
}

t_list	*ft_lst_new(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

int	ft_lst_add_back(t_list **lst, int content)
{
	t_list	*new;
	t_list	*last;

	new = ft_lst_new(content);
	if (!new)
		return (-1);
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	return (0);
}

int	ft_lst_size(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}