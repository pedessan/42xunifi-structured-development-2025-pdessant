/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:05:09 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/10 12:33:24 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

static int arr_len(const int *arr, int size)
{
    int i = 0;

    while ((i < size) && (arr[i] != -1))
        i++;
    return (i);
}

int count_segments(const int *arr, int size)
{
    int i = 0;
    int flag = 1;
    int counter = 0;

    while (i < size)
    {
        if (flag == 1)
        {
            if (arr_len(&arr[i], size - i) >= 3)
                counter++;
            flag = 0;
        }
        if (arr[i] == -1)
            flag = 1;
        i++;
    }
    return (counter);
}

/* #include <stdio.h>

int main()
{
    //int arr[11] = {2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4};
    //int size = 11;
    int arr[17] = {1, 2, 3, -1, 5, 7, 8, -1, 1, 2, 3, -1, 4, 5, 6, -1, -1};
    int size = 17;
    int segs;

    segs = count_segments(arr, size);
    printf ("segs: %d\n", segs);
    return (0);
} */