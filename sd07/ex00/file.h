/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:06:09 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/20 12:45:46 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H
 
#include "libft/libft.h"

#define MAX_CONSULT 1000

#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"


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