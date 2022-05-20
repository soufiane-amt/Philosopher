/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:29:35 by samajat           #+#    #+#             */
/*   Updated: 2022/05/20 23:38:17 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int counter;

typedef struct mutex
{
    pthread_mutex_t *lock;
} t_mutex;
void* doSomeThing(void *mu)
{
    pthread_mutex_t lock;
    unsigned long i = 0;

    pthread_mutex_lock(((pthread_mutex_t *)mu));
    counter += 1;
    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    pthread_mutex_unlock(((pthread_mutex_t *)mu));

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    pthread_mutex_t test;
    pthread_mutex_t test2;
    pthread_mutex_t test1;
    pthread_t tid[2];

    if (pthread_mutex_init(&test1, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&test2, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
    if (pthread_mutex_init(&test, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return 1;
    }
    err = pthread_create(&(tid[0]), NULL, &doSomeThing, &test);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    err = pthread_create(&(tid[1]), NULL, &doSomeThing, &test);
    if (err != 0)
        printf("\ncan't create thread :[%s]", strerror(err));
    // err = pthread_create(&(tid[2]), NULL, &doSomeThing, &test2);
    // if (err != 0)
    //     printf("\ncan't create thread :[%s]", strerror(err));
    i++;
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    // pthread_join(tid[2], NULL);
    // pthread_mutex_destroy(&test1);
    // pthread_mutex_destroy(&test2);
    pthread_mutex_destroy(&test);

    return 0;
}