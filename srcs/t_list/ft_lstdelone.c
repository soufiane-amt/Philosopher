/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:00:19 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 00:30:46 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "t_list.h"

void	ft_lstdelone(t_list **lst)
{
	if (!lst || !(*lst)->content)
		return ;
    free((*lst)->content);
    (*lst)->content = NULL;
	free (*lst);
	lst = NULL;
}