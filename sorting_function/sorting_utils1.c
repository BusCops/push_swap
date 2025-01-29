/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:49:24 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 16:56:39 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_numbers_sort(t_list **a)
{
	if ((*a)->data < (*a)->next->data)
		sa(*a);
	if ((*a)->data > lst_last(*a)->data)
		ra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

int	find_min(t_list *a)
{
	int	min;

	min = a->data;
	while (a)
	{
		if (min > a->data)
			min = a->data;
		a = a->next;
	}
	return (min);
}

void	push_the_min(t_list **a, t_list **b, int min)
{
	int		i;
	int		size;
	t_list	*start;

	i = 0;
	size = ft_lst_size(*a);
	start = *a;
	while (*a)
	{
		if ((*a)->data == min)
			break ;
		*a = (*a)->next;
		i++;
	}
	*a = start;
	if (size / 2 >= i)
		push_ra(a, b, min);
	else
		push_rra(a, b, min);
}

void	four_numbers_sort(t_list **a, t_list **b)
{
	int	min;

	min = find_min(*a);
	push_the_min(a, b, min);
	three_numbers_sort(a);
	pa(a, b);
}

void	five_numbers_sort(t_list **a, t_list **b)
{
	int	min;

	min = find_min(*a);
	push_the_min(a, b, min);
	four_numbers_sort(a, b);
	pa(a, b);
}
