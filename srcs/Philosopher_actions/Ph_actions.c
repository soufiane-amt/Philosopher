/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 23:56:42 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int do_sleeping (t_data *data, t_philosopher *philosopher)
{
    printf("%d ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is sleeping ", philosopher->identity);
    usleep(data->time_to_sleep / 1000);
}


int do_eating (t_data *data, t_philosopher *philosopher)
{
    printf ("%d ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is eating ", philosopher->identity);
    usleep(data->time_to_eat / 1000);
}

int do_thinking (t_data *data, t_philosopher *philosopher)
{
    printf("%d ", get_passed_time_in_milli(data->launching_time));
    printf ("%d is thinking ", philosopher->identity);
}


int wait_untill_taking_forks(t_data *data, t_philosopher *philosopher)
{
    if(philosopher->left_fork_available.fork_available)
    {
        philosopher->left_fork_available.fork_token = TRUE;
        philosopher->left_fork_available.fork_available = FALSE;
        printf("%d ", get_passed_time_in_milli(data->launching_time));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if(philosopher->right_fork_available.fork_available)
    {
        philosopher->right_fork_available.fork_token = TRUE;
        philosopher->right_fork_available.fork_available = FALSE;
        printf("%d ", get_passed_time_in_milli(data->launching_time));
        printf ("%d is taking a fork ", philosopher->identity);
    }
    if (!philosopher->left_fork_available.fork_token || !philosopher->right_fork_available.fork_token)
        wait_untill_taking_forks(data, philosopher);
    return(1);
}
