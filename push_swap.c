/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 09:22:57 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:17:59 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_next(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index == -1)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}

void	add_index(t_node *stack)
{
	int		index;
	t_node	*temp;
	t_node	*max_val;

	index = lstsize(stack);
	temp = stack;
	max_val = stack;
	if (index == 0)
		return ;
	while (index > 0)
	{
		temp = temp->next;
		if (temp->num > max_val->num && temp->index == -1)
			max_val = temp;
		if (temp->next == NULL)
		{
			max_val->index = index;
			index--;
			max_val = find_next(stack);
			temp = stack;
		}
	}
}

void	make_stack(t_node **stack, char **argv, int start)
{
	t_node	*new;
	t_node	*last;
	int		i;

	i = start;
	while (argv[i] != NULL)
	{
		new = (t_node *)malloc(sizeof(t_node));
		if (!new)
		{
			free_stack(*stack);
			write(2, "Error\n", 6);
			exit (1);
		}
		new->next = NULL;
		ft_atoi_check(argv[i], new, *stack);
		if (!(*stack))
			*stack = new;
		else
		{
			last = find_last(stack);
			last->next = new;
		}
		i++;
	}
}

int	push_swap(int argc, char **argv)
{
	t_node	*stack_a;
	char	**args;

	stack_a = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		make_stack(&stack_a, args, 0);
		free_split(args);
	}
	if (argc > 2)
		make_stack(&stack_a, argv, 1);
	if (stack_a == NULL)
		return (1);
	if (lstsize(stack_a) > 1)
	{
		check_dupes(stack_a);
		add_index(stack_a);
		if (is_inorder(stack_a) != 0)
			sort_stack(&stack_a);
	}
	free_stack(stack_a);
	return (0);
}
