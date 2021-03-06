/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 23:23:48 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/09 23:04:00 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	int		i;

	i = 0;
	if (c == '\0')
		return (((char *)s) + ft_strlen(s));
	while (s[i] != 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
