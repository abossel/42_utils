/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:01:39 by abossel           #+#    #+#             */
/*   Updated: 2022/11/16 12:39:26 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define FT_MALLOC 1
#define FT_FREE 2
#define FT_FREE_ALL 3

typedef struct s_malloc_list
{
	void					*ptr;
	struct s_malloc_list	*next;
}	t_malloc_list;

static void	ft_malloc_list_free(t_malloc_list **list, void *ptr)
{
	t_malloc_list	*prev;
	t_malloc_list	*curr;

	prev = NULL;
	curr = *list;
	while (curr != NULL)
	{
		if (curr->ptr == ptr)
		{
			if (prev != NULL)
				prev->next = curr->next;
			else
				*list = curr->next;
			free(curr->ptr);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static void	*ft_malloc_list(size_t size, void *ptr, int cmd)
{
	static t_malloc_list	*list;
	t_malloc_list			*node;

	if (cmd == FT_MALLOC)
	{
		node = (t_malloc_list *)malloc(sizeof(t_malloc_list));
		if (node == NULL)
			return (NULL);
		node->ptr = malloc(size);
		if (node->ptr == NULL)
		{
			free(node);
			return (NULL);
		}
		node->next = list;
		list = node;
		return (node->ptr);
	}
	else if (cmd == FT_FREE)
		ft_malloc_list_free(&list, ptr);
	else if (cmd == FT_FREE_ALL)
		while (list != NULL)
			ft_malloc_list_free(&list, list->ptr);
	return (NULL);
}

void	*ft_malloc(size_t size)
{
	return (ft_malloc_list(size, NULL, FT_MALLOC));
}

void	ft_free(void *ptr)
{
	ft_malloc_list(0, ptr, FT_FREE);
}

void	ft_free_all(void)
{
	ft_malloc_list(0, NULL, FT_FREE_ALL);
}
