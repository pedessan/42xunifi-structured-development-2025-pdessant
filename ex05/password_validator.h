/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:51:07 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 08:58:35 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

/* STRUCT */

typedef enum
{
    VALID = 0,
    INVALID = 1
} PwStatus;


PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif