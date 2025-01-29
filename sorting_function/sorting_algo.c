/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 18:27:17 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_best_move(t_list **a, t_list **b, t_Number_mv *num)
{
	while (num->ra_mv--)
		ra(a);
	while (num->rb_mv--)
		rb(b);
	while (num->rra_mv--)
		rra(a);
	while (num->rrb_mv--)
		rrb(b);
	while (num->rr_mv--)
		rr(a, b);
	while (num->rrr_mv--)
		rrr(a, b);
	pa(a, b);
}

void	sort_numbers_with_best_move(t_list **a, t_list **b,
	t_Number_mv num, int max)
{
	t_list		*start;
	t_Number_mv	tmp;

	tmp.num = (*b)->data;
	number_movement_reset(&tmp);
	start = *b;
	while (*b)
	{
		num.num = (*b)->data;
		best_move_from_b(*b, &num);
		best_move_to_a(*a, &num, max);
		while (*b)
		{
			tmp.num = (*b)->data;
			best_move_from_b(start, &tmp);
			best_move_to_a(*a, &tmp, max);
			check_move(&num, &tmp);
			number_movement_reset(&tmp);
			*b = (*b)->next;
		}
		*b = start;
		apply_best_move(a, b, &num);
		number_movement_reset(&num);
		start = *b;
	}
}

void	sorting(t_list **a, t_list **b, int max)
{
	t_Number_mv	num;

	num.num = (*b)-> data;
	number_movement_reset(&num);
	best_move_from_b(*b, &num);
	best_move_to_a(*a, &num, max);
	sort_numbers_with_best_move(a, b, num, max);
}

void	final_sorting(t_list **a, int i, int size, t_min_med_max values)
{
	if (size / 2 > i)
	{
		while (*a)
		{
			if ((*a)->data == values.min)
				break ;
			ra(a);
		}
	}
	else
	{
		while (*a)
		{
			if ((*a)->data == values.min)
				break ;
			rra(a);
		}
	}
}

void	sort(t_list **a, t_list **b)
{
	t_min_med_max	values;
	int				i;
	int				size;
	t_list			*start;

	i = 0;
	get_the_mmm(*a, &values);
	pre_sort(a, b, values);
	five_numbers_sort(a, b);
	sorting(a, b, values.max5);
	start = *a;
	size = ft_lst_size(*a);
	while (*a)
	{
		if ((*a)->data == values.min)
			break ;
		i++;
		*a = (*a)->next;
	}
	*a = start;
	final_sorting(a, i, size, values);
}
