/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:47:54 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 12:17:01 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "playlist_creator.h"

/* 
You are building a personalized playlist generator for a music app. The program should:
1. Analyze the user’s mood.
2. Build initial filter settings based on default filters.
3. Refine filters according to mood variations.
4. Assemble a final playlist using mood and filter settings:
• Depending on filter characteristics, fetch a popular or niche song.
• Combine the chosen song into a mood playlist
*/

struct Playlist *create_playlist(void)
{
    struct SongData *song;
    struct MoodSettings     *mood = analyze_user_mood();
    struct FilterSettings   *filter = default_filters();

    int variations = get_mood_variations(mood);
    struct FilterSettings   *refined = refine_filters(filter);
    int popular = filters_require_popular_song(refined);
    if (popular != 0)
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
}