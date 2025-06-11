/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:41:39 by pdessant          #+#    #+#             */
/*   Updated: 2025/06/11 13:48:20 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

int compute_total_size(FSNode *node)
{
	FSNode *p;
	int size = 0;

	if (!node)
		return (0);
	p = node;
	while (p)
	{
		if (p->type == FILE_NODE)
			size += p->size;
		else if (p->type == FOLDER_NODE)
			size += compute_total_size(p->child);
		p = p->sibling;
	}
	return (size);
}

void print_structure(const FSNode *node, int indent)
{
	int i;
	int	size = 0;

	while (node)
	{
		i = 0;
		while (i < indent - 1)
		{
			printf("    ");
			i++;
		}
		if (indent > 0)
			printf("└── ");
		if (node->type == FILE_NODE)
			size = node->size;
		else if (node->type == FOLDER_NODE)
			size = compute_total_size((FSNode *)node);
		printf("%s (%d)\n", node->name, size);
		if (node->type == FOLDER_NODE)
			print_structure(node->child, indent + 1);
		node = node->sibling;
	}
}

void free_filesystem(FSNode *node)
{
	if (!node)
		return ;
	free_filesystem(node->child);
	free_filesystem(node->sibling);
	free(node->name);
	free(node);
}

/* // --- Main di test ---

int main(void) {
    // Creo la root e file/cartelle
    FSNode *root = create_folder("root");
    FSNode *file1 = create_file("file1.txt", 100);
    FSNode *folderA = create_folder("folderA");
    FSNode *file2 = create_file("file2.txt", 200);
    FSNode *file3 = create_file("file3.txt", 300);

    // Costruisco la struttura
    add_child(root, file1);
    add_child(root, folderA);
    add_child(folderA, file2);
    add_child(folderA, file3);

    // Stampa struttura
    printf("Struttura del filesystem:\n");
    print_structure(root, 0);

    // Calcolo dimensione totale della root
    int total_size = compute_total_size(root);
    printf("\nDimensione totale di 'root': %d byte\n", total_size);

    // Libero la memoria
    free_filesystem(root);

    return 0;
} */