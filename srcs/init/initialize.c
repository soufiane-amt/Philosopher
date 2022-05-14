/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:05 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 00:40:32 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    initialize_user_input (t_input  *uinput, char   **argv)
{
    //handle bad args
    uinput->number_of_philosophers = (long)ft_atoi(argv[1]);
    uinput->time_to_die = (long)ft_atoi(argv[2]);
    uinput->time_to_eat = (long)ft_atoi(argv[3]);
    uinput->time_to_sleep = (long)ft_atoi(argv[4]);
    
}