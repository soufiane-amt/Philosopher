/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:05 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 01:56:42 by samajat          ###   ########.fr       */
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


void    initialize_forks(t_philosopher *philosopher, int forks_number)
{
    if (philosopher->identity == 1)
    {
        philosopher->left_fork.index = 0;
        philosopher->right_fork.index = forks_number - 1;
    }
    else
    {
        philosopher->left_fork.index = philosopher->identity - 1;
        philosopher->right_fork.index = philosopher->identity - 2;
    }
    philosopher->left_fork.available = TRUE;
    philosopher->right_fork.available = TRUE;
    pthread_mutex_init (&(philosopher->left_fork.mutex), NULL);
    pthread_mutex_init (&(philosopher->right_fork.mutex), NULL);
}


t_philosopher    initialize_philosopher(int identity, int forks_number)
{
    t_philosopher   philsopher;

    philsopher.identity = identity;
    philsopher.status = NOTHING;
    initialize_forks(&philsopher, forks_number);
    return (philsopher);
}

void    build_philosophers(t_list **philsophers, t_data data)
{
    int             identity;
    t_philosopher   new_philosopher;

    identity = 1;
    while (identity <= data.number_of_philosophers)
    {
        new_philosopher = initialize_philosopher(identity, data.number_of_philosophers);
        ft_lstadd_front(philsophers, ft_lstnew((void *)&new_philosopher));
        printf("%d\n", new_philosopher.identity);
        identity++;
    }
}