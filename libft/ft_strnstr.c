/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:26:16 by algultse          #+#    #+#             */
/*   Updated: 2024/01/21 22:01:25 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big && !len)
		return (0);
	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		while ((*(big + i) == *(little + i)) && *(little + i) && len > i)
		{
			if (!*(little + i + 1))
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
