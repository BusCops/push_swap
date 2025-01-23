/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:43:22 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 15:11:02 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list *a)
{
	int		tmp1;
	t_list	*tmp2;

	if (!a || !a->next)
		return ;
	tmp1 = a->data;
	tmp2 = a->next;
	a->data = tmp2->data;
	tmp2->data = tmp1;
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	int		tmp1;
	t_list	*tmp2;

	if (!b || !b->next)
		return ;
	tmp1 = b->data;
	tmp2 = b->next;
	b->data = tmp2->data;
	tmp2->data = tmp1;
	write(1, "ba\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp1;

	if (!(*b) || !b)
		return ;
	tmp1 = *b;
	*b = (*b)->next;
	tmp1->next = *a;
	*a = tmp1;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp1;

	if (!a || !(*a))
		return ;
	tmp1 = *a;
	*a = (*a)->next;
	tmp1->next = *b;
	*b = tmp1;
	write(1, "pb\n", 3);
}
