/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Isabela Genial <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:33:10 by Isabela Gen       #+#    #+#             */
/*   Updated: 2023/05/26 15:07:49 by igenial          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_putchar_fd(char c, int fd)
{
	int	counter;

	counter = 0;
	write(fd, &c, 1);
	counter++;
	return (counter);
}
