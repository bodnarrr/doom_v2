/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:02:54 by abodnar           #+#    #+#             */
/*   Updated: 2019/05/06 22:02:56 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_chr(char *source, char symbol)
{
	int		i;
	char	*res;

	i = 0;
	while (source[i] && source[i] != symbol)
		i++;
	res = (char*)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(res, source, i);
	return (res);
}
