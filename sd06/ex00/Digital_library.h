/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Digital_library.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:14:34 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/18 15:21:12 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGITAL_LIBRARY_H
# define DIGITAL_LIBRARY_H

typedef enum
{
    BY_TITLE,
    BY_AUTHOR
}   Search_by;

typedef struct z_book
{
    int fd;
    int id;
    char *title;
    char *Author;
}   t_book;

#endif