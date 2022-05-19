/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:05 by samajat           #+#    #+#             */
/*   Updated: 2022/05/19 22:08:03 by samajat          ###   ########.fr       */
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
    static t_fork                  *right_for_next;
    static t_philosopher           *first_philosopher;
    pthread_mutex_t                mutex;

    if (philosopher->identity == 1)
    {
        philosopher->left_fork->available = FALSE;
        printf ("------------\n");
        philosopher->left_fork->index = 0;
        first_philosopher = philosopher;
    }
    else
    {
        philosopher->left_fork->index = philosopher->identity - 1;
        philosopher->right_fork = right_for_next;
    }
    philosopher->left_fork->available = TRUE;
    philosopher->left_fork->mutex = &mutex;
    pthread_mutex_init (philosopher->left_fork->mutex, NULL);
    right_for_next = philosopher->left_fork;
    if (forks_number == philosopher->identity)
        first_philosopher->right_fork = philosopher->left_fork;
}


t_philosopher    *initialize_philosopher(int identity, int forks_number)
{
    t_philosopher   *philsopher;

    philsopher = malloc (sizeof(t_philosopher));
    philsopher->left_fork = malloc (sizeof(t_fork));
    philsopher->right_fork = malloc (sizeof(t_fork));
    if (!philsopher)
        return (NULL);
    philsopher->identity = identity;
    philsopher->status = NOTHING;
    initialize_forks(philsopher, forks_number);
    return (philsopher);
}

void    build_philosophers(t_list **philsophers, t_data data)
{
    int             identity;
    t_philosopher   *new_philosopher;
    t_list *temp;

    identity = 1;
    while (identity <= data.number_of_philosophers)
    {
        new_philosopher = initialize_philosopher(identity, data.number_of_philosophers);
        temp = ft_lstnew((void *)new_philosopher);
        ft_lstadd_front(philsophers, temp);
        identity++;
    }
}