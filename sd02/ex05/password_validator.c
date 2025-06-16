/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 08:51:11 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 13:49:51 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "password_validator.h"

/* 
At least 8 characters long
• At least one uppercase letter
• At least one lowercase letter
• At least one digit
• At least one special character (@#$%ˆ&*)
• Must differ from current password
The validation function returns one of two states:
• ‘0 = VALID‘
• ‘1 = INVALID‘ (fails any of the rules above)
*/

static int    check_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while(s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

static int  check_strchr(const char *s, int c)
{
    char    p;
    int     i = 0;

    p = (unsigned char)c;
    while (s[i])
    {
        if (s[i] == p)
            return (1);
        i++;
    }
    return (0);
}

static int    check_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

static int    check_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

static int    check_digits(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
    int i = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int special = 0;


    if (!new_pw || !curr_pw)
        return (INVALID);
    if (check_strcmp(new_pw, curr_pw) == 0)
        return (INVALID);
    while(new_pw[i])
    {
        upper += check_uppercase(new_pw[i]);
        lower += check_lowercase(new_pw[i]);
        digit += check_digits(new_pw[i]);
        special += check_strchr("@#$%^&*" ,new_pw[i]);
        i++;
    }
    if (i < 8)
        return (INVALID);
    if ((upper > 0) && (lower > 0) && (digit > 0) && (special > 0))
        return (VALID);
    return (INVALID);
}

/* #include <stdio.h>

int main()
{
    char *old = "c1Ao!!_sn Pe!*";
    char *new = "c1Ao!!_sn Pe!.*";

    int check = validate_password(new, old);
    printf ("%d\n", check);
    return (0);
} */