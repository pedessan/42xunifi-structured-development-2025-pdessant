/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recipe_generator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:16:37 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/12 11:42:33 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECIPE_GENERATOR_H
# define RECIPE_GENERATOR_H

#include <stdlib.h>

// Fetch current ingredients from fridge. Returns a new Ingredients* or NULL on failure.
struct Ingredients *get_current_ingredients(void);
// Fetch user taste profile. Returns a new TasteProfile* or NULL on failure.
struct TasteProfile *get_user_taste_profile(void);
// Generate a new recipe candidate based on ingredients & taste. Returns a new Recipe* or NULL on failure.
struct Recipe *create_recipe(struct Ingredients *ingredients, struct TasteProfile *taste);
// Ask user approval for the given recipe. Returns 1 if approved, 0 otherwise.
int get_user_approval(struct Recipe *recipe);
// Free functions for cleanup:
void free_ingredients(struct Ingredients *ing);
void free_taste_profile(struct TasteProfile *tp);
void free_recipe(struct Recipe *recipe);

struct Recipe *create_custom_recipe(void);

#endif