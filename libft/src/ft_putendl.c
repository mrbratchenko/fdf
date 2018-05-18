/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:55:31 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/11 16:55:32 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
