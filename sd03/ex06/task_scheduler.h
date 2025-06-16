/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_scheduler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:14:43 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 16:16:10 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASK_SCHEDULER_H
# define TASK_SCHEDULER_H

// Analyze task load and I/O behavior. Returns a new TaskProfile or NULL on failure.
struct TaskProfile *profile_tasks(struct TaskList *tasks);
// Compute a priority map from task profiling. Returns a new PriorityMap or NULL on failure.
struct PriorityMap *compute_priorities_mock(struct TaskProfile *profile);
// Return the number of available CPU cores.
int get_available_core_count(void);
// Select the best task to assign next based on the profile. Returns a task ID or -1 on failure.
int select_best_task(struct TaskProfile *profile);
// Create a ScheduleResult structure for the specified number of cores. Returns NULL on failure.
struct ScheduleResult *create_schedule_result(int core_count);
// Update the result schedule with a task assignment.
void update_schedule_entry(struct ScheduleResult *result, int core_id, int task_id);
// Free functions for cleanup
void free_task_profile(struct TaskProfile *profile);
void free_priority_map(struct PriorityMap *priorities);
void free_loadinfo(struct LoadInfo *load);

struct ScheduleResult *schedule_tasks(struct TaskList *tasks);

#endif