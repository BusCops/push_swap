/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/24 18:28:21 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_num_1(t_list *a)
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

/*void	insertion_sort2(t_list **a, t_list **b)
{
	t_list	*start;
	int		i;
	int		j;
	
	i = 0;
	
	start = *a;
	j = ft_lst_size(*a) / 5;
	while (j)
	{
		while (i < 5)
		{
			pb(a, b);
			i++;
		}
		i = 0;
		algo_num_1(*b);
		while (i < 5)
		{
			pa(a, b);
			ra(a);
			i++;
		}
		j--;
	}
	algo_num_1(*a);
}*/
/*
int	pivot(t_list *a)
{
	int	first;
	int	last;
	int	mid;
	int	size;

	size = ft_lst_size(a) / 2 - 1;
	first = a->data;
	while (size)
	{
		a = a->next;
		size--;
	}
	mid = a->data;
	a = lst_last(a);
	last = a->data;
	size = mid_number(first, mid, last);
	return (size);
}

int	mid_number(int first, int mid, int last)
{
	if ((first > mid && first < last) || (first < mid && first > last))
		return (first);
	else if ((mid > first && mid < last) || (mid < first && mid > last))
		return (mid);
	else
		return (last);
}*/
/*
void	quick_sort(t_list **a, t_list **b)
{
	int		i;
	int		size;
	
	size = ft_lst_size(*a);
	if (size == 0)
		return ;
	i = pivot(*a);
	while (size)
	{
		if (i >= (*a)->data)
			pb(a, b);
		else
			ra(a);
		size--;
	}
	algo_num_1(*b);
	algo_num_1(*a);
	//quick_sort(b, a);
}*/


int	grap_the_smallest(t_list *a)
{
	int	i;

	i = a->data;
	while (a)
	{
		if (i > a->data)
			i = a->data;
		a = a->next;
	}
	return (i);
}

int find_closest_smallest(t_list *a, int min)
{
	int i;
	t_list *start;

	start = a;
	i = 0;
	while (a)
	{
		if (a->data == min)
			break;
		i++;
		a = a->next;
	}
	a = start;
	if (ft_lst_size(a) / 2 >= i)
		return (1);
	return (0);
}

void	push_min_to_b(t_list **a, t_list **b, int min, int direction)
{
	if (direction == 1)
	{
		while ((*a)->data != min)
			ra(a);
	}
	else
	{
		while ((*a)->data != min)
			rra(a);
	}
	pb(a, b);
}

void	sort_algo2(t_list **a, t_list **b)
{
	int		min;
	int		direction;

	while (*a)
	{
		min = grap_the_smallest(*a);
		direction = find_closest_smallest(*a, min);
		push_min_to_b(a, b, min, direction);
	}
	while (*b)
	{
		pa(a, b);
	}
}

int	find_max(t_list *a)
{
	int	i;

	i = a->data;
	while (a)
	{
		if (i < a->data)
			i = a->data;
		a = a->next;
	}
	return (i);
}
