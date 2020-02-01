/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:41:31 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 13:38:20 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_lst *list)
{
	if (list && list->next)
	{
		while (list->next)
		{
			if (list->a > (list->next)->a)
				return (0);
			list = list->next;
		}
	}
	return (1);
}
