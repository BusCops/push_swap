/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 17:19:50 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calcul_total_move(Number_mv *num)
{
	if (num->ra_mv == 0 || num->rb_mv == 0)
	{
		num->rr_mv = num->rr_mv;
	}
	else if (num->ra_mv - num->rb_mv == 0)
	{
		num->rr_mv = num->ra_mv + num->rr_mv;
		num->ra_mv = 0;
		num->rb_mv = 0;
	}
	else if (num->ra_mv - num->rb_mv > 0)
	{
		num->rr_mv = num->rb_mv + num->rr_mv;
		num->ra_mv = num->ra_mv - num->rb_mv;
		num->rb_mv = 0;
	}
	else if (num->ra_mv - num->rb_mv < 0)
	{
		num->rr_mv = num->ra_mv + num->rr_mv;
		num->rb_mv = num->rb_mv - num->ra_mv;
		num->ra_mv = 0;
	}
	if (num->rra_mv == 0 || num->rrb_mv == 0)
	{
		num->rrr_mv = num->rrr_mv;
	}
	else if (num->rra_mv - num->rrb_mv == 0)
	{
		num->rrr_mv = num->rra_mv + num->rrr_mv;
		num->rra_mv = 0;
		num->rrb_mv = 0;
	}
	else if (num->rra_mv - num->rrb_mv > 0)
	{
		num->rrr_mv = num->rrb_mv + num->rrr_mv;
		num->rra_mv = num->rra_mv - num->rrb_mv;
		num->rrb_mv = 0;
	}
	else if (num->rra_mv - num->rrb_mv < 0)
	{
		num->rrr_mv = num->rra_mv + num->rrr_mv;
		num->rrb_mv = num->rrb_mv - num->rra_mv;
		num->rra_mv = 0;
	}
	//printf("RR MOVES %d\n", num->rr_mv);
	num->total_mv = num->rr_mv + num->rb_mv + num->ra_mv + num->rrr_mv + num->rrb_mv + num->rra_mv + num->pa_mv;
}

void	check_move(Number_mv *num, Number_mv *tmp)
{
	//printf("num");
	calcul_total_move(num);
	//printf("tmp");
	calcul_total_move(tmp);
	if (num->total_mv > tmp->total_mv)
	{
	//	printf("exchange :)\n");
		num->num = tmp->num;
		num->pa_mv = tmp->pa_mv;
		num->ra_mv = tmp->ra_mv;
		num->rb_mv = tmp->rb_mv;
		num->rra_mv = tmp->rra_mv;
		num->rrb_mv = tmp->rrb_mv;
		num->rr_mv = tmp->rr_mv;
		num->rrr_mv = tmp->rrr_mv;
		num->total_mv = tmp->total_mv;
	//	printf("RR MOVES %d\n", num->rr_mv);
	}
}

void	apply_best_move(t_list **a, t_list **b, Number_mv *num)
{
	while (num->ra_mv)
	{
		ra(a);
		num->ra_mv--;
	}
	while (num->rb_mv)
	{
		rb(b);
		num->rb_mv--;
	}
	while (num->rra_mv)
	{
		rra(a);
		num->rra_mv--;
	}
	while (num->rrb_mv)
	{
		rrb(b);
		num->rrb_mv--;
	}
	while (num->rr_mv)
	{
		rr(a, b);
		num->rr_mv--;
	}
	while (num->rrr_mv)
	{
		rrr(a, b);
		num->rrr_mv--;
	}
	while (num->pa_mv)
	{
		pa(a, b);
		num->pa_mv--;
	}
}

void	sorting(t_list **a, t_list **b, int max)
{
	Number_mv	num;
	Number_mv	tmp;
	t_list		*start;
	(void)a;
	
	start = *b;
	tmp.num = (*b)->data;
	num.num = (*b)-> data;
	//printf("number is %d      %d\n",num.num,tmp.num);
	number_movement_reset(&num);
	number_movement_reset(&tmp);
	best_move_from_b(*b, &num);
	best_move_to_a(*a, &num, max);
	//printf("ra %d rra %d rb %d rrb %d pa %d\n",num.ra_mv, num.rra_mv, num.rb_mv, num.rrb_mv, num.pa_mv);
	while (*b)
	{
		num.num = (*b)->data;
		best_move_from_b(*b, &num);
		best_move_to_a(*a, &num, max);
		//printf(" NUM ra %d rra %d rb %d rrb %d rr %d rrr %d pa %d\n",num.ra_mv, num.rra_mv, num.rb_mv, num.rrb_mv,num.rr_mv, num.rrr_mv ,num.pa_mv);
		while (*b)
		{
			tmp.num = (*b)->data;
			best_move_from_b(start, &tmp);
			best_move_to_a(*a, &tmp, max);
			//printf("ra %d rra %d rb %d rrb %d rr %d rrr %d pa %d\n",num.ra_mv, num.rra_mv, num.rb_mv, num.rrb_mv,num.rr_mv, num.rrr_mv ,num.pa_mv);
			//printf("tmp     ra %d rra %d rb %d rrb %d  rr %d rrr %d pa %d\n",tmp.ra_mv, tmp.rra_mv, tmp.rb_mv, tmp.rrb_mv,tmp.rr_mv ,tmp.rrr_mv ,tmp.pa_mv);
			check_move(&num, &tmp);
			number_movement_reset(&tmp);
			*b = (*b)->next;
		}
		*b = start;
		apply_best_move(a, b, &num);
		number_movement_reset(&num);
		start  = *b;
	}
}

void	sort(t_list **a, t_list **b)
{
	min_med_max	values;

	get_the_mmm(*a, &values);
	pre_sort(a, b, values);
	five_numbers_sort(a, b);
	sorting(a, b, values.max5);
	int	i = 0;
	t_list *start = *a;
	int size = ft_lst_size(*a);
	while (*a)
	{
		if ((*a)->data == values.min)
			break;
		i++;
		*a = (*a)->next;
	}
	*a = start;
	size = size / 2;
	if (size > i)
	{
		while (*a)
		{
			if ((*a)->data == values.min)
				break;
			ra(a);
		}
	}
	else
	{
		while (*a)
		{
			if ((*a)->data == values.min)
				break;
			rra(a);
		}
	}
}
