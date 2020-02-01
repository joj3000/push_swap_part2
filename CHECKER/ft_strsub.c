/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerbs <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:30:39 by jerbs             #+#    #+#             */
/*   Updated: 2020/01/31 13:37:52 by jerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**size_t	ft_strlen(const char *str)
**{
**	size_t i = 0;
**	while(str[i])
**		i++;
**	return (i);
**}
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len)
	{
		cpy[i] = s[start + i];
		len--;
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

/*
**#include <stdio.h>
**int main()
**{
**	const char str[] = "this is a test";
**
**	printf("%s", ft_substr(str, 1, 15));
**}
*/
