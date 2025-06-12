/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:16:47 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 17:18:26 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "task_scheduler.h"

/* 
You are building a simulated task scheduler for a multicore CPU system. The program
should:
1. Profile the provided task list to evaluate load and I/O patterns.
2. Compute scheduling priorities for each task.
3. Assign tasks to CPU cores using the computed priorities.
Your task is to design a well-layered control flow that delegates these responsibilities us-
ing the following prototypes:
*/

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    int i = 0;
    struct TaskProfile  *profiled = profile_tasks(tasks);
    struct PriorityMap  *new_priority = compute_priorities_mock(profiled);
    int cpu = get_available_core_count();
    i = 0;
    while (i < cpu)
    {
        struct ScheduleResult   *res = create_schedule_result(cpu);
        int best_task = select_best_task(profiled);
        update_schedule_entry(res, i, best_task);
        i++;
    }
    return (res);
}