/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:11:46 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 17:25:05 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_the_med(t_list **a, t_list **b, min_med_max values)
{
	int		i;
	int		size;
	t_list	*start;

	i = 0;
	size = ft_lst_size(*a);
	start = *a;
	while (*a)
	{
		if ((*a)->data == values.med)
			break ;
		*a = (*a)->next;
		i++;
	}
	*a = start;
	if (size / 2 > i)
		push_ra(a, b, values.med);
	else
		push_rra(a, b, values.med);
}

void	pre_sort(t_list **a, t_list **b, min_med_max values)
{
	push_the_med(a, b, values);
	while (ft_lst_size(*a) != 5)
	{
		if ((*a)->data == values.max1 || (*a)->data == values.max2
			|| (*a)->data == values.max3 || (*a)->data == values.max4
			|| (*a)->data == values.max5)
			ra(a);
		else
		{
			if ((*a)->data > values.med)
			{
				pb(a, b);
				rb(b);
			}
			else
				pb(a, b);
		}
	}
}

void	number_movement_reset(Number_mv *num)
{
	num->pa_mv = 0;
	num->ra_mv = 0;
	num->rb_mv = 0;
	num->rra_mv = 0;
	num->rrb_mv = 0;
	num->rr_mv = 0;
	num->rrr_mv = 0;
	num->total_mv = 0;
}

void	search_for_position(t_list *a, int max, Number_mv *num)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(a);
	while (a->next)
	{
		if ((num->num > a->data && num->num < a->next->data)
			|| (a->data == max && num->num < a->next->data))
		{
			i++;
			break ;
		}
		a = a->next;
		i++;
	}
	if (size / 2 >= i)
		num->ra_mv = i;
	else
		num->rra_mv = size - i;
	num->pa_mv++;
}

void	best_move_to_a(t_list *a, Number_mv *num, int max)
{
	if (num->num < a->data && num->num < lst_last(a)->data
		&& a->data < lst_last(a)->data)
		num->pa_mv++;
	else if (num->num < a->data && num->num > lst_last(a)->data)
		num->pa_mv++;
	else
		search_for_position(a, max, num);
}

void	best_move_from_b(t_list *b, Number_mv *num)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lst_size(b);
	while (b)
	{
		if (num->num == b->data)
			break ;
		b = b->next;
		i++;
	}
	if (size / 2 >= i)
		num->rb_mv = i;
	else
		num->rrb_mv = size - i;
}
