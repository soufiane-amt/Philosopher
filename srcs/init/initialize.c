/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:05 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 00:05:33 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    initialize_user_input (t_data *data, char   **argv)
{
    //handle bad args
    data->launching_time = get_actual_time_in_milliseconds ();
    data->number_of_philosophers = (long)ft_atoi(argv[1]);
    data->time_to_die = (long)ft_atoi(argv[2]);
    data->time_to_eat = (long)ft_atoi(argv[3]);
    data->time_to_sleep = (long)ft_atoi(argv[4]);
}