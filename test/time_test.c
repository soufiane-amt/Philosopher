/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:40:57 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 23:59:53 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>


int main ()
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    printf ("%ld\n", current_time.tv_sec * 1000);
}