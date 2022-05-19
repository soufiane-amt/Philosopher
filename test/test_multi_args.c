/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multi_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:16:02 by samajat           #+#    #+#             */
/*   Updated: 2022/05/19 22:51:28 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}

void muti_argc(int nbr, ...)
{
    va_list args;
    va_list p_args;
    int         i;
    void        *s;

    va_start(args, nbr);
    va_start(p_args, nbr);
    i = 0;
    while (i < nbr)
    {
        s = va_arg(args, void *);
        printf("-->%p\n", s);
        i++;
    }
    printf("-->%p\n", va_arg(p_args, char *));
    printf("-->%p\n", va_arg(p_args, char *));
    s = malloc (454);
    ((char *)s)[0] = 'd';
    printf ("$%p\n", s);
    free(s);
    printf ("$%s\n", s);
}
int main ()
{
    
    muti_argc (4,  NULL,  ft_strdup("h"), ft_strdup("h"), ft_strdup("h"));
}