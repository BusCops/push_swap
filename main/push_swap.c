/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:40:57 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/30 18:32:38 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lets_sort_it(t_list **a, t_list **b)
{
	check_doubles(*a);
	if (check_if_sorted(*a) == 0)
		return ;
	detect_range(a, b);
}

void	detect_range(t_list **a, t_list **b)
{
	int	i;

	i = ft_lst_size(*a);
	if (i == 2 || i == 3)
		three_numbers_sort(a);
	else if (i == 4)
		four_numbers_sort(a, b);
	else if (i == 5)
		five_numbers_sort(a, b);
	else if (i > 5)
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**str_num;

	b = NULL;
	str_num = args_check(ac, av);
	a = stack_filler(str_num);
	free_array(str_num);
	if (!a)
		return (1);
	lets_sort_it(&a, &b);
	free_linked_list(&b);
	free_linked_list(&a);
	return (0);
}
