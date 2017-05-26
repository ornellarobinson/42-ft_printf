/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:55:46 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 15:36:24 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_is_in(char elem, char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		if (src[i] == elem)
			return (1);
		i++;
	}
	return (0);
}
