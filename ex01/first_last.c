/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:38:20 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/10 11:59:01 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"


int first_occ(int arr[], int size, int target)
{
    int i = 0;

    while (i < size)
    {
        if (arr[i] == target)
            return (i);
        i++;
    }
    return (-1);
}

int last_occ(int arr[], int size, int target)
{
    int last;

    last = size - 1;
    while (last >= 0)
    {
        if (arr[last] == target)
            return (last);
        last--;
    }
    return (-1);
}

void first_last(int arr[], int size, int target, int *first, int *last)
{
    *first = first_occ(arr, size, target);
    *last = last_occ(arr, size, target);
}

/* #include <stdio.h>

int main()
{
    int size = 7;
    int arr[7] = {1, 6, 2, 9, 5, 6, 22};
    int target = 6;
    int first;
    int last;

    first_last(arr, size, target, &first, &last);
    printf("first = %d\nlast = %d\n", first, last);
    return (0);
} */