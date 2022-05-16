/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:27 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 00:55:31 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "t_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc (sizeof(t_phil));
    printf ("-----------\n");
	if (!node)
        return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
