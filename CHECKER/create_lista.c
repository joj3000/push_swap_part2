/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lista.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:04:32 by jerbs             #+#    #+#             */
/*   Updated: 2020/02/13 04:16:26 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		contains_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static t_lst	*arg_list_creation(t_lst **lista, char **av)
{
	int i;

	i = 0;
	while (av[1][i] != 0 && av[1][i] != ' ')
		i++;
	while (av[1][i] != 0)
	{
		push_li_front(lista, ft_atol(&av[1][i]));
		i++;
		while (av[1][i] != 0 && av[1][i] != ' ')
			i++;
	}
	return (*lista);
}

t_lst			*create_lista(int ac, char **av)
{
	t_lst	*lista;
	t_lst	*listb;
	int		i;

	listb = NULL;
	lista = (t_lst *)malloc(sizeof(t_lst));
	lista->a = ft_atol(av[1]);
	lista->next = NULL;
	if (contains_space(av[1]) == 1)
		lista = arg_list_creation(&lista, av);
	else
	{
		i = 2;
		while (i < ac)
			push_ch_front(&lista, av[i++]);
	}
	return (lista);
}
