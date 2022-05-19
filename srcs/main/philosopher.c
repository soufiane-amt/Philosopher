/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:35 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 00:55:48 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main (int   argc, char  **argv)
{
    t_data          data;
    t_list   **philsophers;
    t_list      *temp;

    philsophers = malloc (sizeof(t_philosopher *));
    *philsophers = NULL;
    (void)argc;
    initialize_user_input(&data, argv);
    build_philosophers(philsophers, data);
    temp = *philsophers;
    // while (temp)
    // {
    //     printf("-->%p\n", ((t_philosopher *)temp->content)->right_fork->mutex);
    //     temp = temp ->next;
    // }
    // printf("-->%d\n", ((t_philosopher *)(*philsophers)->next->next->content)->right_fork->index);
    // printf("-->%d\n", ((t_philosopher *)(*philsophers)->content)->left_fork->index);
    print_philo_data(philsophers);
}