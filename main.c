/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braimbau <braimbau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 09:39:31 by braimbau          #+#    #+#             */
/*   Updated: 2019/11/02 17:41:18 by braimbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int i;
	int fd[argc - 1];
	int v[argc - 1];
	char *str;
	int a;
	
	a = 0;
	i = 0;
	while (i < argc - 1)
	{
    	v[i] = 1;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
    	fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (v[i])
			{
				v[i] = get_next_line(fd[i], &str);
				printf("fd : %d : l : %d : %s\n",fd[i], a, str);
				free(str);
			}
			i++;
		}
		a++;
	}
}
