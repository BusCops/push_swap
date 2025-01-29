/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:57:23 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 17:08:14 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 1;
	while (i)
	{
		i = 0;
		while (j < size - 1)
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

int	*malloc_and_sort(t_list *a)
{
	int	*arr;
	int	size;
	int	i;

	i = 0;
	size = ft_lst_size(a);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = a->data;
		i++;
		a = a->next;
	}
	sort_arr(arr, size);
	return (arr);
}

void	get_the_mmm(t_list *a, min_med_max *values)
{
	int	*arr;
	int	size;

	size = ft_lst_size(a) - 1;
	arr = malloc_and_sort(a);
	if (!arr)
	{
		free_linked_list(&a);
		exit(7);
	}
	values->min = arr[0];
	if (size % 2 == 0)
		values->med = arr[(size - 1) / 2];
	else
		values->med = arr[size / 2];
	values->max1 = arr[size - 4];
	values->max2 = arr[size - 3];
	values->max3 = arr[size - 2];
	values->max4 = arr[size - 1];
	values->max5 = arr[size];
	free(arr);
}

void	push_rra(t_list **a, t_list **b, int med)
{
	while (*a)
	{
		if ((*a)->data == med)
		{
			pb(a, b);
			break ;
		}
		rra(a);
	}
}

void	push_ra(t_list **a, t_list **b, int med)
{
	while (*a)
	{
		if ((*a)->data == med)
		{
			pb(a, b);
			break ;
		}
		ra(a);
	}
}
