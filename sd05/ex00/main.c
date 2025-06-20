/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:08:41 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/20 11:55:31 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int check_commas(char *s)
{
    int counter = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] == ',')
            counter++;
        i++;
    }
    if (counter == 3)
        return (VALID);
    return (INVALID);
}


char **check_line(char *s)
{
    if (check_commas(s) == INVALID)
    {
        printf("Invalid line: %s\n", s);
        return (NULL);
    }
    char **args = ft_split(s, ',');
    if (!args)
    {
        printf("Error during memory allocation\n");
        return (NULL);
    }
    return args;
}


void save_lines_in_buff(int fd, t_book *catalog)
{
    char    *line;
    char    **args = NULL;
    int     status;
    int     counter = 0;

    line = get_next_line(fd);
    while (line && counter < MAX_CONSULT)
    {
        args = check_line(line);
        if (args)
        {                       //ft_atoi to be reviewed for better check on characters
            book_lstadd_back(&catalog, lst_new_book(ft_atoi(args[1]), args[2], args[3]));
        }
        free(line);
        free_alloc(args);
        counter++;
        line = get_next_line(fd);
    }
}




void    check_file(char *s, int *status, t_book *catalog)
{
    int     fd;

    fd = open(s, O_RDONLY);
    if (fd < 0)
    {
        *status = EXIT;
        return ;
    }
    save_infos_in_struct(status, catalog);
    close (fd);
    *status = VALID;
}


void    print_istructions(int *status)
{
    ft_printf("lauch> ./tracker file.txt");
    *status = EXIT;
}

void put_prompt_line(int *status)
{
    char *line;

    ft_printf("To search by title: digit 0\nTo search by Author: digit 1\nTo exit: digit exit\n> ");
    line = get_next_line(0);

    if (!line)
    {
        *status = EXIT;
        return;
    }

    if (!ft_strncmp(line, "exit", 4))
        *status = EXIT;
    else if (!ft_strncmp(line, "0", 1))
        ft_printf ("%s\n", line);
        //*status = BY_TITLE;
    else if (!ft_strncmp(line, "1", 1))
        ft_printf ("%s\n", line);
        //*status = BY_AUTHOR;
    else
        *status = INVALID;

    free(line);
}

void    print_error(void)
{
    printf("Input 1 accepts only 0, 1, or exit");
}

int main(int ac, char **av)
{
    int     status;
    int     input_1;
    char    *input_2;
    t_book  catalog;

    init_catalog(&catalog);
    if (ac == 2)
        check_file(av[1], &status, &catalog);
    else
        print_istructions(&status);

    while (status != EXIT)
    {
        put_prompt_line(&status);
 /*        if (status == VALID)
            get_input();
        if (status == VALID)
            search(); */
        if (status == INVALID)
            print_error();
        if (status == EXIT)
            free_all();
    }
    return (0);
}



/* void    save_infos_in_struct(char *lines, int *status, t_book *catalog)
{
    int counter = 0;
    char    *line;

    while (counter < MAX_CONSULT)
    {
        
        if (check_line(lines[counter]) == VALID)
        {
            book_lstadd_back(&catalog, lst_new_book());
        }
    }
} */

/* void save_lines_in_buff(char **buffer, int fd)
{
    char *line;
    int counter = 0;

    line = get_next_line(fd);
    while (line)
    {
        char *tmp;

        if (!*buffer)
            tmp = ft_strdup(line);
        else
            tmp = ft_strjoin(*buffer, line);
        free(*buffer);
        if (!tmp)
        {
            ft_printf("Error\nWrong memory allocation\n");
            free(line);
            close(fd);
            exit(1);
        }
        *buffer = tmp;
        free(line);
        line = get_next_line(fd);
    }
} */


/* void    check_file(char *s, int *status, t_book *catalog)
{
    int     fd;
    char    *buffer;

    buffer = NULL;
    fd = open(s, O_RDONLY);
    if (fd < 0)
        return (*status == EXIT, NULL);
    save_lines_in_buff(&buffer, fd);
    close (fd);
    if (!buffer)
        return (*status == EXIT, NULL);
    save_infos_in_struct(buffer, status, catalog);

} */



/* //main per testare save_lines_in_buff()
int main(int ac, char **av)
{
    int     fd;
    char    *buffer;

    buffer = NULL;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (fd < 0)
            return (1);
        save_lines_in_buff(&buffer, fd);
        close (fd);
        if (!buffer)
            return (1);
        printf ("%s", buffer);
    }
    return (0);
} */