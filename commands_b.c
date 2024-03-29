/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:52:17 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:15:34 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	r_rotate(stack_b);
	write(1, "rrb\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push_to_stack(stack_a, stack_b);
	write(1, "pb\n", 3);
}
