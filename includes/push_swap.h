/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:55:42 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/23 16:00:36 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

char	**args_check(int ac, char **av);
void	arg_num_check(int ac);
void	arg_check_int(char **av);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**args_combinor(char **av);
void	free_array(char **str);
int		ft_strlen(char *str);
int		ft_atoi(char *str, char **args, t_list *lst);
void	wrong_number(char **args, t_list *lst);
t_list	*stack_filler(char **args);
int		ft_lst_add_back(t_list **lst, int content);
t_list	*ft_lst_new(int content);
void	free_linked_list(t_list **lst);
void	check_doubles(t_list *lst);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
int		ft_lst_size(t_list *lst);
int 	check_if_sorted(t_list *a);
void	lets_sort_it(t_list **a, t_list **b);
void	detect_range(t_list **a, t_list **b);
t_list	*lst_last(t_list *last);
void	algo_num_1(t_list *a);
#endif