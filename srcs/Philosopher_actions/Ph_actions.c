/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:20:09 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	do_sleeping(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->left_fork->mutex);
	pthread_mutex_unlock(philosopher->right_fork->mutex);
	pthread_mutex_lock(&philosopher->data->printing_mutex);
	printf("%ld %d is sleeping \n", get_passed_time_in_milli(
			philosopher->data->launching_time), philosopher->identity);
	pthread_mutex_unlock(&philosopher->data->printing_mutex);
	usleep(philosopher->data->time_to_sleep * 1000);
}

void	do_eating(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->printing_mutex);
	printf ("%ld %d is eating \n", get_passed_time_in_milli(
			philosopher->data->launching_time), philosopher->identity);
	pthread_mutex_unlock(&philosopher->data->printing_mutex);
	philosopher->last_time_eaten = get_actual_time_in_milliseconds();
	usleep(philosopher->data->time_to_eat * 1000);
	philosopher->nbr_meals++;
	if (philosopher->nbr_meals == philosopher->data->nbr_times_a_philo_must_eat)
		philosopher->data->philos_reached_min_eat++;
}

void	do_thinking(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->data->printing_mutex);
	printf("%ld %d is thinking \n", get_passed_time_in_milli(
			philosopher->data->launching_time), philosopher->identity);
	pthread_mutex_unlock(&philosopher->data->printing_mutex);
}

int	wait_untill_taking_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork->mutex);
	pthread_mutex_lock(&philosopher->data->printing_mutex);
	printf("%ld %d is taking a fork left\n", get_passed_time_in_milli(
			philosopher->data->launching_time), philosopher->identity);
	pthread_mutex_unlock(&philosopher->data->printing_mutex);
	pthread_mutex_lock(philosopher->right_fork->mutex);
	pthread_mutex_lock(&philosopher->data->printing_mutex);
	printf("%ld %d is taking a fork right\n", get_passed_time_in_milli(
			philosopher->data->launching_time), philosopher->identity);
	pthread_mutex_unlock(&philosopher->data->printing_mutex);
	return (1);
}
