/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:21:12 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 13:49:04 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_windows.h"

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
        if ((arr[i] >= 0) && (arr[i] <= 150))
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

int critical_windows_analyses(const int *readings, int size)
{
    int i = 0;
    int counter = 0;

    while (i < size)
    {
        if ((readings[i] >= 70) && readings[i] <= 150)
            counter++;
        i++;
    }
    if ((counter >= 3) && (average(readings, size) >= 90))
        return (1);
    return (0);
}

int count_critical_windows(const int *readings, int size)
{
    int i = 0;
    int ret = 0;

    while (i < (size - 5))
    {
        ret += critical_windows_analyses(&readings[i], 5);
        i++;
    }
    return (ret);
}

/* #include <stdio.h>
int main()
{
    int c[15] = {104, 165, 100, 102, 90, 72, 65, 123, 45, 82, 91, 132, 123, 167, 91};
    //int c[15] = {104, 165, 100, 102};
    int size = 15;
    int count;

    count = count_critical_windows(c, size);
    printf("%d\n", count);
    return (0);
} */

/* int count_critical_windows(const int *readings, int size)
{
    int flag = 1;
    int count_pos = 1;
    int i = 0;
    int ret = 0;

    while (i < size)
    {
        if ((count_pos == 1) && (flag == 1))
        {
            ret += critical_windows_analyses(&readings[i], 5);
            flag = 0;
        }
        else if ((count_pos == 5) && (flag == 0))
        {
            count_pos = 0;
            flag = 1;
        }
        count_pos++;
        i++;
    }
    return (ret);
} */
