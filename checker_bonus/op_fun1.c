/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fun1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:11:58 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:56 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

void	ss_no_write(t_list *a, t_list *b)
{
	sa_no_write(a);
	sb_no_write(b);
}

void	pa_no_write(t_list **a, t_list **b)
{
	t_list	*tmp1;

	if (!(*b) || !b)
		return ;
	tmp1 = *b;
	*b = (*b)->next;
	tmp1->next = *a;
	*a = tmp1;
}

void	pb_no_write(t_list **a, t_list **b)
{
	t_list	*tmp1;

	if (!a || !(*a))
		return ;
	tmp1 = *a;
	*a = (*a)->next;
	tmp1->next = *b;
	*b = tmp1;
}

void	rrr_no_write(t_list **a, t_list **b)
{
	rra_no_write(a);
	rrb_no_write(b);
}

void	rr_no_write(t_list **a, t_list **b)
{
	ra_no_write(a);
	rb_no_write(b);

}