/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_passed_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:46:14 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 23:37:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long    get_passed_time_in_milli(long program_launch_time)
{
    return (get_actual_time_in_milliseconds() - program_launch_time);
}
