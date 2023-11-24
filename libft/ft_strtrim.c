/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:26:32 by mapfenni          #+#    #+#             */
/*   Updated: 2023/04/10 20:45:02 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischarset(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dest;

	if (!s1 && !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1 && ft_ischarset(s1[end], (char *)set))
		end--;
	while (s1 && ft_ischarset(s1[start], (char *)set))
		start++;
	if (start > end)
		dest = malloc(1 * sizeof(char));
	else
		dest = malloc((end - start) * sizeof(char));
	if (!dest)
		return (NULL);
	while (end >= start)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}
