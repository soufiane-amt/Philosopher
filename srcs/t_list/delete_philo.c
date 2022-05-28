/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:48:12 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:22:56 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	delete_philo(void	*philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *) philosopher;
	free_forks(philo->right_fork);
	free(philo);
}
