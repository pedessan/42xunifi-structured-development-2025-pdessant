/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rockyd <rockyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 00:51:02 by rockyd            #+#    #+#             */
/*   Updated: 2025/06/19 00:56:56 by rockyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

// Prototipi (supponendo che tu abbia get_next_line e ft_printf implementati)
//char *get_next_line(int fd);
//int ft_printf(const char *format, ...);

// Funzioni libft di supporto

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;
    while (i < n && s1[i] && s2[i])
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }
    if (i == n)
        return 0;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

char *ft_strtolower(const char *str)
{
    size_t i = 0;
    char *lower = malloc(ft_strlen(str) + 1);
    if (!lower)
        return NULL;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            lower[i] = str[i] + 32;
        else
            lower[i] = str[i];
        i++;
    }
    lower[i] = '\0';
    return lower;
}

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char *ft_strtrim(const char *s, const char *set)
{
    size_t start = 0;
    size_t end = ft_strlen(s);
    size_t i;

    while (s[start] && ft_isspace(s[start]))
        start++;
    if (start == end)
        return malloc(1); // stringa vuota
    while (end > start && ft_isspace(s[end - 1]))
        end--;
    char *trimmed = malloc(end - start + 1);
    if (!trimmed)
        return NULL;
    for (i = 0; start < end; start++, i++)
        trimmed[i] = s[start];
    trimmed[i] = '\0';
    return trimmed;
}

// Funzione case-insensitive strstr
char *ft_strcasestr(const char *haystack, const char *needle)
{
    if (!*needle)
        return (char *)haystack;
    char *hay_lower = ft_strtolower(haystack);
    char *need_lower = ft_strtolower(needle);
    if (!hay_lower || !need_lower)
    {
        free(hay_lower);
        free(need_lower);
        return NULL;
    }

    char *p = hay_lower;
    size_t needle_len = ft_strlen(need_lower);
    while (*p)
    {
        size_t i;
        for (i = 0; i < needle_len; i++)
            if (p[i] != need_lower[i])
                break;
        if (i == needle_len)
        {
            size_t pos = p - hay_lower;
            free(hay_lower);
            free(need_lower);
            return (char *)(haystack + pos);
        }
        p++;
    }
    free(hay_lower);
    free(need_lower);
    return NULL;
}

// Dati finti: piccolo catalogo libri statico
typedef struct s_book {
    int id;
    char *title;
    char *author;
} t_book;

t_book catalog[] = {
    {1, "The C Programming Language", "Brian Kernighan"},
    {2, "Clean Code", "Robert C. Martin"},
    {3, "Introduction to Algorithms", "Thomas H. Cormen"},
    {4, "Design Patterns", "Erich Gamma"},
    {5, "The Pragmatic Programmer", "Andrew Hunt"},
};

#define CATALOG_SIZE (sizeof(catalog) / sizeof(catalog[0]))

int main(void)
{
    char *input = NULL;
    while (1)
    {
        ft_printf("Inserisci substring da cercare (\"exit\" per uscire): ");
        input = get_next_line(0);
        if (!input)
        {
            ft_printf("\nErrore o EOF, esco.\n");
            break;
        }

        char *trimmed = ft_strtrim(input, " \t\n");
        free(input);

        if (!trimmed || ft_strlen(trimmed) == 0)
        {
            free(trimmed);
            ft_printf("Input vuoto, riprova.\n");
            continue;
        }

        if (ft_strncmp(trimmed, "exit", 4) == 0 && ft_strlen(trimmed) == 4)
        {
            free(trimmed);
            ft_printf("Uscita dal programma.\n");
            break;
        }

        ft_printf("Risultati per \"%s\":\n", trimmed);
        int found = 0;
        for (size_t i = 0; i < CATALOG_SIZE; i++)
        {
            if (ft_strcasestr(catalog[i].title, trimmed) || ft_strcasestr(catalog[i].author, trimmed))
            {
                ft_printf("ID: %d | Titolo: %s | Autore: %s\n", catalog[i].id, catalog[i].title, catalog[i].author);
                found = 1;
            }
        }
        if (!found)
            ft_printf("Nessun libro trovato.\n");

        free(trimmed);
    }
    return 0;
}
