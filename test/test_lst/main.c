#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}   t_list	;

typedef struct s_test
{
	int     n;
	char    c;
}   t_test	;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = (*lst);
	(*lst) = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (struct s_list *) malloc (sizeof(struct s_list));
	if (!node)
        return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void    init(t_test **test)
{
    (*test)->c = 'F';
    (*test)->n = 9999;
}
int main ()
{
    t_test test;
    t_test *test1;
    t_list *lst;
    t_test t;
    int a;
    int b;
    int c;


    a = 4;
    b = 55;
    c = 14;
    // test.n = 10;
    // test .c = 'a';
    // ft_lstadd_front(&lst, ft_lstnew((void *)&test));
    // // memcpy (&t, lst->content, sizeof(t));
    // t =*((t_test *) lst->content);
    // printf ("lst : n = %d ; c = %c\n", (*((t_test *) lst->content)).n, (*((t_test *) lst->content)).c);
    // ft_lstadd_front(&lst, ft_lstnew((void *)&a));
    // ft_lstadd_front(&lst, ft_lstnew((void *)&b));
    // ft_lstadd_front(&lst, ft_lstnew((void *)&c));
    // printf("%d\n", *(int *)lst->content);
    // printf("%d\n", *(int *)lst->next->content);
    // printf("%d\n", *(int *)lst->next->next->content);
    init(&test1);
    printf ("%c  %d\n", test1->c, test1->n);
}