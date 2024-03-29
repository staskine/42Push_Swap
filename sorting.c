/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:12:15 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:22:56 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_node **stack)
{
	int	first;
	int	sec;
	int	third;

	first = (*stack)->index;
	sec = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if ((is_inorder(*stack)) == 0)
		return ;
	if (first < sec && first < third)
	{
		rra(stack);
		sa(stack);
	}
	else if (first > sec && sec < third && first < third)
		sa(stack);
	else if (first < sec && sec > first)
		rra(stack);
	else if (first > sec && sec < third && first > third)
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_small(t_node **stack_a, int i)
{
	t_node	*stack_b;

	stack_b = NULL;
	while (lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->index <= i - 3)
			pb(stack_a, &stack_b);
		else
			ra(stack_a);
	}
	sort_tiny(stack_a);
	while (stack_b != NULL)
	{
		if (stack_b->index != i - 3)
			rb(&stack_b);
		else
		{
			pa(&stack_b, stack_a);
			i--;
		}
	}
}

void	sort_stack(t_node **stack)
{
	int	many;

	many = lstsize(*stack);
	if (many == 2)
		sa(stack);
	else if (many == 3)
		sort_tiny(stack);
	else if (many <= 10)
		sort_small(stack, many);
	else
		sort(stack);
}
