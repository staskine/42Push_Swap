/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:08:39 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:14:18 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_check(char *str, t_node *new, t_node *stack)
{
	char	*number;

	if (str[0] == '+')
		str++;
	new->num = ft_atoi(str);
	number = ft_itoa(new->num);
	if (ft_strcmp(number, str) != 0)
	{
		free(new);
		free_stack(stack);
		free(number);
		write(2, "Error\n", 6);
		exit (1);
	}
	free(number);
	new->index = -1;
}

int	is_inorder(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->num < temp->next->num)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}
