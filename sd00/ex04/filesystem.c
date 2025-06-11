/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 22:28:57 by rockyd            #+#    #+#             */
/*   Updated: 2025/06/11 13:49:37 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
	FSNode	*file;

	file = malloc(sizeof(FSNode));
	if(!file)
		return (NULL);
	file->name = strdup(name);
	file->size = size;
	file->type = FILE_NODE;
	file->child = NULL;
	file->sibling = NULL;
	return (file);
}

FSNode *create_folder(const char *name)
{
	FSNode	*folder;

	folder = malloc(sizeof(FSNode));
	if(!folder)
		return (NULL);
	folder->name = strdup(name);
	folder->size = 0;
	folder->type = FOLDER_NODE;
	folder->child = NULL;
	folder->sibling = NULL;
	return (folder);
}

void add_child(FSNode *parent, FSNode *child)
{
	FSNode *cpy;

	cpy = NULL;
	if (parent->child == NULL)
		parent->child = child;
	else
	{
		cpy = parent->child;
		while (cpy->sibling)
			cpy = cpy->sibling;
		cpy->sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	return(parent->child);
}

FSNode *get_sibling(const FSNode *node)
{
	return (node->sibling);
}

/* 
#include <stdio.h>

int main(void)
{
    FSNode *root = create_folder("root");
    FSNode *file1 = create_file("file1.txt", 100);
    FSNode *folderA = create_folder("folderA");
    FSNode *file2 = create_file("file2.txt", 200);
    FSNode *file3 = create_file("file3.txt", 300);

    add_child(root, file1);
    add_child(root, folderA);
    add_child(folderA, file2);
    add_child(folderA, file3);

    // Stampa i figli di root
    FSNode *child = get_children(root);
    while (child)
    {
        printf("root has: %s (%s)\n", child->name, child->type == FILE_NODE ? "file" : "folder");
        child = get_sibling(child);
    }

    return 0;
} */


/* 
Sarà rappresentato così:

root_folder->children punta a file1.txt
file1.txt->next punta a subfolder
subfolder->children punta a file2.txt
file2.txt->next punta a file3.txt
subfolder->next punta a file4.txt
file4.txt->next è NULL
*/


/* 
Implement a basic file system manager that simulates the hierarchical structure of folders
and files.
Each folder can contain:
• Files (each with a name and size).
• Files (each with a name and size).
• Other folders (size set to zero).
• Other folders (size set to zero).
the functions must be formatted as follows:
FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);
*/