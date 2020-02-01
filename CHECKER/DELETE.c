/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DELETE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:30:10 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 21:04:53 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_atoi(const char *str)
{
	int i;
	int neg;
	int nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' && str[i])
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
}

void	push_li_front(t_lst **list, long int s)
{
	t_lst *new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->a = s;
	new->next = (*list);
	(*list) = new;
}

long int		ft_atol(char *str)
{
	int			i;
	long int	neg;
	long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-' && str[i])
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (neg * nb);
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

void	push_ch_front(t_lst **list, char *s)
{
	t_lst *new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->a = ft_atol(s);
	new->next = (*list);
	(*list) = new;
}

t_lst *create_lista(int ac, char **av)
{
	t_lst *lista;
	t_lst *listb;
	listb = NULL;
	int i;

	lista = (t_lst *)malloc(sizeof(t_lst));
	lista->a = ft_atol(av[1]);
	lista->next = NULL;
	if (contains_space(av[1]) == 1)
	{
		int i = 0;
			while (av[1][i] != 0 && av[1][i] != ' ')
				i++;

		while (av[1][i] != 0)
		{
			push_li_front(&lista, ft_atoi(&av[1][i]));
			i++;
			while (av[1][i] != 0 && av[1][i] != ' ')
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

void	print_each_nb(int ac, char **av)
{
	(void)ac;
	int i = 0;
	if (contains_space(av[1]) == 1)
	{
		while (av[1][i] != 0)
		{
			printf("%d\n", ft_atoi(&(av[1][i])));
			i++;
			while (av[1][i] != 0  && av[1][i] != ' ')
				i++;
		}

	}

}


int main(int ac, char **av)
{
	t_lst *lista;
	t_lst *listb;

	listb = NULL;
	lista = NULL;
	lista = create_lista(ac, av);
	ps(&lista, &listb);
//	print_each_nb(ac, av);
}
