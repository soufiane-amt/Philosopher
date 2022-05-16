/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:35 by samajat           #+#    #+#             */
/*   Updated: 2022/05/16 01:42:45 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main (int   argc, char  **argv)
{
    t_data          data;
    t_list   *philsophers;

    (void)argc;
    initialize_user_input(&data, argv);
    build_philosophers(&philsophers, data);
    
    printf("-->%d\n", ((t_philosopher *)philsophers->content)->identity);
}