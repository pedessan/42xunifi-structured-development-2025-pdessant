/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:52:36 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/20 12:10:54 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"


void free_book_list(t_book **head)
{
    t_book *tmp;

    while (*head)
    {
        tmp = (*head)->next;
        free((*head)->title);
        free((*head)->author);
        free(*head);
        *head = tmp;
    }
}



void init_catalog(t_book *c)
{
    c->id = 0;
    c->title = NULL;
    c->author = NULL;
    c->next = NULL;
}

t_book	*book_lstlast(t_book *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	book_lstadd_back(t_book **lst, t_book *new)
{
	t_book	*tmp;

	if (lst)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			tmp = book_lstlast(*lst);
			tmp->next = new;
		}
	}
}

t_book	*lst_new_book(int id, char *title, char *author)
{
	t_book	*book;

	book = (t_book *)malloc(sizeof(t_book));
	if (!book)
		return (NULL);
    book->id = id;
    book->title = ft_strdup(title);
    book->author = ft_strdup(author);
	book->next = NULL;
	return (book);
}