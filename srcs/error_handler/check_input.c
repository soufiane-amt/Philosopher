/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 21:51:13 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 22:31:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isnbr(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen (str);
	if (str[i] == '+')
	{
		i = 1;
		if (length == 1)
			return (0);
	}
	while (i < length)
	{
		if (!ft_isdigit (str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	nbr_is_int(char *str)
{
	long	nbr;

	nbr = ft_atoi(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

int	user_input_is_valid (char	**argv, int argc)
{
	int	i;

	i = 0;
	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong amount of arguments." , 2);
		return (0);
	}
	while (argv[i])
	{
		if (!ft_isnbr(argv[i]) || !nbr_is_int(argv[i]))
		{
			ft_putstr_fd("Error: At least one wrong argument", 2);
			return (0);
		}
		i++;
	}
	return (1);
}