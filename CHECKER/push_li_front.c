/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_li_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:20:33 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 18:22:02 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_li_front(t_lst **list, long int s)
{
	t_lst *new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->a = s;
	new->next = (*list);
	(*list) = new;
}
