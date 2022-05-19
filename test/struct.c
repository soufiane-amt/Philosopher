/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:55:13 by samajat           #+#    #+#             */
/*   Updated: 2022/05/19 21:42:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
typedef struct s_test
{
	int     n;
	char    c;
}   t_test	;

void increa (int    *i)
{
    *i = 0;
    (*i)++;
}
int main ()
{
    t_test *t;

    // increa(&t.n);
    printf ("-->%p\n" ,(void *)t);
    printf ("-->%p\n" ,(void *)t);
    printf ("-->%p\n" ,(void *)t);
    printf ("-->%p\n" ,(void *)t);
}