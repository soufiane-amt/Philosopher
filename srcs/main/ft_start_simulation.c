/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:23:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 22:08:11 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    ft_start_dinner (t_data *data, t_philosopher *philosopher)
{
    if(wait_untill_taking_forks(data, philosopher))
    {
        do_eating(data, philosopher);
        do_sleeping(data, philosopher);
        do_thinking(data, philosopher);
        ft_start_dinner(data, philosopher);
    }
    else
    {
        printf("Game over!\n");
        exit(1);
    }
}