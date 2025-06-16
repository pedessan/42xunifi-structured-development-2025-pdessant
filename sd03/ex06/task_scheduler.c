/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:16:47 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/16 15:58:44 by pdessant         ###   ########.fr       */
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
    struct TaskProfile *profiled = profile_tasks(tasks);
    if (!profiled)
        return (NULL);

    struct PriorityMap *priorities = compute_priorities_mock(profiled);
    if (!priorities)
        return (free_task_profile(profiled), NULL);

    int core_count = get_available_core_count();
    struct ScheduleResult *result = create_schedule_result(core_count);
    if (!result)
        return (free_task_profile(profiled), free_priority_map(priorities), NULL);

    while (i < core_count)
    {
        int task_id = select_best_task(profiled);
        if (task_id == -1)
        {
            free_task_profile(profiled);
            free_priority_map(priorities);
            free_loadinfo();
            // Potresti voler anche liberare `result` se parzialmente popolato
            return (NULL);
        }
        update_schedule_entry(result, i, task_id);
        i++;
    }

    free_task_profile(profiled);
    free_priority_map(priorities);
    return (result);
}


/* struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    int i = 0;
    struct TaskProfile  *profiled = profile_tasks(tasks);
    if (!profiled)
        return (NULL);

    struct PriorityMap  *new_priority = compute_priorities_mock(profiled);
    if (!new_priority)
    {
        free_task_profile(new_priority);
        return (NULL);
    }

    int cpu = get_available_core_count();
    i = 0;
    struct ScheduleResult   *res = create_schedule_result(cpu);
    if (!res)
    {
        free_task_profile(profiled);
        free_priority_map(new_priority);
        return (NULL);
    }
    while (i < cpu)
    {
        int task_id = select_best_task(profiled);
        if (task_id == -1)
        {
            free_task_profile(profiled);
            free_priority_map(new_priority);
            free_loadinfo();  // opzionale, se usata altrove
            // Potresti voler anche liberare `result` se parzialmente popolato
            return (NULL);
        }
        update_schedule_entry(res, i, task_id);
        i++;
    }
    return (res);
} */





/* 
struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    struct TaskProfile *profiled = profile_tasks(tasks);
    if (!profiled)
        return NULL;

    struct PriorityMap *priorities = compute_priorities_mock(profiled);
    if (!priorities)
    {
        free_task_profile(profiled);
        return NULL;
    }

    int core_count = get_available_core_count();
    struct ScheduleResult *result = create_schedule_result(core_count);
    if (!result)
    {
        free_task_profile(profiled);
        free_priority_map(priorities);
        return NULL;
    }

    for (int i = 0; i < core_count; i++)
    {
        int task_id = select_best_task(profiled);
        if (task_id == -1)
            break;
        update_schedule_entry(result, i, task_id);
    }

    free_task_profile(profiled);
    free_priority_map(priorities);
    return result;
}
 */