/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:53:00 by samajat           #+#    #+#             */
/*   Updated: 2022/05/21 21:49:13 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int    ft_usleep(long  time_in_milli, t_philosopher *philosopher)
// {
//     long    start_time;

//     start_time = get_actual_time_in_milliseconds();
//     while (get_actual_time_in_milliseconds() - start_time < time_in_milli)
//     {
//         if(the_philosopher_is_dead(philosopher))
//             return (0);
//     }
//     return (1);
// }

int    ft_usleep(long  time_in_milli, t_philosopher *philosopher)
{
    long    start_time;

    (void)philosopher;
    start_time = get_actual_time_in_milliseconds();
    while (get_actual_time_in_milliseconds() - start_time > time_in_milli);
    return (0);
}
