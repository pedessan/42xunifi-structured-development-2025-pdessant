/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:28:53 by rockyd            #+#    #+#             */
/*   Updated: 2025/06/11 12:07:25 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESYSTEM_H
# define FILESYSTEM_H

/* includes */

# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/* STRUCTS */

typedef enum {
    FILE_NODE,
    FOLDER_NODE
} NodeType;


typedef struct z_struct
{
	char *name;
	int	size;
	NodeType type;
	struct z_struct *child;
	struct z_struct *sibling;
	//struct z_struct *next;
}	FSNode;


FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
int compute_total_size(FSNode *node);
void print_structure(const FSNode *node, int indent);
void free_filesystem(FSNode *node);

#endif