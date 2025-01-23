/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:41 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 15:11:00 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	last = *a;
	*a = (*a)->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	last = *b;
	*b = (*b)->next;
	while (last->next)
	{
		last = last->next;
	}
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next->next)
	{
		last = last->next;
	}
	tmp = last->next;
	last->next = NULL;
	tmp->next = *a;
	*a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next->next)
	{
		last = last->next;
	}
	tmp = last->next;
	last->next = NULL;
	tmp->next = *b;
	*b = tmp;
	write(1, "rrb\n", 4);
}