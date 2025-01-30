/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_operation4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:07:14 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/30 18:31:23 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_no_write(t_list *a)
{
	int		tmp1;
	t_list	*tmp2;

	if (!a || !a->next)
		return ;
	tmp1 = a->data;
	tmp2 = a->next;
	a->data = tmp2->data;
	tmp2->data = tmp1;
}

void	sb_no_write(t_list *b)
{
	int		tmp1;
	t_list	*tmp2;

	if (!b || !b->next)
		return ;
	tmp1 = b->data;
	tmp2 = b->next;
	b->data = tmp2->data;
	tmp2->data = tmp1;
}
