/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/25 17:27:29 by hvillain          #+#    #+#             */
/*   Updated: 2014/07/25 17:28:48 by hvillain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char			*ft_str0chr(char *line)
{
	while (*line && *line <= '9' && *line >= '0')
		line++;
	return (line);
}

static char			*ft_strsub(char *s, int start, int len)
{
	char		*s1;
	int			i;

	i = -1;
	if (!s)
		return (0);
	if (!(s1 = (char *)malloc(len + 1)))
		return (0);
	while (++i < len)
		s1[i] = ((char *)s)[start++];
	s1[i] = 0;
	return (s1);
}

void			ft_strsplit_ints(char *line)
{
	char		*next;

	while (*line)
	{
		if (*line <= '9' && *line >= '0')
		{
			next = ft_str0chr(line);
			manage_list("add", ft_strsub(line, 0, (next - line)), NULL);
			line = next;
		}
		else if (*line != ' ' && *line != '\0')
		{
			manage_list("add", ft_strsub(line, 0, 1), NULL);
			line++;
		}
		else
			line++;
	}
}
