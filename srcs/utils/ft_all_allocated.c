/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_allocated.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:10:09 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:25:06 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_all_allocated(int number_of_variables, ...)
{
	va_list	args;
	va_list	p_args;
	int		i;
	void	*t_free;

	va_start(args, number_of_variables);
	i = 0;
	while (i < number_of_variables)
	{
		if (!va_arg(args, char *))
			break ;
		if (i == number_of_variables - 1)
			return (1);
		i++;
	}
	i = 0;
	va_start(p_args, number_of_variables);
	while (i < number_of_variables)
	{
		t_free = va_arg(p_args, void *);
		if (t_free)
			free(t_free);
		i++;
	}
	return (0);
}
