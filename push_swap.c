/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:40:57 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/21 18:09:06 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort()
{
	
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
	check_doubles(a);
	
	//test_func
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
	//end of test fun
	
	free_linked_list(&b);
	free_linked_list(&a);
	return (0);
}
