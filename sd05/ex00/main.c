/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:08:41 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/20 13:11:49 by pdessant         ###   ########.fr       */
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
    if (counter == 2)
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


void  save_infos_in_struct(int fd, t_book **catalog)
{
    char    *line;
    char    **args = NULL;
   // int     status;
    int     counter = 0;

    line = get_next_line(fd);
    while (line && counter < MAX_CONSULT)
    {
        args = check_line(line);
        if (args)
        {                       //ft_atoi to be reviewed for better check on characters
            book_lstadd_back(catalog, lst_new_book(ft_atoi(args[0]), args[1], args[2]));
            free_alloc(args);
        }
        free(line);
        counter++;
        line = get_next_line(fd);
    }
}




void    check_file(char *s, int *status, t_book **catalog)
{
    int     fd;

    fd = open(s, O_RDONLY);
    if (fd < 0)
    {
        *status = EXIT;
        return ;
    }
    save_infos_in_struct(fd, catalog);
    close (fd);
    *status = VALID;
}


void    print_istructions(int *status)
{
    ft_printf("launch> ./tracker file.txt\n");
    *status = EXIT;
}


void put_prompt_line(int *status)
{
    char *line;

    ft_printf("To search by title:  digit 0\n");
    ft_printf("To search by Author: digit 1\n");
    ft_printf("To exit:             digit exit\n");
    ft_printf("> ");

    line = get_next_line(STDIN_FILENO);
    if (!line)
    {
        *status = EXIT;
        return;
    }

    if (strcmp(line, "exit\n") == 0)
        *status = EXIT;
    else if (strcmp(line, "0\n") == 0)
    {
        ft_printf ("%s\n", line);
        *status = VALID; // o meglio BY_TITLE
    }
    else if (strcmp(line, "1\n") == 0)
    {
        ft_printf ("%s\n", line);
        *status = VALID; // o meglio BY_AUTHOR
    }
    else
        *status = INVALID;

    free(line);
}


/* void put_prompt_line(int *status)
{
    char *line;

    printf("To search by title:  digit 0\n");
    printf("To search by Author: digit 1\n");
    printf("To exit:             digit exit\n");
    printf("> ");
    line = get_next_line(STDIN_FILENO);

    if (!line)
    {
        *status = EXIT;
        return;
    }

    if (ft_strncmp(line, "exit\n", 5) == 0)
        *status = EXIT;
    else if (ft_strncmp(line, "0\n", 2) == 0)
    {
        *status = VALID;
        ft_printf ("%s\n", line);
        *status = BY_TITLE;
    }
    else if (ft_strncmp(line, "1\n", 2) == 0)
    {
        *status = VALID;
        ft_printf ("%s\n", line);
        *status = BY_AUTHOR;
    }
    else
    {
        //ft_printf(YELLOW "\nError: Invalid Input digit\n\n" RESET);
        *status = INVALID;
    }

    free(line);
} */

void    print_error(void)
{
    ft_printf(YELLOW "Input 1 accepts only 0, 1, or exit\n" RESET);
}

int main(int ac, char **av)
{
    int     status = 0;
    //int     input_1;
    //char    *input_2;
    t_book  *catalog = NULL;

    //init_catalog(&catalog);
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
            free_book_list(&catalog);
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