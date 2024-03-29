/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:21:21 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:22:05 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pb_or_ra(t_node **stack_a, t_node **stack_b, int i)
{
	if ((((*stack_a)->index >> i) & 1) == 0)
		pb(stack_a, stack_b);
	else
		ra(stack_a);
}

static void	rb_or_pa(t_node **stack_a, t_node **stack_b, int i)
{
	if ((((*stack_b)->index >> i) & 1) == 0 && is_inorder(*stack_a) != 0)
		rb(stack_b);
	else
		pa(stack_b, stack_a);
}

void	sort(t_node **stack_a)
{
	t_node	*stack_b;
	int		i;
	int		len;

	i = 0;
	stack_b = NULL;
	while (is_inorder(*stack_a) != 0 || stack_b != NULL)
	{
		len = lstsize(*stack_a);
		while (len > 0 && is_inorder(*stack_a) != 0)
		{
			pb_or_ra(stack_a, &stack_b, i);
			len--;
		}
		i++;
		len = lstsize(stack_b);
		while (len > 0)
		{
			rb_or_pa(stack_a, &stack_b, i);
			len--;
		}
	}
}
