/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:23:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/21 18:58:53 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    *ft_start_dinner (void *philosopher)
{
    static long launching_time;

    if (!launching_time)
        launching_time = get_actual_time_in_milliseconds();
    if(wait_untill_taking_forks(launching_time, philosopher))
    {
        do_eating(launching_time, philosopher);
        do_sleeping(launching_time, philosopher);
        do_thinking(launching_time, philosopher);
        ft_start_dinner(philosopher);
    }
    else
    {
        printf("Game over!\n");
        exit(1);
    }
    return (NULL);
}

int     let_the_fun_bigins(t_list   **philosophers)
{
    t_list  *temp;

    temp = *philosophers;
    while (temp)
    {
        pthread_join(((t_philosopher *)temp->content)->thread_id, NULL);
        temp = temp->next;
    }
    return (0);
}