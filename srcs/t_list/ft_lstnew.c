/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:27 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 00:32:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "t_list.h"

t_list	*ft_lstnew(void *content, int   type)
{
	t_list	*node;

	node = (struct s_list *) malloc (sizeof(struct s_list));
	if (!node)
        return (NULL);
    if (type == INT)
	    node -> content = (int *)content;
    else
	    node -> content = (char *)content;
	node -> next = NULL;
	return (node);
}
