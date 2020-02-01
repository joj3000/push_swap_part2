/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:47:19 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 18:34:03 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		stuff(char **line, t_lst **lista, t_lst **listb)
{
	if (ft_strcmp(*line, "sa") == 0)
		sa_swap_a(*lista);
	else if (ft_strcmp(*line, "sb") == 0)
		sb_swap_b(*listb);
	else if (ft_strcmp(*line, "ss") == 0)
		ss_sa_sb(*lista, *listb);
	else if (ft_strcmp(*line, "pa") == 0)
		pa_push_a(lista, listb);
	else if (ft_strcmp(*line, "pb") == 0)
		pb_push_b(listb, lista);
	else if (ft_strcmp(*line, "ra") == 0)
		ra_rotate_a(lista);
	else if (ft_strcmp(*line, "rb") == 0)
		rb_rotate_b(listb);
	else if (ft_strcmp(*line, "rr") == 0)
		rr_ra_rb(lista, listb);
	else if (ft_strcmp(*line, "rra") == 0)
		rra_revrotate_a(lista);
	else if (ft_strcmp(*line, "rrb") == 0)
		rrb_revrotate_b(listb);
	else if (ft_strcmp(*line, "rrr") == 0)
		rrr_rra_rrb(lista, listb);
	else
		return (0);
	return (1);
}

void	middle_shit(t_lst **lista, t_lst **listb, char **line)
{
	(void)line;
	write(1, "Error\n", 6);
	lst_delboth(lista, listb);
}

int 	contains_space(char *s)
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

t_lst *create_lista(int ac, char **av)
{
	t_lst *lista;
	int i;
		
	lista = (t_lst *)malloc(sizeof(t_lst));
	lista->a = ft_atol(av[1]);
	lista->next = NULL;
	if (contains_space(av[1]) == 1)
	{
		i = 0;
		while (av[1][i])
		{
			push_li_front(&lista, ft_atol(&av[1][i]));
			while (av[1][i] && av[1][i] != ' ')
				i++;
		}
	}
	else
	{
		i = 2;
		while (i < ac)
			push_ch_front(&lista, av[i++]);
	}
	return (lista);
}

void	end_shit(t_lst **lista, t_lst **listb)
{
	if (is_a_sorted(*lista) && lst_size(*listb) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		main(int ac, char **av)
{
	t_lst	*lista;
	t_lst	*listb;
//	int		i;
	char	*line;

	if (error_check(ac, av) == 0)
		return (0);
//	i = 2;
	listb = NULL;
	lista = create_lista(ac, av);
//	lista = (t_lst *)malloc(sizeof(t_lst));
//	lista->a = ft_atol(av[1]);
//	lista->next = NULL;
//	while (i < ac)
//		push_ch_front(&lista, av[i++]);
	printf("%d\n", lista->a);
	while (get_next_line(0, &line) > 0)
	{
		if (stuff(&line, &lista, &listb) == 0)
		{
			middle_shit(&lista, &listb, &line);
			return (0);
		}
		free(line);
	}
	end_shit(&lista, &listb);
	lst_delboth(&lista, &listb);
}
