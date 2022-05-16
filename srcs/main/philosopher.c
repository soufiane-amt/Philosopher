/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:35 by samajat           #+#    #+#             */
/*   Updated: 2022/05/17 00:43:22 by samajat          ###   ########.fr       */
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
    while (temp)
    {
        printf("-->%d\n", ((t_philosopher *)temp->content)->identity);
        temp = temp ->next;
    }
    
}