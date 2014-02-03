/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <hvillain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:36:08 by hvillain          #+#    #+#             */
/*   Updated: 2013/12/01 22:32:50 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if ((char) c == 0)
	{
		while (*s != (char) c)
			s++;
		return ((char *) s);
	}
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return (&((char *) s)[i]);
		i--;
	}
	return (0);
}
