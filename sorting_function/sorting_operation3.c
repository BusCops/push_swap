/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:05:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 17:50:15 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_list **a, t_list **b)
{
	rra_no_write(a);
	rrb_no_write(b);
	write(1, "rrr\n", 4);
}

void	ra_no_write(t_list **a)
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
}

void	rb_no_write(t_list **b)
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
}

void	rra_no_write(t_list **a)
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
}

void	rrb_no_write(t_list **b)
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
}
