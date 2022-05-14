/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 23:23:28 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int do_sleeping (t_input *input, t_philosopher *philosopher)
{
    printf("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
    printf ("%d is sleeping ", philosopher->identity);
    usleep(input->time_to_sleep * 1000);
}


int do_thinking (t_input *input, t_philosopher *philosopher)
{
    printf("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
    printf ("%d is thinking ", philosopher->identity);
    while (!philosopher->left_fork_available.fork_available &&
        !philosopher->right_fork_available.fork_available);
}


int do_eating (t_input *input, t_philosopher *philosopher)
{
    printf ("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
    printf ("%d is eating ", philosopher->identity);
    usleep(input->time_to_eat * 1000);
}

int wait_untill_taking_forks(t_input *input, t_philosopher *philosopher)
{
    if(philosopher->left_fork_available.fork_available)
    {
        philosopher->left_fork_available.fork_token = TRUE;
        philosopher->left_fork_available.fork_available = FALSE;
        printf("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if(philosopher->right_fork_available.fork_available)
    {
        philosopher->right_fork_available.fork_token = TRUE;
        philosopher->right_fork_available.fork_available = FALSE;
        printf("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if (!philosopher->left_fork_available.fork_token || !philosopher->right_fork_available.fork_token)
        wait_untill_taking_forks(input, philosopher);
    return(1);
}
