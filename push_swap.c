/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:40:57 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/20 15:46:43 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	//t_list	a;
	//t_list	b;
	char **str_num;
	
	str_num = args_check(ac, av);
	int i = 0;
	while(str_num[i])
	{
		printf("%d\n", ft_atoi(str_num[i], str_num));
		i++;
	}
	free_array(str_num);
	return (0);
}
