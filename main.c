/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:15:33 by sataskin          #+#    #+#             */
/*   Updated: 2024/03/28 16:20:15 by sataskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (1);
	}
	else
	{
		if (check_input(argc, argv) != 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	if (push_swap(argc, argv) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
