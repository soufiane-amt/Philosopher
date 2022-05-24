/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:35 by samajat           #+#    #+#             */
/*   Updated: 2022/05/24 22:29:43 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main (int   argc, char  **argv)
{
    t_data          data;
    t_list   **philsophers;
    
	if (!user_input_is_valid(argv, argc))
		return (0);
    philsophers = malloc (sizeof(t_philosopher *));
    if (!philsophers)
        return (0);
    *philsophers = NULL;
    (void)argc;
    initialize_user_input(&data, argv);
    pthread_mutex_lock(&data.hhhhh);
    set_to_philosophers_to_default(philsophers, &data);
    let_the_fun_bigins(philsophers);
    pthread_mutex_lock(&data.hhhhh);
	return (1);
/*     while (!data.some_one_is_dead)
        usleep(100); */
}