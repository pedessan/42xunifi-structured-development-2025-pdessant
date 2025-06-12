/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movie_planner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:43:50 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 16:24:38 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVIE_PLANNER_H
# define MOVIE_PLANNER_H

# include <stdlib.h>

struct Preferences;
struct MovieList;
struct Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);

// Returns a list of movies matching the given preferences.
//      Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);

// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

struct Plan *create_movie_night_plan(void);

#endif