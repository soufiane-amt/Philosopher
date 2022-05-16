/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 01:49:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void do_sleeping (t_data *data, t_philosopher *philosopher)
{
    printf("%ld ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is sleeping ", philosopher->identity);
    usleep(data->time_to_sleep * 1000);
}


void do_eating (t_data *data, t_philosopher *philosopher)
{
    printf ("%ld ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is eating ", philosopher->identity);
    usleep(data->time_to_eat * 1000);
}

void do_thinking (t_data *data, t_philosopher *philosopher)
{
    printf("%ld ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is thinking ", philosopher->identity);
}


int wait_untill_taking_forks(t_data *data, t_philosopher *philosopher)
{
    if(philosopher->left_fork.available)
    {
        philosopher->left_fork.available = FALSE;
        printf("%ld ", get_passed_time_in_milli(data->launching_time));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if(philosopher->right_fork.available)
    {
        philosopher->right_fork.available = FALSE;
        printf("%ld ", get_passed_time_in_milli(data->launching_time));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if (!philosopher->left_fork.available || !philosopher->right_fork.available)
        wait_untill_taking_forks(data, philosopher);
    return(1);
}
