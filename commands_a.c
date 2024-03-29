/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:51:58 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:14:55 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	r_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push_to_stack(stack_b, stack_a);
	write(1, "pa\n", 3);
}
