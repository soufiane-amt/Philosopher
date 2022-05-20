/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:58:45 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 21:07:39 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <sys/time.h>

long    get_actual_time_in_milliseconds()
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
}

int    ft_usleep(long  time_in_milli)
{
    long    start_time;

    start_time = get_actual_time_in_milliseconds();
    while (get_actual_time_in_milliseconds() - start_time < time_in_milli);
    return (0);
}


int main ()
{
    printf ("start dinner at %ld.\n", get_actual_time_in_milliseconds()/1000);
    ft_usleep (10000);
    printf ("dinner is over at %ld.\n", get_actual_time_in_milliseconds()/1000);    
}