/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:13:20 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:24:04 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

void	ft_lstprint(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
	}
}
