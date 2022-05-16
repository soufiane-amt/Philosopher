/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_contain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:04:38 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 01:47:20 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include "philosopher.h"

int ft_lst_contain(t_list **lst, void *value, int   type)
{
    t_list	*temp;

	temp = *lst;
    if (!value || !temp)
        return (0);
	while (temp)
	{
        if (type == CHAR)
            if (!ft_strcmp((char *)value, (char *)temp->content))
                return (1);
        if (type == INT && *(int *)value == *(int *)temp->content)
            return (1);
		temp = temp->next;
	}
    return (0);
}