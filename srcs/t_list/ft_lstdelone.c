/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:19 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 23:34:43 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "t_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	// printf("About to delete the phili")
	del (lst -> content);
	free (lst);
	lst = NULL;
}