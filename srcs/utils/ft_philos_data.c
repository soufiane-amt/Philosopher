/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 00:43:02 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 18:44:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    print_philo_info(t_list *temp)
{
    printf ("-philosopher number %d\n", ((t_philosopher *)(temp)->content)->identity);
    printf ("-left fork index : %d\n", ((t_philosopher *)(temp)->content)->left_fork->index);
    printf ("-left fork add : %p\n", ((t_philosopher *)(temp)->content)->left_fork->mutex);
    printf ("-right fork index : %d\n", ((t_philosopher *)(temp)->content)->right_fork->index);
    printf ("-right fork add : %p\n", ((t_philosopher *)(temp)->content)->right_fork->mutex);
    printf("-----------------------\n");
}
void    print_philo_data(t_list **philos)
{
    t_list  *temp;

    temp = *philos;
    while (temp)
    {
        print_philo_info(temp);
        temp = temp ->next;
    }
}