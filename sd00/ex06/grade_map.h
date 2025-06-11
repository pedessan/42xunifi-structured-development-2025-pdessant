/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:01:56 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 10:53:31 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAP_H
# define GRADE_MAP_H

typedef const char* (*GradeMapper)(int);

void    map_scores(const int *scores, int size, GradeMapper mapper, \
    const char **mapped_grades);

#endif