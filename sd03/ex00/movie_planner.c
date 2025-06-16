/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:43:46 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 16:06:55 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
    struct Preferences  *fav = get_user_preferences();
    if (!fav)
        return (NULL);

    struct MovieList    *movies = find_movies(fav);
    if (!movies)
    {
        free(fav);
        return (NULL);
    }

    struct Plan         *plan = build_plan(movies);
    if (!plan)
    {
        free(fav);
        free(movies);
        return (NULL);
    }

    return (plan);
}