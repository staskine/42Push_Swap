/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:41:11 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:23:52 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*rest;

	first = (*stack)->next;
	rest = first->next;
	first->next = (*stack);
	(*stack)->next = rest;
	(*stack) = first;
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = (*stack)->next;
	last = find_last(stack);
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = first;
}

void	r_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = find_last(stack);
	last = (*stack);
	while (last->next->next != NULL)
		last = last->next;
	first->next = (*stack);
	last->next = NULL;
	(*stack) = first;
}

void	push_to_stack(t_node **stack_s, t_node **stack_d)
{
	t_node	*first;

	first = (*stack_s);
	(*stack_s) = (*stack_s)->next;
	if ((*stack_d) == NULL)
		first->next = NULL;
	else
		first->next = (*stack_d);
	(*stack_d) = first;
}
