/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:18:10 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 17:16:57 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_format(char *str, int argc)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= '9' && str[i] >= '0') || (str[i] == ' ' && argc == 2))
			i++;
		else if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] <= '9' && str[i] >= '0')
				i++;
			else
				return (-1);
		}
		else
			return (-1);
	}
	if (str[0] == '\0')
		return (-1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	tracker;

	tracker = 1;
	while (tracker < argc)
	{
		if (check_format(argv[tracker], argc) == 0)
			tracker++;
		else
			return (-1);
	}
	return (0);
}

void	check_dupes(t_node *stack)
{
	t_node	*temp;
	t_node	*check;

	check = stack;
	while (check)
	{
		temp = check->next;
		while (temp)
		{
			if (temp->num == check->num)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			temp = temp->next;
		}
		check = check->next;
	}
}
