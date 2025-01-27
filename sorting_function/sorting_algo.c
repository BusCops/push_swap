/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/27 14:44:31 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tree_numbers_sort(t_list **a)
{
	if ((*a)->data < (*a)->next->data)
		sa(*a);
	if ((*a)->data > lst_last(*a)->data)
		ra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 1;
	while(i)
	{
		i = 0;
		while(j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				i++;
			}
			j++;
		}
		j = 0;
	}
}

long	get_the_median(t_list *a, int *min, int *max)
{
	int	*arr;
	int	size;
	int	i;
	int	mid;

	size = ft_lst_size(a);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (LONG_MAX);
	i = 0;
	while (i < size)
	{
		arr[i] = a->data;
		i++;
		a = a->next;
	}
	sort_arr(arr, size);
	size = size - 1;
	*min = arr[0];
	*max = arr[size];
	mid = arr[(size / 2)];
	return (free(arr), mid);
}

void	pre_sort(t_list **a, t_list **b)
{
	long	mid;
	int		size;
	int 	min;
	int		max;
	
	mid = get_the_median(*a, &min, &max);
	if (mid == LONG_MAX)
		return;
	size = ft_lst_size(*a);
	while (size)
	{
		if ((*a)->data == min || (*a)->data == max)
			ra(a);
		else if (mid >= (*a)->data)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
		size--;
	}
	sort(a, b, min);
}

int	the_farest_from_size(int size, int i, int j, t_list **b)
{
	if (size >= i && size <= j)
	{
		if (size - i <= j - size)
		{
			rrb(b);
			if (size > j)
				return (1);
			else
				return (0);
		}
		else if (size - i >= j - size)
		{
			if (size > i)
				return (1);
			else
				return (0);
		}
	}
	
	if (size <= i && size >= j)
	{
		if (size - j >= i - size)
		{
			rrb(b);
			if (size > j)
				return (1);
			else
				return (0);
		}
		else if (size - j <= i - size)
		{
			if (size > i)
				return (1);
			else
				return (0);
		}
	}
	return (0);
}

int	get_the_quickest_way(int up, int down, t_list *a, t_list **b)
{
	int	size;
	int	i;
	int	j;
	t_list	*start;

	start = a;
	size = ft_lst_size(a);
	i = 0;
	j = 0;
	while(a->next)
	{
		if (up > a->data && up < a->next->data )
			break;
		i++;
		a = a->next;
	}
	a = start;
	while (a->next)
	{
		if (down > a->data && down < a->next->data)
			break ;
		j++;
		a = a->next;
	}
	//printf("num is holding %d size is holding %d and i is holding %d\n",num,size,  i);
	size = size / 2;
	if (size >= i && size >= j)
	{
		if (i > j)
			rrb(b);
		return (1);
	}
	else if (size <= i && size <= j)
	{
		if (i < j)
			rrb(b);
		return (0);
	}
	return (the_farest_from_size(size, i, j, b));
}

void	sort(t_list **a, t_list **b, int min)
{
	int	size;
	int	i;
	t_list	*start;
	while (*b)
	{
		if ((*b)->data < (*a)->data && (*b)->data > lst_last(*a)->data)
			pa(a, b);
		//else if ((*b)->data > (*a)->data && (*b)->data < lst_last(*a)->data)
		//	pa(a, b);
		else if(get_the_quickest_way((*b)->data, lst_last(*b)->data, *a, b))
		{
			while (*a)
			{
				if ((*b)->data < (*a)->data && (*b)->data > lst_last(*a)->data)
				{
					pa(a, b);
					break ;
				}
				ra(a);
			}
		}
		else if(get_the_quickest_way((*b)->data, lst_last(*b)->data, *a, b) == 0)
		{
			while (*a)
			{
				if ((*b)->data < (*a)->data && (*b)->data > lst_last(*a)->data)
				{
					pa(a, b);
					break ;
				}
				rra(a);
			}
		}
	}
	i = 0;
	start = *a;
	size = ft_lst_size(*a);
	while (*a)
	{
		if ((*a)->data == min)
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
			if ((*a)->data == min)
				break;
			ra(a);
		}
	}
	else
	{
		while (*a)
		{
			if ((*a)->data == min)
				break;
			rra(a);
		}
	}
}


/*
void	insertion_sort2(t_list **a, t_list **b)
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
}

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
}

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
}

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
*/