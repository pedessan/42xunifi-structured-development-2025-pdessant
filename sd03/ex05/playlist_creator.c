/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playlist_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:47:54 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/16 15:56:54 by pdessant         ###   ########.fr       */
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
    int i = 0;
    struct SongData *song;
    struct MoodSettings     *mood = analyze_user_mood();
    struct FilterSettings   *filter = default_filters();

    if (!filter)
        return (free_mood_settings(mood), NULL);

    int variations = get_mood_variations(mood);
    while (i < variations)
    {
        struct FilterSettings   *refined = refine_filters(filter);
        if (!refined)
            return (free_mood_settings(mood), free_filter_settings(filter), NULL);

        free_filter_settings(filter);  // libera il precedente
        filter = refined;              // aggiorna il puntatore a quello nuovo
        i++;
    }
    int popular = filters_require_popular_song(filter);
    free_filter_settings(filter);
    if (popular != 0)
        song = fetch_popular_song();
    else
        song = fetch_niche_song();
    struct Playlist *playlist = combine_with_mood_playlist(song, mood);
    free_mood_settings(mood);
    free_song_data(song);
    if (!playlist)
        return (NULL);
    return (playlist);
}