/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workout_scheduler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:14:35 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/18 14:54:34 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workout_scheduler.h"

/* 
You’re building a workout scheduler for a fitness tracking app. 
 - The system fetches a user’s data,
 - builds a preliminary workout plan,
 - refines it with the user’s preferences, and then
 - finalizes a complete schedule for a certain number of days.
 - Each day includes personalized exercises and motivational tips.
*/

struct WorkoutPlan *create_workout_schedule(char *username)
{
	int	i = 0;
	struct UserData	*data = get_user_data(username);
	if (!data)
		return (NULL);

	struct WorkoutPlan	*plan = build_base_plan(data);
	if (!plan)
		return (free_user_data(data), NULL);

	struct WorkoutPlan	*refined = refine_plan(plan, data);
	if (!refined)
		return (free_user_data(data), free_workout_plan(plan), NULL);

	if (refined != plan)
		free_workout_plan(plan);
	
	int	duration = determine_duration(refined);
	if (duration <= 0)
		return (free_user_data(data), free_workout_plan(refined), NULL);

	while (i < duration)
	{
		assign_daily_exercises(refined, i + 1);
		assign_daily_tips(refined, i + 1);
		i++;
	}
	free_user_data(data);
	return (refined);
}