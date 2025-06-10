/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 10:58:16 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/10 11:32:21 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

float   average(const int *arr, int size)
{
    int     i;
    int     div;
    float   av;

    i = 0;
    av = 0;
    div = 0;
    while (i < size)
    {
        if ((arr[i] >= 0) && (arr[i] <= 100))
        {
            av += arr[i];
            div++;
        }
        i++;
    }
    if (div != 0)
        av /= div;
    else
        return (0);
    return (av);
}

/* #include <stdio.h>

int main()
{
    float t;
    int     size = 7;
    int     arr[7] = {5, 100, 37, 89, 200, 300, 8};

    t = average(arr, size);
    printf("%f\n", t);
    return (0);
} */
