/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:26:57 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:50:03 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_node;

/*		INPUT ERROR HANDLING		*/

int		check_input(int argc, char **argv);
int		check_format(char *str, int argc);
int		is_inorder(t_node *stack);
void	check_dupes(t_node *stack);

/*		THIS IS FOR FREEING		*/

void	free_split(char **array);
void	free_stack(t_node *stack);

/*		UTILS FOR PUSH_SWAP		*/

t_node	*find_last(t_node **stack);
int		lstsize(t_node *lst);

/*		FOR PREPARING THE STACK		*/

int		push_swap(int argc, char **argv);
void	add_index(t_node *stack);
void	ft_atoi_check(char *str, t_node *new, t_node *stack);
void	add_index(t_node *stack);

/*		FOR SORTING		*/

void	sort_stack(t_node **stack);
void	sort_tiny(t_node **stack);
void	sort_small(t_node **stack_a, int i);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	r_rotate(t_node **stack);
void	push_to_stack(t_node **stack_s, t_node **stack_d);
void	push_to_b(t_node **stack_b, t_node **stack_a, int max);
void	sort(t_node **stack_a);

/*		FOR COMMANDS		*/

void	sb(t_node **stack_a);
void	rb(t_node **stack_a);
void	rrb(t_node **stack_a);
void	pb(t_node **stack_b, t_node **stack_a);
void	sa(t_node **stack_a);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
void	pa(t_node **stack_b, t_node **stack_a);
void	ss(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif