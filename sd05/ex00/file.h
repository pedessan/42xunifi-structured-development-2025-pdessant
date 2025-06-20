/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:06:09 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/20 12:11:50 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
 
#include "libft/libft.h"

#define MAX_CONSULT 1000


typedef enum
{
    VALID,
    INVALID,
    EXIT
}   status;

typedef enum
{
    BY_TITLE,
    BY_AUTHOR
}   Search_by;

typedef struct z_book
{
    int id;
    char *title;
    char *author;
    struct z_book *next;
}   t_book;


/* PROTOTYPES */

void    init_catalog(t_book *c);
void	book_lstadd_back(t_book **lst, t_book *new);
t_book	*lst_new_book(int id, char *title, char *author);
void    free_book_list(t_book **head);

#endif