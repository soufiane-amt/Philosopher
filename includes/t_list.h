/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 00:21:59 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 22:50:02 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

//Headers
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void        *content;
    struct  s_list  *next;
}   t_list;

//Type
#define CHAR 55
#define INT  111
#define OTHER_T  141

t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	ft_lstprint(t_list *lst);
int     ft_lst_contain(t_list **lst, void *value, int   type);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
int	    ft_lstdelete_last(t_list **lst);
int	    ft_lstdelete_top(t_list **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstprint(t_list *lst);
int	    ft_lstsize(t_list *lst);

#endif