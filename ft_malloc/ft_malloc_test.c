/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:36:41 by abossel           #+#    #+#             */
/*   Updated: 2022/11/17 09:05:02 by abossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * use ft_malloc to allocate num blocks of 1 to bytes size, zero them then
 * free every delta block
 */
void	multi_malloc(int num, int bytes, int delta)
{
	char	*ptr;
	size_t	size;

	if (num == 0)
		return ;
	size = rand() % bytes + 1;
	ptr = (char *)ft_malloc(size);
	if (ptr != NULL)
		bzero(ptr, size);
	else
		printf("error: ft_malloc failed\n");
	multi_malloc(num - 1, bytes, delta);
	if (ptr != NULL & num % delta == 0)
		ft_free(ptr);
}

int	main(void)
{
	multi_malloc(1000, 1000, 10);
	ft_free_all();
}
