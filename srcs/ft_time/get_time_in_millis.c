/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_millis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:42:00 by samajat           #+#    #+#             */
/*   Updated: 2022/05/26 22:35:52 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long    get_actual_time_in_milliseconds()
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}