/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:40:57 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/28 15:14:37 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lets_sort_it(t_list **a, t_list **b)
{
	check_doubles(*a);
	if(check_if_sorted(*a) == 0)
		return;
	detect_range(a, b);
}

void	detect_range(t_list **a, t_list **b)
{
	int	i;
	
	(void)b;
	i = ft_lst_size(*a);
	if (i ==2 || i == 3)
		three_numbers_sort(a);
	else if (i == 4)
		four_numbers_sort(a, b);
	else if (i == 5)
		five_numbers_sort(a, b);
	else if (i > 5)
		sort(a, b);
	//quick_sort(a, b);
		//pre_sort(a, b);
	//sort_with_chunks(a, b);
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
	lets_sort_it(&a,&b);
	//test_func
	/*
	t_list *new = a;
	t_list *new2 = b;
	printf("stack a\n");
	while (new)
	{
		printf("%d\n",new->data);
		new = new->next;
	}
	printf("stack b\n");
	while (new2)
	{
		printf("%d\n",new2->data);
		new2= new2->next;
	}
	*/
	//end of test fun
	
	free_linked_list(&b);
	free_linked_list(&a);
	return (0);
}
