/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:23:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 20:55:54 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*check_death(void *a)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) a;
	while (69)
	{
		if (get_actual_time_in_milliseconds() - philo->last_time_eaten >= philo->data->time_to_die)
		{
			pthread_mutex_lock(&philo->data->printing_mutex);
			printf("%ld %d died \n", get_passed_time_in_milli(philo->last_time_eaten), philo->identity);
            pthread_mutex_unlock(&philo->data->hhhhh);
            break;
		}
        usleep(100);
	}
	return (NULL);
}

void    *ft_start_dinner (void *philosopher)
{
	static long launching_time;
	t_philosopher *tr;
	pthread_t death_angel;
	
	// printf ("----\n");
	tr = (t_philosopher *)philosopher;  
	launching_time = get_actual_time_in_milliseconds();
	tr->last_time_eaten = launching_time;
	pthread_create(&death_angel, NULL, check_death, tr);
	pthread_detach(death_angel);
	if (tr->identity % 2 == 0)
		usleep(tr->data->time_to_eat * 1000);
	while(69)
	{
		wait_untill_taking_forks(launching_time, philosopher);
		do_eating(launching_time, philosopher);
		do_sleeping(launching_time, philosopher);
		do_thinking(launching_time, philosopher);
	}
	return (NULL);
}

int     let_the_fun_bigins(t_list   **philosophers)
{
	t_list  *temp;

	temp = *philosophers;
	while (temp)
	{
		pthread_detach(((t_philosopher *)temp->content)->thread_id);
		temp = temp->next;
	}
	return (0);
}