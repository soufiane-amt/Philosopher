/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prelast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:22:54 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 00:19:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_get_prelast(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (temp && temp -> next)
		while (temp->next->next)
			temp = temp->next;
	return (temp);
}
