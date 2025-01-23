/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 15:14:42 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_num_1(t_list **a)
{
	t_list	*last;

	last = lst_last(*a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
	if ((*a)->next->data > last->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void	algo_num_2(t_list *a)
{
	int		i;
	t_list	*start;

	start = a;
	i = 1;
	while (i != 0)
	{
		i = 0;
		while (a && a->next)
		{
			if (a->data > a->next->data)
			{
				sa(a);
				i++;
			}
			a = a->next;
		}
		a = start;
	}
}

