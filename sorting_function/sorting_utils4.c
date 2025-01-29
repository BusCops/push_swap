/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:38:27 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 18:12:55 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	number_movement_reset(t_Number_mv *num)
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

void	calcul_rr_move(t_Number_mv *num)
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
}

void	calcul_rrr_move(t_Number_mv *num)
{
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
}

void	calcul_total_move(t_Number_mv *num)
{
	calcul_rr_move(num);
	calcul_rrr_move(num);
	num->total_mv = num->rr_mv + num->rb_mv + num->ra_mv
		+ num->rrr_mv + num->rrb_mv + num->rra_mv + num->pa_mv;
}

void	check_move(t_Number_mv *num, t_Number_mv *tmp)
{
	calcul_total_move(num);
	calcul_total_move(tmp);
	if (num->total_mv > tmp->total_mv)
	{
		num->num = tmp->num;
		num->pa_mv = tmp->pa_mv;
		num->ra_mv = tmp->ra_mv;
		num->rb_mv = tmp->rb_mv;
		num->rra_mv = tmp->rra_mv;
		num->rrb_mv = tmp->rrb_mv;
		num->rr_mv = tmp->rr_mv;
		num->rrr_mv = tmp->rrr_mv;
		num->total_mv = tmp->total_mv;
	}
}
