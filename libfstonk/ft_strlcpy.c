/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igenial <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:01:32 by igenial           #+#    #+#             */
/*   Updated: 2023/05/23 11:10:33 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(char *dst, const char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0') {
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}