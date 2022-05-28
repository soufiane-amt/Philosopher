/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelete_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:54:55 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:23:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

int	ft_lstdelete_top(t_list **lst)
{
	t_list	*temp;

	if (!*lst)
		return (0);
	temp = *lst;
	*lst = temp -> next;
	free (temp);
	temp = NULL;
	return (1);
}
