/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_organizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:45:56 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/16 15:52:20 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "music_organizer.h"


/* 
Your goal
is to automate the process of 
    -scanning music files,
    -categorizing them,
    -updating a central music database.
*/

struct MusicLibrary *organize_music_library(const char *directory_path)
{
    int i = 0;
    struct MusicLibrary *music_lib = create_music_library();
    if (!music_lib)
        return (NULL);

    const char  **filenames = scan_directory(directory_path);
    if (!filenames)
        return (free (music_lib), NULL);

    while (filenames[i])
    {
        struct MusicFile *m_file = process_music_file(directory_path, filenames[i]);
        if (!m_file)
            return (free (music_lib), free (filenames), NULL);

        update_music_library(music_lib, m_file);
        free (m_file);
        i++;
    }

    return (free (filenames), music_lib);
}