/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:01:05 by elel-yak          #+#    #+#             */
/*   Updated: 2022/06/25 13:54:19 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dlen;
	int	i;

	dlen = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dlen] = src[i];
		dlen++;
		i++;
	}
	dest[dlen] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		new_len;
	int		i;
	char	*new_str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	new_len = ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		new_len += ft_strlen(strs[i]);
		i++;
	}
	new_len++;
	new_str = (char *)malloc(sizeof(char) * new_len);
	new_str[0] = '\0';
	ft_strcpy(new_str, strs[0]);
	i = 1;
	while (i < size)
	{
		ft_strcat(new_str, sep);
		ft_strcat(new_str, strs[i]);
		i++;
	}
	return (new_str);
}
