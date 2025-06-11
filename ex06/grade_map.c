/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:01:59 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 11:33:04 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_map.h"


const char  *plusminus_mapper(int score)
{
    if (score < 0 || score > 100)
        return "Invalid";
    else if (score >= 97)
        return ("A+");
    else if (score >= 93)
        return ("A");
    else if (score >= 90)
        return ("A-");
    else if (score >= 87)
        return ("B+");
    else if (score >= 83)
        return ("B");
    else if (score >= 80)
        return ("B-");
    else if (score >= 77)
        return ("C+");
    else if (score >= 73)
        return ("C");
    else if (score >= 70)
        return ("C-");
    else if (score >= 67)
        return ("D+");
    else if (score >= 63)
        return ("D");
    else if (score >= 60)
        return ("D-");
    else
        return ("F");
}

const char  *passfail_mapper(int score)
{
    if (score < 0 || score > 100)
        return "Invalid";
    else if (score >= 60)
        return ("P");
    else
        return ("F");

}

const char  *standard_mapper(int score)
{
    if (score < 0 || score > 100)
        return "Invalid";
    else if (score >= 90)
        return ("A");
    else if (score >= 80)
        return ("B");
    else if (score >= 70)
        return ("C");
    else if (score >= 60)
        return ("D");
    else
        return ("F");
}

void    map_scores(const int *scores, int size, GradeMapper mapper, \
    const char **mapped_grades)
{
    int i = 0;

    while (i < size)
    {
        mapped_grades[i] = mapper(scores[i]);
        i++;
    }
}

/* #include <stdio.h>
int main()
{
    int scores[] = {90, 60, 81, 26, 200, -1};
    int size = sizeof(scores) / sizeof(scores[0]);
    int i = 0;

    const char *mapped_grades[size];  // Array di stringhe

    // Prova con standard_mapper
    map_scores(scores, size, standard_mapper, mapped_grades);

    // Stampa risultati
    while (i < size)
    {
        printf("Score: %d → Grade: %s\n", scores[i], mapped_grades[i]);
        i++;
    }
    return (0);
} */