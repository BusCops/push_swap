/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:48:49 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/29 16:47:01 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_numbers_sort(t_list **a)
{
	if ((*a)->data < (*a)->next->data)
		sa(*a);
	if ((*a)->data > lst_last(*a)->data)
		ra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

int	find_min(t_list *a)
{
	int min;
	
	min = a->data;
	while (a)
	{
		if (min > a->data)
			min = a->data;
		a = a->next;
	}
	return (min);
}

void	push_the_min(t_list **a, t_list **b, int min)
{
	int	i;
	int	size;
	t_list *start;

	i = 0;
	size = ft_lst_size(*a);
	start = *a;
	while (*a)
	{
		if ((*a)->data == min)
			break;
		*a = (*a)->next;
		i++;
	}
	*a = start;
	if (size / 2 >= i)
		push_ra(a, b, min);
	else
		push_rra(a, b, min);
}

void	four_numbers_sort(t_list **a, t_list **b)
{
	int	min;
	
	min = find_min(*a);
	push_the_min(a, b, min);
	three_numbers_sort(a);
	pa(a, b);
}

void	five_numbers_sort(t_list **a, t_list **b)
{
	int min;

	min = find_min(*a);
	push_the_min(a, b, min);
	four_numbers_sort(a, b);
	pa(a, b);
	
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
	return(arr);
}

void	get_the_MMM(t_list *a, Min_Med_Max *values)
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

void	push_the_med(t_list **a, t_list **b, Min_Med_Max values)
{
	int	i;
	int	size;
	t_list *start;

	i = 0;
	size = ft_lst_size(*a);
	start = *a;
	while (*a)
	{
		if ((*a)->data == values.med)
			break;
		*a = (*a)->next;
		i++;
	}
	*a = start;
	if (size / 2 > i)
		push_ra(a, b, values.med);
	else
		push_rra(a, b, values.med);
}

void	pre_sort(t_list **a, t_list **b, Min_Med_Max values)
{
	push_the_med(a, b, values);
	while (ft_lst_size(*a) != 5)
	{
		if ((*a)->data == values.max1 || (*a)->data == values.max2 || (*a)->data == values.max3 || (*a)->data == values.max4 || (*a)->data == values.max5)
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

void	Number_movement_reset(Number_mv *num)
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

void	best_move_to_a(t_list *a, Number_mv *num, int max)
{
	int	i;
	int	size;
	//printf("num is %d aaaaaaaaaaaaaaaaaaaaaaaaaaaa           %d\n",num->num, a->data);
	i = 0;
	size = ft_lst_size(a);
	
	if (num->num < a->data && num->num < lst_last(a)->data && a->data < lst_last(a)->data)
		num->pa_mv++;
	else if (num->num < a->data && num->num > lst_last(a)->data)
		num->pa_mv++;
	else
	{
		while (a->next)
		{
			if ((num->num > a->data && num->num < a->next->data) || (a->data == max && num->num < a->next->data ))
			{
				i++;
				break;
			}
			a = a->next;
			i++;
		}
	//printf("num is %d aaaaaaaaaaaaaaaaaaaaaaaaaaaa           %d\n",num->num, i);
	if (size / 2 >= i)
		num->ra_mv = i;
	else
		num->rra_mv = size - i;
	num->pa_mv++;
	}
}

void	best_move_from_b(t_list *b, Number_mv *num)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_lst_size(b);
	while (b)
	{
		//printf("b is holding %d and num is %d\n",b->data, num->num  );
		if (num->num == b->data)
			break;
		b = b->next;
		i++;
	}
	//printf("dfsfdfsfsdf     %d\n",i);
	if (size / 2 >= i)
		num->rb_mv = i;
	else
		num->rrb_mv = size - i;
}

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
	Number_movement_reset(&num);
	Number_movement_reset(&tmp);
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
			Number_movement_reset(&tmp);
			*b = (*b)->next;
		}
		*b = start;
		apply_best_move(a, b, &num);
		Number_movement_reset(&num);
		start  = *b;
		
	}
}

void	sort(t_list **a, t_list **b)
{
	Min_Med_Max	values;

	get_the_MMM(*a, &values);
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


////////////////////////////////////////////


/*

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
	my_sort(a, b, min);
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

int	find_position_of_the_number(t_list *a,int num)
{
	int	i;

	i = 0;
	while(a->next)
	{
		if (num > a->data && num < a->next->data )
			break;
		i++;
		a = a->next;
	}
	return (i);
}

int	get_the_quickest_way(int up, int down, t_list *a, t_list **b)
{
	int	size;
	int	i;
	int	j;
	t_list	*start;

	start = a;
	size = ft_lst_size(a);
	i = find_position_of_the_number(a, up);
	j = find_position_of_the_number(a, down);
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

void	my_sort(t_list **a, t_list **b, int min)
{
	int	size;
	int	i;
	t_list	*start;
	while (*b)
	{
		if ((*b)->data < (*a)->data && (*b)->data > lst_last(*a)->data)
			pa(a, b);
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
*/
/////////////////////////////////////////////////////////////////////////

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