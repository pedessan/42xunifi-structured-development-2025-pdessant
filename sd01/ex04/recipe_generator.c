/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:16:33 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 11:45:11 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "recipe_generator.h"

/* 
You are building an interactive recipe generator that creates recipes based on the user’s
current ingredients and taste profile, repeating the generation process until the user ap-
proves the result. The program should:
1. Fetch the current fridge ingredients.
2. Fetch the user’s taste profile.
3. Iteratively generate a recipe candidate:
• Produce a new recipe.
• Ask for user approval.
• Repeat until approved.
4. Return the final approved recipe.
*/

struct Recipe *create_custom_recipe(void)
{
    int approval = 0;
    struct Recipe   *recipe = NULL;

    struct Ingredients *ingredients = get_current_ingredients();
    if (!ingredients)
        return (NULL);

    struct TasteProfile *taste = get_user_taste_profile();
    if (!taste)
    {
        free_ingredients(ingredients);
        return (NULL);
    }

    while (1)
    {
        recipe = create_recipe(ingredients, taste);
        if (!recipe)
        {
            free_ingredients (ingredients);
            free_taste_profile (taste);
            return (NULL);
        }

        approval = get_user_approval(recipe);

        if (approval == 1)
        {
            free_ingredients (ingredients);
            free_taste_profile (taste);
            return (recipe);
        }

        if (approval != 0)
        {
            free_ingredients (ingredients);
            free_taste_profile (taste);
            free_recipe (recipe);
            return (NULL);
        }
        free_recipe (recipe);
    }
}
