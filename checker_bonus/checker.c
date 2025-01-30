/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:00 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/30 18:31:11 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	error_hundle(t_list **a, t_list **b, char *line)
{
	free_linked_list(b);
	free_linked_list(a);
	free(line);
	write(2, "Error\n", 6);
	exit(1);
}

void	apply_action(char *line, t_list **a, t_list **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_no_write(*a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_no_write(*b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_no_write(*a, *b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_no_write(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_no_write(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_no_write(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_no_write(b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_no_write(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_no_write(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_no_write(a, b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_no_write(a, b);
	else
		error_hundle(a, b, line);
}

void	start_sorting(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_action(line, a, b);
		free(line);
		line = get_next_line(0);
	}
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
	start_sorting(&a, &b);
	if (check_if_sorted(a) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_linked_list(&b);
	free_linked_list(&a);
	return (0);
}
